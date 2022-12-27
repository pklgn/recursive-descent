#pragma once

#include "parser/common_parser.h"

#include "common/string/util.hpp"

namespace parser::lexeme
{ // clang-format off

struct Token {}; // Token == Terminal ?== epsilon?

// IDENTIFICATOR Token //

struct TokenIdentificator : Token {};

struct TokenIdentificatorId : TokenIdentificator {};
struct TokenIdentificatorNum : TokenIdentificator {};

// IDENTIFICATOR Token //

///////////////////////////////////////////////////////////

// TYPE Token //

struct TokenType : Token {};

struct TokenTypeBool : TokenType {};
struct TokenTypeFloat : TokenType {};
struct TokenTypeInt : TokenType {};
struct TokenTypeString : TokenType {};

// TYPE Token //

///////////////////////////////////////////////////////////

// KEYWORDS Token //

struct TokenKeyword : Token {};

struct TokenKeywordAssign : TokenKeyword {};
struct TokenKeywordBegin : TokenKeyword {};
struct TokenKeywordEnd : TokenKeyword {};
struct TokenKeywordProg : TokenKeyword {};
struct TokenKeywordRead : TokenKeyword {};
struct TokenKeywordVar : TokenKeyword {};
struct TokenKeywordWrite : TokenKeyword {};

// KEYWORDS Token //

///////////////////////////////////////////////////////////

// DELIMETER Token //

struct TokenDelimeter : Token {};

struct TokenDelimeterColon : TokenDelimeter {};            // :
struct TokenDelimeterColonEqual : TokenDelimeter {};       // :=
struct TokenDelimeterComma : TokenDelimeter {};            // ,
struct TokenDelimeterLeftParenthesis : TokenDelimeter {};  // (
struct TokenDelimeterPlus : TokenDelimeter {};             // +
struct TokenDelimeterRightParenthesis : TokenDelimeter {}; // )
struct TokenDelimeterSemicolon : TokenDelimeter {};        // ;
struct TokenDelimeterStar : TokenDelimeter {};             // *

// DELIMETER Token //

// clang-format on

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// IDENTIFICATOR Token //

constexpr auto ID_STR = "ID";
constexpr auto NUM_STR = "NUM";

// IDENTIFICATOR Token //

///////////////////////////////////////////////////////////

// TYPE Token //

constexpr auto BOOL_STR = "BOOL";
constexpr auto FLOAT_STR = "FLOAT";
constexpr auto INT_STR = "INT";
constexpr auto STRING_STR = "STRING";

// TYPE Token //

///////////////////////////////////////////////////////////

// KEYWORDS Token //

constexpr auto ASSIGN_STR = "ASSIGN";
constexpr auto BEGIN_STR = "BEGIN";
constexpr auto END_STR = "END";
constexpr auto PROG_STR = "PROG";
constexpr auto READ_STR = "READ";
constexpr auto VAR_STR = "VAR";
constexpr auto WRITE_STR = "WRITE";

// KEYWORDS Token //

///////////////////////////////////////////////////////////

// DELIMETER Token //

constexpr auto COLON_STR = "COLON";
constexpr auto COLONEQUAL_STR = "COLONEQUAL";
constexpr auto COMMA_STR = "COMMA";
constexpr auto LEFTPARENTHESIS_STR = "LEFTPARENTHESIS";
constexpr auto PLUS_STR = "PLUS";
constexpr auto RIGHTPARENTHESIS_STR = "RIGHTPARENTHESIS";
constexpr auto SEMICOLON_STR = "SEMICOLON";
constexpr auto STAR_STR = "STAR";

// DELIMETER Token //

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum class TokenEnum
{
	ID = 0,
	NUM,

	BOOL,
	FLOAT,
	INT,
	STRING,

	ASSIGN,
	BEGIN,
	END,
	PROG,
	READ,
	VAR,
	WRITE,

	COLON,
	COLONEQUAL,
	COMMA,
	LEFTPARENTHESIS,
	PLUS,
	RIGHTPARENTHESIS,
	SEMICOLON,
	STAR,
};

static inline ::std::string TokenEnumToString(TokenEnum token)
{
	switch (token)
	{
	case TokenEnum::ID:
		return ID_STR;
	case TokenEnum::NUM:
		return NUM_STR;

	case TokenEnum::BOOL:
		return BOOL_STR;
	case TokenEnum::FLOAT:
		return FLOAT_STR;
	case TokenEnum::INT:
		return INT_STR;
	case TokenEnum::STRING:
		return STRING_STR;

	case TokenEnum::ASSIGN:
		return ASSIGN_STR;
	case TokenEnum::BEGIN:
		return BEGIN_STR;
	case TokenEnum::END:
		return END_STR;
	case TokenEnum::PROG:
		return PROG_STR;
	case TokenEnum::READ:
		return READ_STR;
	case TokenEnum::VAR:
		return VAR_STR;
	case TokenEnum::WRITE:
		return WRITE_STR;

	case TokenEnum::COLON:
		return COLON_STR;
	case TokenEnum::COLONEQUAL:
		return COLONEQUAL_STR;
	case TokenEnum::COMMA:
		return COMMA_STR;
	case TokenEnum::LEFTPARENTHESIS:
		return LEFTPARENTHESIS_STR;
	case TokenEnum::PLUS:
		return PLUS_STR;
	case TokenEnum::RIGHTPARENTHESIS:
		return RIGHTPARENTHESIS_STR;
	case TokenEnum::SEMICOLON:
		return SEMICOLON_STR;
	case TokenEnum::STAR:
		return STAR_STR;
	default:
		return "";
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T = Token>
class CLexeme
{
public:
	using Lexeme = common::Lexeme;

	// TODO: move to cpp (remove inline?)
	static inline std::string GetTokenType() const
	{
		if constexpr (std::is_same_v<T, TokenIdentificatorId>)
		{
			return TokenEnumToString(TokenEnum::ID);
		}
		if constexpr (std::is_same_v<T, TokenIdentificatorNum>)
		{
			return TokenEnumToString(TokenEnum::NUM);
		}

		if constexpr (std::is_same_v<T, TokenTypeBool>)
		{
			return TokenEnumToString(TokenEnum::BOOL);
		}
		if constexpr (std::is_same_v<T, TokenTypeFloat>)
		{
			return TokenEnumToString(TokenEnum::FLOAT);
		}
		if constexpr (std::is_same_v<T, TokenTypeInt>)
		{
			return TokenEnumToString(TokenEnum::INT);
		}
		if constexpr (std::is_same_v<T, TokenTypeString>)
		{
			return TokenEnumToString(TokenEnum::STRING);
		}

		if constexpr (std::is_same_v<T, TokenKeywordAssign>)
		{
			return TokenEnumToString(TokenEnum::ASSIGN);
		}
		if constexpr (std::is_same_v<T, TokenKeywordBegin>)
		{
			return TokenEnumToString(TokenEnum::BEGIN);
		}
		if constexpr (std::is_same_v<T, TokenKeywordEnd>)
		{
			return TokenEnumToString(TokenEnum::END);
		}
		if constexpr (std::is_same_v<T, TokenKeywordProg>)
		{
			return TokenEnumToString(TokenEnum::PROG);
		}
		if constexpr (std::is_same_v<T, TokenKeywordRead>)
		{
			return TokenEnumToString(TokenEnum::READ);
		}
		if constexpr (std::is_same_v<T, TokenKeywordVar>)
		{
			return TokenEnumToString(TokenEnum::VAR);
		}
		if constexpr (std::is_same_v<T, TokenKeywordWrite>)
		{
			return TokenEnumToString(TokenEnum::WRITE);
		}

		if constexpr (std::is_same_v<T, TokenDelimeterColon>)
		{
			return TokenEnumToString(TokenEnum::COLON);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterColonEqual>)
		{
			return TokenEnumToString(TokenEnum::COLONEQUAL);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterComma>)
		{
			return TokenEnumToString(TokenEnum::COMMA);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterLeftParenthesis>)
		{
			return TokenEnumToString(TokenEnum::LEFTPARENTHESIS);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterPlus>)
		{
			return TokenEnumToString(TokenEnum::PLUS);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterRightParenthesis>)
		{
			return TokenEnumToString(TokenEnum::RIGHTPARENTHESIS);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterSemicolon>)
		{
			return TokenEnumToString(TokenEnum::SEMICOLON);
		}
		if constexpr (std::is_same_v<T, TokenDelimeterStar>)
		{
			return TokenEnumToString(TokenEnum::STAR);
		}
	}

	explicit CLexeme() = default;

	const Lexeme& GetLexeme() const noexcept
	{
		return m_lexeme;
	}

	// TODO: Put here implementation lexema's methods

private:
	Lexeme m_lexeme = Lexeme{};
};

template <typename T = parser::lexeme::Token>
class LexemaException : public std::exception, public CLexeme<T>
{
public:
	using MyBaseException = std::exception;
	using MyBaseLexeme = CLexeme<T>;

	explicit LexemaException() = default;
	explicit LexemaException(const char* msg)
		: MyBaseException(msg)
		, MyBaseLexeme()
	{
	};
};

#include <iostream>

void usage()
{
	CLexeme<TokenDelimeterColonEqual> lexemeColonEqual;

	auto tokenStr = lexemeColonEqual.GetTokenType();
	auto& currentLexeme = lexemeColonEqual.GetLexeme();

	try
	{
		throw LexemaException<TokenDelimeterColonEqual>(
			// "At line %1%, at pos %2%"
		);
	}
	catch (LexemaException<Token>& e) // LexemaException without <> ??? bc of default template parameter
	{
		//::std::cout << 
		//	//::boost::format(
		//		"Failed to parse lexeme with %1%" type
		//	//) % e.GetTokenType() << '/n';
		//::std::cout << "/tAt line x at pos y"
	}
}

} // namespace parser::lexeme
