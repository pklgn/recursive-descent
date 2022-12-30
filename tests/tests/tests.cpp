#include <fstream>

#include "catch.hpp"
#include "parser/Parser.h"

TEST_CASE("Run positive tests")
{
	size_t testsCount = 3;
	std::ifstream file;

	for (size_t index = 0; index < testsCount; ++index)
	{
		std::string testFilename = "..\\SUCCESS\\SUCCESS_" + std::to_string(index) + ".TXT";
		file.open(testFilename);
		if (file.is_open())
		{
			parser::Parser parser(file);
			bool success = parser.Parse();
			CHECK(success);
			if (!success)
			{
				WARN("Test fail: SUCCESS_" + std::to_string(index) + ".TXT");
			}
			file.close();
		}
		else
		{
			WARN("Failed to open test file: " + testFilename);
		}
	}
}

TEST_CASE("Run negative tests")
{
	size_t testsCount = 13;
	std::ifstream file;

	for (size_t index = 0; index < testsCount; ++index)
	{
		std::string testFilename = "..\\FAILURE\\FAILURE_" + std::to_string(index) + ".TXT";
		file.open(testFilename);
		if (file.is_open())
		{
			parser::Parser parser(file);
			bool success = parser.Parse();
			CHECK_FALSE(success);
			if (success)
			{
				WARN("Test fail: FAILURE_" + std::to_string(index) + ".TXT");
			}
			file.close();
		}
		else
		{
			WARN("Failed to open test file: " + testFilename);
		}
	}
}
