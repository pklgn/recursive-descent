#include "pch.h"
#include "Parser.h"
#include "methods/Methods.h"

parser::Parser::Parser(std::istream& inputStream): m_inputStream(inputStream)
{
}

bool parser::Parser::Parse()
{
	bool success = Methods::PROG(m_inputStream);

	if (!success)
	{
		std::cout << "\nFATAL at " << Methods::GetLine()
				  << " with lexeme " << Methods::GetLexeme() << '\n'; 
	}

	return success;
}
