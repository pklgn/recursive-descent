#include "pch.h"

#include "SyntaxAnalyzer.h"

namespace parser::syntax_analyzer
{

bool SyntaxAnalyzer::Prog(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return ParseToken<token::ProgKeyword>(input, ctx) &&
		   ParseToken<token::Identifier>(input, ctx) &&
		   Var(input, ctx) &&
		   ParseToken<token::BeginKeyword>(input, ctx) &&
		   ListSt(input, ctx) &&
		   ParseToken<token::EndKeyword>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::Var(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return ParseToken<token::VarKeyword>(input, ctx) &&
		   IdList(input, ctx) &&
		   ParseToken<token::Colon>(input, ctx) &&
		   Type(input, ctx) &&
		   ParseToken<token::Semicolon>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::ListSt(InputStreamR input, ParserContext& ctx)
{
	return St(input, ctx) && ListStRight(input, ctx);
}

bool SyntaxAnalyzer::IdList(InputStreamR input, ParserContext& ctx)
{
	return ParseToken<token::Identifier>(input, ctx) && IdListRight(input, ctx);
}

bool SyntaxAnalyzer::St(InputStreamR input, ParserContext& ctx)
{
	return Read(input, ctx) || Write(input, ctx) || Assign(input, ctx);
}

bool SyntaxAnalyzer::Type(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return ParseToken<token::IntType>(input, ctx) ||
		   ParseToken<token::FloatType>(input, ctx) ||
		   ParseToken<token::BoolType>(input, ctx) ||
		   ParseToken<token::StringType>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::Read(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return ParseToken<token::ReadKeyword>(input, ctx) &&
		   ParseToken<token::LeftParenthesis>(input, ctx) &&
		   IdList(input, ctx) &&
		   ParseToken<token::RightParenthesis>(input, ctx) &&
		   ParseToken<token::Semicolon>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::Write(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return ParseToken<token::WriteKeyword>(input, ctx) &&
		   ParseToken<token::LeftParenthesis>(input, ctx) &&
		   IdList(input, ctx) &&
		   ParseToken<token::RightParenthesis>(input, ctx) &&
		   ParseToken<token::Semicolon>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::Assign(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return ParseToken<token::Identifier>(input, ctx) &&
		   ParseToken<token::AssignmentOp>(input, ctx) &&
		   Exp(input, ctx) &&
		   ParseToken<token::Semicolon>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::Exp(InputStreamR input, ParserContext& ctx)
{
	return T(input, ctx) && ExpRight(input, ctx);
}

bool SyntaxAnalyzer::T(InputStreamR input, ParserContext& ctx)
{
	return F(input, ctx) && TRight(input, ctx);
}

bool SyntaxAnalyzer::F(InputStreamR input, ParserContext& ctx)
{ // clang-format off
	return (ParseToken<token::UnaryMinusOp>(input, ctx) && F(input, ctx)) ||
		   (ParseToken<token::LeftParenthesis>(input, ctx) && Exp(input, ctx) && ParseToken<token::RightParenthesis>(input, ctx)) ||
		   ParseToken<token::Identifier>(input, ctx) ||
		   ParseToken<token::Number>(input, ctx);
} // clang-format on

bool SyntaxAnalyzer::ListStRight(InputStreamR input, ParserContext& ctx)
{
	// Parsing 'None' token always complete successfully
	// Now code is more correspond with grammar rules

	return (St(input, ctx) && ListStRight(input, ctx)) || ParseToken<token::None>(input, ctx);
}

bool SyntaxAnalyzer::IdListRight(InputStreamR input, ParserContext& ctx)
{
	return (ParseToken<token::Comma>(input, ctx) && ParseToken<token::Identifier>(input, ctx) && IdListRight(input, ctx)) || ParseToken<token::None>(input, ctx);
}

bool SyntaxAnalyzer::ExpRight(InputStreamR input, ParserContext& ctx)
{
	return (ParseToken<token::PlusOp>(input, ctx) && T(input, ctx) && ExpRight(input, ctx)) || ParseToken<token::None>(input, ctx);
}

bool SyntaxAnalyzer::TRight(InputStreamR input, ParserContext& ctx)
{
	return (ParseToken<token::MultiplyOp>(input, ctx) && F(input, ctx) && TRight(input, ctx)) || ParseToken<token::None>(input, ctx);
}

} // namespace parser::syntax_analyzer
