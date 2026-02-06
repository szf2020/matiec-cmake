/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  End-to-end tests for v1 CLI long-option aliases.
 */

#include <gtest/gtest.h>

#include "test_utils.hh"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace matiec::test;

#ifndef MATIEC_TEST_IEC2C_PATH
#define MATIEC_TEST_IEC2C_PATH ""
#endif

namespace {

std::string quoteArg(const std::string& value) {
    std::string out = "\"";
    for (char ch : value) {
        if (ch == '"') {
            out += "\\\"";
        } else {
            out.push_back(ch);
        }
    }
    out += '"';
    return out;
}

std::string normalizeLineEndings(std::string text) {
    text.erase(std::remove(text.begin(), text.end(), '\r'), text.end());
    return text;
}

struct CommandResult {
    int code = -1;
    std::string output;
};

CommandResult runCommand(const fs::path& executable, const std::vector<std::string>& args) {
#ifdef _WIN32
    std::string cmd = executable.string();
#else
    std::string cmd = quoteArg(executable.string());
#endif
    for (const auto& arg : args) {
        cmd += " ";
        cmd += quoteArg(arg);
    }
    cmd += " 2>&1";

    CommandResult result;

#ifdef _WIN32
    FILE* pipe = _popen(cmd.c_str(), "r");
#else
    FILE* pipe = popen(cmd.c_str(), "r");
#endif
    if (pipe == nullptr) {
        result.output = "failed to spawn process";
        return result;
    }

    std::array<char, 512> buffer{};
    while (std::fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) != nullptr) {
        result.output.append(buffer.data());
    }

#ifdef _WIN32
    result.code = _pclose(pipe);
#else
    result.code = pclose(pipe);
#endif
    result.output = normalizeLineEndings(result.output);
    return result;
}

} // namespace

TEST(CliV1Test, HelpLongOptionMatchesShortOption) {
    const fs::path iec2cPath(MATIEC_TEST_IEC2C_PATH);
    ASSERT_TRUE(fs::exists(iec2cPath)) << "iec2c not found: " << iec2cPath.string();

    const auto shortHelp = runCommand(iec2cPath, {"-h"});
    const auto longHelp = runCommand(iec2cPath, {"--help"});

    EXPECT_EQ(shortHelp.code, 0);
    EXPECT_EQ(longHelp.code, 0);
    EXPECT_EQ(shortHelp.output, longHelp.output);
    EXPECT_NE(shortHelp.output.find("syntax:"), std::string::npos);
}

TEST(CliV1Test, VersionLongOptionMatchesShortOption) {
    const fs::path iec2cPath(MATIEC_TEST_IEC2C_PATH);
    ASSERT_TRUE(fs::exists(iec2cPath)) << "iec2c not found: " << iec2cPath.string();

    const auto shortVersion = runCommand(iec2cPath, {"-v"});
    const auto longVersion = runCommand(iec2cPath, {"--version"});

    EXPECT_EQ(shortVersion.code, 0);
    EXPECT_EQ(longVersion.code, 0);
    EXPECT_EQ(shortVersion.output, longVersion.output);
    EXPECT_NE(shortVersion.output.find("version"), std::string::npos);
}

TEST(CliV1Test, CompileSupportsLongIncludeAndTargetDirOptions) {
    const fs::path iec2cPath(MATIEC_TEST_IEC2C_PATH);
    ASSERT_TRUE(fs::exists(iec2cPath)) << "iec2c not found: " << iec2cPath.string();

    TempDir temp;
    const fs::path inputFile = temp.path() / "program.st";
    ASSERT_TRUE(writeFile(inputFile, samples::MINIMAL_PROGRAM));

    const fs::path outputDir = temp.path() / "out";
    fs::create_directories(outputDir);

    const auto compile = runCommand(
        iec2cPath,
        {
            "--include", getLibDir().string(),
            "--target-dir", outputDir.string(),
            inputFile.string(),
        });

    EXPECT_EQ(compile.code, 0) << compile.output;
    EXPECT_TRUE(fs::exists(outputDir / "POUS.c")) << compile.output;
    EXPECT_TRUE(fs::exists(outputDir / "POUS.h")) << compile.output;
}
