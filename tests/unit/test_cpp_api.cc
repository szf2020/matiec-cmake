/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for the modern C++ API wrapper.
 */

#include <gtest/gtest.h>

#include "test_utils.hh"
#include "matiec/matiec.hpp"

namespace fs = std::filesystem;
using namespace matiec::test;

TEST(CppApiTest, CompileStringSucceedsWithDefaultCOutput) {
    TempDir temp;

    matiec::CompilerOptions options;
    options.includeDir = getLibDir();
    options.outputDir = temp.path();

    matiec::Compiler compiler(options);
    matiec::CompilerResult result =
        compiler.compileString(samples::MINIMAL_PROGRAM, "inline_program.st");

    EXPECT_TRUE(result.ok()) << result.diagnostic.message;
    EXPECT_EQ(result.diagnostic.code, MATIEC_OK);
    EXPECT_TRUE(result.diagnostic.message.empty());
}

TEST(CppApiTest, CompileFileReportsMissingInput) {
    matiec::CompilerOptions options;
    options.includeDir = getLibDir();

    matiec::Compiler compiler(options);
    matiec::CompilerResult result =
        compiler.compileFile(getProjectRoot() / "tests" / "fixtures" / "does_not_exist.st");

    EXPECT_FALSE(result.ok());
    EXPECT_EQ(result.diagnostic.code, MATIEC_ERROR_FILE_NOT_FOUND);
}
