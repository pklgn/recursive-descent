#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#include "token/definitions/definitions.h"
#include "token/values/values.h"
#include "parser_context/ParserContext.hpp"

struct Lexer
{
	template <typename Tok>
	static bool MatchToken(std::istream& stream, ParserContext& ctx)
	{
		const std::string expectedValue = token::Value<Tok>();
		std::string actualValue;
		ctx.lastExpectedToken = expectedValue;

		size_t index = 0;
		for (; stream && index < expectedValue.size(); ++index)
		{
			char ch;
			stream.get(ch);
			actualValue.push_back(ch);
		}

		ctx.lastParsedToken = actualValue;
		StrToLower(actualValue);

		bool equal = expectedValue == actualValue;

		if (!equal)
			stream.seekg(-static_cast<int>(index), std::ios_base::cur);
		else
			ctx.col += index;

		return equal;
	}

	/*
	Special overload for 'None' token which always must be matched
	In this case we avoid execution of unnecessary code of method above
	*/
	template <>
	static bool MatchToken<token::None>(std::istream& stream, ParserContext& ctx)
	{
		return true;
	}

	static void SkipWs(std::istream& stream, ParserContext& ctx)
	{
		char ch;
		while (std::isspace(ch = stream.peek()))
		{
			if (ch == '\n')
			{
				++ctx.line;
				ctx.col = 1;
			}

			stream.get();
			++ctx.col;
		}
	}

private:
	static void StrToLower(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(),
			[](unsigned char ch) { return std::tolower(ch); });
	}
};
