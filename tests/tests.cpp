#include <fstream>

#include <catch2/catch_all.hpp>

#include "parser/Parser.h"

TEST_CASE("Run positive tests")
{
	const size_t testsCount = 3;
	std::ifstream file;

	for (size_t index = 0; index < testsCount; ++index)
	{
		// TODO: use std filesystem?
		const std::string testFilename = "..\\test_cases\\success\\success_" + std::to_string(index) + ".txt";
		file.open(testFilename);
		if (!file.is_open())
		{
			WARN("Failed to open test file: " + testFilename);
			continue;
		}

		parser::Parser parser(file);
		bool success = parser.Parse();

		CHECK(success);
		if (!success)
		{
			WARN("Test fail: " + testFilename);
		}
		file.close();
	}
}

TEST_CASE("Run negative tests")
{
	const size_t testsCount = 13;
	std::ifstream file;

	for (size_t index = 0; index < testsCount; ++index)
	{
		const std::string testFilename = "..\\test_cases\\failure\\failure_" + std::to_string(index) + ".txt";
		file.open(testFilename);
		if (!file.is_open())
		{
			WARN("Failed to open test file: " + testFilename);
			continue;
		}
		
		parser::Parser parser(file);
		bool success = parser.Parse();

		CHECK_FALSE(success);
		if (success)
		{
			WARN("Test fail: " + testFilename);
		}

		file.close();
	}
}
