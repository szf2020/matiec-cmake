/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Code generation regression tests.
 */

#include <gtest/gtest.h>

#include "test_utils.hh"
#include "matiec/matiec.h"

#include <algorithm>
#include <filesystem>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace fs = std::filesystem;
using namespace matiec::test;

namespace {

std::string normalizeLineEndings(std::string content) {
    content.erase(
        std::remove(content.begin(), content.end(), '\r'),
        content.end());
    return content;
}

std::vector<std::string> parseWhitelist(std::string_view raw) {
    std::vector<std::string> entries;
    std::istringstream stream{std::string(raw)};
    std::string line;

    while (std::getline(stream, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        if (!line.empty() && line.rfind("\xEF\xBB\xBF", 0) == 0) {
            line.erase(0, 3);
        }

        const auto first = line.find_first_not_of(" 	");
        if (first == std::string::npos) {
            continue;
        }
        const auto last = line.find_last_not_of(" 	");
        line = line.substr(first, last - first + 1);

        if (line.empty() || line[0] == '#') {
            continue;
        }

        entries.push_back(line);
    }

    return entries;
}

} // namespace

class CodegenRegressionTest : public ::testing::Test {
protected:
    void SetUp() override {
        matiec_options_init(&opts_);
        lib_dir_ = getLibDir().string();
        opts_.include_dir = lib_dir_.c_str();
        output_dir_ = temp_.path().string();
        opts_.output_dir = output_dir_.c_str();
        fixture_path_ = getFixturesDir() / "simple_program.st";
    }

    void TearDown() override {
        matiec_result_free(&result_);
    }

    void CompileFixture(matiec_output_format_t format) {
        ASSERT_TRUE(fs::exists(fixture_path_)) << "Missing fixture: " << fixture_path_.string();
        opts_.output_format = format;
        auto status = matiec_compile_file(fixture_path_.string().c_str(), &opts_, &result_);
        ASSERT_EQ(status, MATIEC_OK)
            << "Compilation failed: "
            << (result_.error_message ? result_.error_message : "none");
    }

    std::string ReadRequiredFile(const fs::path& path) {
        auto content = readFile(path);
        EXPECT_TRUE(content.has_value()) << "Failed to read: " << path.string();
        return content.value_or(std::string());
    }

    std::vector<std::string> LoadGoldenWhitelist() {
        const fs::path whitelist_path = getFixturesDir() / "codegen" / "golden_whitelist.txt";
        return parseWhitelist(ReadRequiredFile(whitelist_path));
    }

    std::vector<std::string> CollectGeneratedFilenames() {
        std::vector<std::string> names;

        if (result_.output_files != nullptr && result_.output_file_count > 0) {
            for (int i = 0; i < result_.output_file_count; ++i) {
                if (result_.output_files[i] == nullptr) {
                    continue;
                }
                names.push_back(fs::path(result_.output_files[i]).filename().string());
            }
        }

        if (names.empty()) {
            for (const auto& entry : fs::directory_iterator(temp_.path())) {
                if (!entry.is_regular_file()) {
                    continue;
                }
                names.push_back(entry.path().filename().string());
            }
        }

        std::sort(names.begin(), names.end());
        names.erase(std::unique(names.begin(), names.end()), names.end());
        return names;
    }

    void AssertGeneratedFilesWhitelisted(const std::vector<std::string>& whitelist) {
        std::unordered_set<std::string> allowed(whitelist.begin(), whitelist.end());
        ASSERT_FALSE(allowed.empty()) << "Golden whitelist must not be empty";

        const auto generated_files = CollectGeneratedFilenames();
        ASSERT_FALSE(generated_files.empty()) << "No generated files found in output directory";

        for (const auto& filename : generated_files) {
            EXPECT_TRUE(allowed.find(filename) != allowed.end())
                << "Generated file is not in golden whitelist: " << filename;
        }
    }

    TempDir temp_;
    matiec_options_t opts_{};
    matiec_result_t result_{};
    std::string lib_dir_;
    std::string output_dir_;
    fs::path fixture_path_;
};

TEST_F(CodegenRegressionTest, GeneratesStableCOutput) {
    CompileFixture(MATIEC_OUTPUT_C);

    const auto whitelist = LoadGoldenWhitelist();
    AssertGeneratedFilesWhitelisted(whitelist);

    const fs::path expected_dir = getFixturesDir() / "codegen";
    const std::string expected_pous_c = ReadRequiredFile(expected_dir / "POUS.c");
    const std::string expected_pous_h = ReadRequiredFile(expected_dir / "POUS.h");

    const std::string actual_pous_c = ReadRequiredFile(temp_.path() / "POUS.c");
    const std::string actual_pous_h = ReadRequiredFile(temp_.path() / "POUS.h");

    EXPECT_EQ(normalizeLineEndings(actual_pous_c), normalizeLineEndings(expected_pous_c));
    EXPECT_EQ(normalizeLineEndings(actual_pous_h), normalizeLineEndings(expected_pous_h));
}

TEST_F(CodegenRegressionTest, GeneratesStableIecOutput) {
    CompileFixture(MATIEC_OUTPUT_IEC);

    const auto whitelist = LoadGoldenWhitelist();
    AssertGeneratedFilesWhitelisted(whitelist);

    const fs::path expected_dir = getFixturesDir() / "codegen";
    const std::string expected_iec = ReadRequiredFile(expected_dir / "simple_program.iec");

    const std::string actual_iec = ReadRequiredFile(temp_.path() / "simple_program.iec");

    EXPECT_EQ(normalizeLineEndings(actual_iec), normalizeLineEndings(expected_iec));
}
