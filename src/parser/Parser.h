#pragma once

#include <istream>

#include "syntax_analyzer/SyntaxAnalyzer.hpp"
#include "parser_context/ParserContext.hpp"

namespace parser
{

class Parser
{
public:
	Parser(std::istream& input);

	bool Parse();

private:
	std::istream& m_input;
	ParserContext m_context;
};
} // namespace parser
