#pragma once

#include <string>

namespace parser::context
{

using Token = std::string;

struct ParserContext
{
	size_t line = 0;
	size_t col = 0;
	Token lastExpectedToken;
	Token lastParsedToken;
};

} // namespace parser::context
