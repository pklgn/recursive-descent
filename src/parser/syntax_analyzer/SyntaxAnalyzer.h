#pragma once

#include <iostream>

#include "../lexer/Lexer.h"
#include "../context/ParserContext.h"

namespace parser::syntax_analyzer
{

class SyntaxAnalyzer
{
public:
	using InputStreamR = std::istream&;
	using ParserContext = context::ParserContext;

	static bool Prog(InputStreamR input, ParserContext& ctx);
	static bool Var(InputStreamR input, ParserContext& ctx);
	static bool ListSt(InputStreamR input, ParserContext& ctx);
	static bool IdList(InputStreamR input, ParserContext& ctx);
	static bool St(InputStreamR input, ParserContext& ctx);
	static bool Type(InputStreamR input, ParserContext& ctx);
	static bool Read(InputStreamR input, ParserContext& ctx);
	static bool Write(InputStreamR input, ParserContext& ctx);
	static bool Assign(InputStreamR input, ParserContext& ctx);
	static bool Exp(InputStreamR input, ParserContext& ctx);
	static bool T(InputStreamR input, ParserContext& ctx);
	static bool F(InputStreamR input, ParserContext& ctx);

private:
	template <typename Tok>
	static bool ParseToken(InputStreamR input, ParserContext& ctx)
	{
		using namespace lexer;

		Lexer::SkipWs(input, ctx);

		return Lexer::MatchToken<Tok>(input, ctx);
	}

	static bool ListStRight(InputStreamR input, ParserContext& ctx);
	static bool IdListRight(InputStreamR input, ParserContext& ctx);
	static bool ExpRight(InputStreamR input, ParserContext& ctx);
	static bool TRight(InputStreamR input, ParserContext& ctx);
};

} // namespace parser::syntax_analyzer
