#include "pch.h"
#include "Parser.h"
#include "methods/Methods.h"

parser::Parser::Parser(std::istream& inputStream): m_inputStream(inputStream)
{
}

bool parser::Parser::Parse()
{
	return Methods::PROG(m_inputStream);
}
