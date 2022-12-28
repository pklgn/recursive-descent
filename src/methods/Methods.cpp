#include "pch.h"
#include <sstream>
#include "Methods.h"

bool Methods::PROG(const ProgramText& programText, const Position& position)
{
	std::istringstream iss(programText.at(position.line));
	iss.seekg(position.index);
	Lexeme currLexeme;
	iss >> currLexeme;
	if (currLexeme != LEXEME.at(LexemeEnum::PROG))
	{
		return false;
	}


}
