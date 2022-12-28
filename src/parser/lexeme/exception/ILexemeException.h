#pragma once

#include <string>

namespace parser::lexeme::exception
{

class ILexemeException
{
public:
	virtual std::string GetTokenType() const = 0;
	virtual const char* what() const = 0;

	virtual ~ILexemeException() = default;
};

} // namespace parser::lexeme::exception
