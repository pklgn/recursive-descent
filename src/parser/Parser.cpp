#include "pch.h"

#include "Parser.h"

#include "syntax_analyzer/SyntaxAnalyzer.h"

namespace parser
{

Parser::Parser(InputStreamR input, OutputStreamR output)
	: m_input(input)
	, m_echoOutput(output)
{
}

bool Parser::Parse()
{
	bool success = syntax_analyzer::SyntaxAnalyzer::Prog(m_input, m_context);

	if (!success)
	{
		m_echoOutput << "FATAL at " << m_context.line << ':' << m_context.col << '\n'
					 << "\tEXPECTED: '" << m_context.lastExpectedToken << "'" << '\n'
					 << "\tGOT: '" << m_context.lastParsedToken << std::endl;
	}

	return success;
}

} // namespace parser
