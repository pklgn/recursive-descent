#pragma once

#include <iostream>

#include "context/ParserContext.h"

namespace parser
{

class Parser
{
public:
	using InputStreamR = std::istream&;
	using OutputStreamR = std::ostream&;

	explicit Parser(InputStreamR input, OutputStreamR output = std::cout);

	bool Parse();

private:
	using Context = context::ParserContext;

	InputStreamR m_input;
	OutputStreamR m_echoOutput;
	Context m_context;
};

} // namespace parser
