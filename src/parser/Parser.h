#pragma once
#include <istream>
#include "IParser.h"

namespace parser
{

class Parser : public IParser
{
public:
	Parser(std::istream&);

	bool Parse();

private:
	std::istream& m_inputStream;
};
} // namespace parser
