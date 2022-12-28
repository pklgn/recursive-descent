#include "pch.h"

#include "parser/lexeme/CLexeme/CLexeme.hpp"
#include "parser/lexeme/exception/CException/LexemeException.hpp"
#include "parser/lexeme/token/all.h"

int main(int, char**)
{
	using namespace parser::lexeme;
	using namespace parser::lexeme::token;
	using namespace parser::lexeme::token::delimeter;
	using namespace parser::lexeme::exception;

	CLexeme<TokenDelimeterColonEqual> lexemeColonEqual;

	auto tokenStr = lexemeColonEqual.GetTokenType();
	auto& currentLexeme = lexemeColonEqual.GetLexeme();

	try
	{
		throw LexemeException<TokenDelimeterColonEqual>("At line %1%, at pos %2%");
	}
	catch (ILexemeException& e)
	{
		std::cout << ("Failed to parse lexeme with " + e.GetTokenType()) + " type\n";
		std::cout << "\tAt line 0 at pos 0\n"
				  << "\tWith msg: " << e.what() << std::endl;
	}

	return 0;
}
