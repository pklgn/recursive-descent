#include "pch.h"
#include "Parser.h"
#include "methods/Methods.h"

parser::Parser::Parser(std::istream& inputStream): m_inputStream(inputStream)
{
}

void parser::Parser::Parse()
{
	Position position{
		0, 0
	};

	try
	{
		Methods::PROG(m_inputStream);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}
}
