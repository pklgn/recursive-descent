//#pragma once
//
//#include <stdexcept>
//
//#include "../../CLexeme/CLexeme.hpp"
//#include "../../../../token/definitions/definitions.h"
//#include "../ILexemeException.h"
//
//namespace parser::lexeme::exception
//{
//
//template <typename T = token::Token>
//class LexemeException
//	: public std::exception
//	, public CLexeme<T>
//	, virtual public ILexemeException
//{// TODO: maybe get CLexeme in ctor is proper way to achieve same
//public:
//	using MyBaseException = std::exception;
//	using MyBaseLexeme = CLexeme<T>;
//
//	explicit LexemeException() = default;
//	explicit LexemeException(const char* msg)
//		: MyBaseException(msg)
//		, MyBaseLexeme()
//	{
//	}
//
//	std::string GetTokenType() const override
//	{
//		return MyBaseLexeme::GetTokenType();
//	}
//
//	const char* what() const override
//	{
//		return MyBaseException::what();
//	}
//};
//
//} // namespace parser::lexeme::exception
