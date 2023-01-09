#include "pch.h"

#include "parser/Parser.h"

using namespace test;

TEST_CASE("Positive tests", "[Parser]")
{// TODO: fixtures? using test file path as argument?
	std::ifstream file;

	size_t testCaseCount = 0;
	for (const auto& testCase : StdFs::directory_iterator(TEST_CASES_SUCCESS_DIR))
	{
		++testCaseCount;

		const auto& tcPath = testCase.path();
		const auto testFileName = (tcPath.has_filename() ? tcPath.filename().generic_string() : "");
		file.open(tcPath.generic_string());
		if (!file.is_open())
		{
			WARN("Failed to open test file:\n\tNAME: " + testFileName + "\n\tPATH: " + TEST_CASES_SUCCESS_DIR);
			continue;
		}

		parser::Parser parser(file);
		bool success = parser.Parse();

		CHECK(success);
		if (!success)
		{
			WARN("Test fail on test file:\n\tNAME: " + testFileName + "\n\tPATH: " + TEST_CASES_SUCCESS_DIR);
		}
		file.close();
	}
}

TEST_CASE("Negative tests", "[Parser]")
{// TODO: remove output from std::cout on failure Parse()
	std::ifstream file;

	size_t testCaseCount = 0;
	for (const auto& testCase : StdFs::directory_iterator(TEST_CASES_FAILURE_DIR))
	{
		++testCaseCount;

		const auto& tcPath = testCase.path();
		const auto testFileName = (tcPath.has_filename() ? tcPath.filename().generic_string() : "");
		file.open(tcPath.generic_string());
		if (!file.is_open())
		{
			WARN("Failed to open test file:\n\tNAME: " + testFileName + "\n\tPATH: " + TEST_CASES_SUCCESS_DIR);
			continue;
		}

		parser::Parser parser(file);
		bool success = parser.Parse();

		CHECK_FALSE(success);
		if (success)
		{
			WARN("Test fail on test file:\n\tNAME: " + testFileName + "\n\tPATH: " + TEST_CASES_SUCCESS_DIR);
		}
		file.close();
	}
}
