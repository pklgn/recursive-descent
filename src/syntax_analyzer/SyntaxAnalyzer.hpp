#pragma once

#include <iostream>

#include "lexer/Lexer.hpp"

struct SyntaxAnalyzer
{
// clang-format off
	static bool Prog(std::istream& input, ParserContext& ctx)
	{
		return 
			ParseToken<token::ProgKeyword>(input, ctx) && 
			ParseToken<token::Identifier>(input, ctx) && 
			Var(input, ctx) && 
			ParseToken<token::BeginKeyword>(input, ctx) && 
			ListSt(input, ctx) && 
			ParseToken<token::EndKeyword>(input, ctx);
	}

	static bool Var(std::istream& input, ParserContext& ctx)
	{
		return 
			ParseToken<token::VarKeyword>(input, ctx) && 
			IdList(input, ctx) && 
			ParseToken<token::Colon>(input, ctx) && 
			Type(input, ctx) && 
			ParseToken<token::Semicolon>(input, ctx);
	}

	static bool ListSt(std::istream& input, ParserContext& ctx)
	{
		return St(input, ctx) && ListStRight(input, ctx);
	}

	static bool IdList(std::istream& input, ParserContext& ctx)
	{
		return ParseToken<token::Identifier>(input, ctx) && IdListRight(input, ctx);
	}

	static bool St(std::istream& input, ParserContext& ctx)
	{
		return 
			Read(input, ctx) || 
			Write(input, ctx) || 
			Assign(input, ctx);
	}

	static bool Type(std::istream& input, ParserContext& ctx)
	{
		return 
			ParseToken<token::IntType>(input, ctx) || 
			ParseToken<token::FloatType>(input, ctx) || 
			ParseToken<token::BoolType>(input, ctx) || 
			ParseToken<token::StringType>(input, ctx);
	}

	static bool Read(std::istream& input, ParserContext& ctx)
	{
		return 
			ParseToken<token::ReadKeyword>(input, ctx) && 
			ParseToken<token::LeftParenthesis>(input, ctx) && 
			IdList(input, ctx) && 
			ParseToken<token::RightParenthesis>(input, ctx) && 
			ParseToken<token::Semicolon>(input, ctx);
	}

	static bool Write(std::istream& input, ParserContext& ctx)
	{
		return 
			ParseToken<token::WriteKeyword>(input, ctx) && 
			ParseToken<token::LeftParenthesis>(input, ctx) && 
			IdList(input, ctx) && 
			ParseToken<token::RightParenthesis>(input, ctx) && 
			ParseToken<token::Semicolon>(input, ctx);
	}

	static bool Assign(std::istream& input, ParserContext& ctx)
	{
		return 
			ParseToken<token::Identifier>(input, ctx) && 
			ParseToken<token::AssignmentOp>(input, ctx) && 
			Exp(input, ctx) && 
			ParseToken<token::Semicolon>(input, ctx);
	}

	static bool Exp(std::istream& input, ParserContext& ctx)
	{
		return T(input, ctx) && ExpRight(input, ctx);
	}

	static bool T(std::istream& input, ParserContext& ctx)
	{
		return F(input, ctx) && TRight(input, ctx);
	}

	static bool F(std::istream& input, ParserContext& ctx)
	{
		return 
			(ParseToken<token::UnaryMinusOp>(input, ctx) && F(input, ctx)) || 
			(ParseToken<token::LeftParenthesis>(input, ctx) && Exp(input, ctx) && ParseToken<token::RightParenthesis>(input, ctx)) || 
			ParseToken<token::Identifier>(input, ctx) || 
			ParseToken<token::Number>(input, ctx);

	}

private:
	template <typename Tok>
	static bool ParseToken(std::istream& input, ParserContext& ctx)
	{
		Lexer::SkipWs(input, ctx);
		return Lexer::MatchToken<Tok>(input, ctx);
	}

	static bool ListStRight(std::istream& input, ParserContext& ctx)
	{
		// Parsing 'None' token always complete successfully
		// Now code is more correspond with grammar rules
		return 
			(St(input, ctx) && ListStRight(input, ctx)) || 
			ParseToken<token::None>(input, ctx);
	}

	static bool IdListRight(std::istream& input, ParserContext& ctx)
	{
		return 
			(ParseToken<token::Comma>(input, ctx) && ParseToken<token::Identifier>(input, ctx) && IdListRight(input, ctx)) || 
			ParseToken<token::None>(input, ctx);
	}

	static bool ExpRight(std::istream& input, ParserContext& ctx)
	{
		return 
			(ParseToken<token::PlusOp>(input, ctx) && T(input, ctx) && ExpRight(input, ctx)) || 
			ParseToken<token::None>(input, ctx);
	}

	static bool TRight(std::istream& input, ParserContext& ctx)
	{
		return 
			(ParseToken<token::MultiplyOp>(input, ctx) && F(input, ctx) && TRight(input, ctx)) || 
			ParseToken<token::None>(input, ctx);
	}
	// clang-format on
};
