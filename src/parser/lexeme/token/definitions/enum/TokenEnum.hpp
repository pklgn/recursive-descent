#pragma once

#include <string>

namespace parser::lexeme::token
{

namespace enum_str
{

constexpr auto TOKEN_STR = "Token";

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

} // namespace enum_str

enum class TokenEnum
{
	// IDENTIFICATOR Token //

	ID = 0,
	NUM,

	// IDENTIFICATOR Token //

	///////////////////////////////////////////////////////////
	
	BOOL,
	FLOAT,
	INT,
	STRING,

	// TYPE Token //

	///////////////////////////////////////////////////////////

	// KEYWORDS Token //

	ASSIGN,
	BEGIN,
	END,
	PROG,
	READ,
	VAR,
	WRITE,

	// KEYWORDS Token //

	///////////////////////////////////////////////////////////

	// DELIMETER Token //

	COLON,
	COLONEQUAL,
	COMMA,
	LEFTPARENTHESIS,
	PLUS,
	RIGHTPARENTHESIS,
	SEMICOLON,
	STAR,

	// DELIMETER Token //
};

static inline ::std::string TokenEnumToString(TokenEnum token)
{
	using namespace enum_str;

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
		return TOKEN_STR;
	}
}

} // namespace parser::lexeme::token
