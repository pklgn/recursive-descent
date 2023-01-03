#include "pch.h"

#include "parser/token/definitions/definitions.h"
#include "parser/Parser.h"

int main()
{
	using namespace parser;

	Parser parser(std::cin, std::cout);

	bool successParse = parser.Parse();

	std::cout << (successParse ? "SUCCESS" : "ERROR") << std::endl;

	return 0;
}
