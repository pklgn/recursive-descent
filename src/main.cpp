#include "pch.h"

#include "parser/lexeme/CLexeme/CLexeme.hpp"
#include "parser/lexeme/exception/CException/LexemeException.hpp"
#include "parser/lexeme/token/all.h"
#include "parser/Parser.h"

using namespace parser;

int main(int, char**)
{
	
	Parser parser(std::cin);
	bool successParse = parser.Parse();

	if (successParse)
	{
		std::cout << "SUCCESS\n";
	}
	else
	{
		std::cout << "ERROR\n";
	}

	return 0;
}
