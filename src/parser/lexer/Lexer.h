#pragma once

#include <iostream>
#include <string>

#include "../context/ParserContext.h"
#include "../token/definitions/definitions.h"
#include "../token/values/values.h"

namespace parser::lexer
{

class Lexer
{
public:
	using InputStreamR = std::istream&;
	using ParserContext = parser::context::ParserContext;

	template <typename Tok>
	static bool MatchToken(InputStreamR stream, ParserContext& ctx)
	{
		const std::string expectedValue = token::Value<Tok>();
		std::string actualValue{};
		ctx.lastExpectedToken = expectedValue;

		size_t readCount = 0;
		for (; stream.good() && readCount < expectedValue.size(); ++readCount)
		{
			char ch{};
			stream.get(ch);
			actualValue.push_back(ch);
		}

		ctx.lastParsedToken = actualValue;
		StrToLower(actualValue);

		bool equal = expectedValue == actualValue;

		if (!stream.good())
		{
			stream.clear();
			++readCount;
		}

		if (!equal)
			stream.seekg(-static_cast<int>(readCount), std::ios_base::cur);
		else
			ctx.col += readCount;

		return equal;
	}

	/*
	Special overload for 'None' token which always must be matched
	In this case we avoid execution of unnecessary code of method above
	*/
	template <>
	static bool MatchToken<token::None>(InputStreamR stream, ParserContext& ctx)
	{
		return true;
	}

	static void SkipWs(InputStreamR stream, ParserContext& ctx);

private:
	static void StrToLower(std::string& str);
};

} // namespace parser::lexer
