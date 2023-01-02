#pragma once

#include <string>

struct ParserContext
{
	size_t line = 0;
	size_t col = 0;
	std::string lastExpectedToken;
	std::string lastParsedToken;
};
