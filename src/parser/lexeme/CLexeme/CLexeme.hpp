#pragma once

#include <string>

#include "parser/common_parser.h"

#include "../token/definitions/token_definitions.h"
#include "../token/definitions/enum/TokenEnum.hpp"

namespace parser::lexeme
{

template <typename T = token::Token>
class CLexeme
{
public:
	using Lexeme = common::Lexeme;

	static ::std::string GetTokenType();

	explicit CLexeme() = default;

	const Lexeme& GetLexeme() const noexcept;

	// TODO: Put here implementation lexema's methods

private:
	Lexeme m_lexeme = Lexeme{};
};

// TODO: move to other place
template <typename T>
inline ::std::string parser::lexeme::CLexeme<T>::GetTokenType()
{
	using namespace token::delimeter;
	using namespace token::special;
	using namespace token::keyword;
	using namespace token::type;

	using token::TokenEnum;

	if constexpr (std::is_same_v<T, TokenIdentifier>)
	{
		return TokenEnumToString(TokenEnum::ID);
	}
	if constexpr (std::is_same_v<T, TokenNum>)
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

	return token::enum_str::TOKEN_STR;
}

template <typename T>
inline const CLexeme<T>::Lexeme& CLexeme<T>::GetLexeme() const noexcept
{
	return m_lexeme;
}

} // namespace parser::lexeme
