#include "Parser.h"

parser::Parser::Parser(std::istream& input): m_input(input)
{
}

bool parser::Parser::Parse()
{
	bool success = SyntaxAnalyzer::Prog(m_input, m_context);

	if (!success)
	{
		std::cout << "FATAL at " << m_context.line << ':' << m_context.col << std::endl
				  << "\texpected '" << m_context.lastExpectedToken << "' but '" << m_context.lastParsedToken << "' appeared" << std::endl;
	}

	return success;
}
