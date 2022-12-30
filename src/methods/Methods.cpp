#include <sstream>
#include "Methods.h"

bool MatchLexeme(std::istream& inputStream, LexemeEnum expected)
{
	auto expectedLexeme = LEXEME.at(expected);
	std::string actualLexeme(expectedLexeme.size(), 0); // memory leaks? wtf? почему? юзнул new, delete не вижу
	inputStream.read(actualLexeme.data(), expectedLexeme.size());
	bool areEqual = common::string::util::IEqualRawStrings(actualLexeme.c_str(), expectedLexeme.c_str());

	if (!areEqual)
	{
		inputStream.seekg(-inputStream.gcount(), std::ios_base::cur);
	}

	return areEqual;
}

bool Methods::ParseLexeme(std::istream& inputStream, LexemeEnum lexeme)
{
	SkipWhitespaces(inputStream);
	if (!MatchLexeme(inputStream, lexeme))
	{
		m_errorLexeme = LEXEME.at(lexeme);

		return false;
	}
	m_col += LEXEME.at(lexeme).size();

	return true;
}

bool Methods::PROG(std::istream& inputStream)
{
	return 
		ParseLexeme(inputStream, LexemeEnum::PROG) && 
		ParseLexeme(inputStream, LexemeEnum::ID) && 
		VAR(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::BEGIN) && 
		LISTST(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::END);
}

bool Methods::VAR(std::istream& inputStream)
{
	return 
		ParseLexeme(inputStream, LexemeEnum::VAR) && 
		IDLIST(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::COLON) && 
		TYPE(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::SEMICOLON);
}

bool Methods::LISTST(std::istream& inputStream)
{
	return ST(inputStream) && LISTST_RIGHT(inputStream);
}

bool Methods::LISTST_RIGHT(std::istream& inputStream)
{
	// это же гениальная хрень
	return !ST(inputStream) || LISTST_RIGHT(inputStream);
}

bool Methods::IDLIST(std::istream& in)
{
	return ParseLexeme(in, LexemeEnum::ID) && IDLIST_RIGHT(in);
}

bool Methods::IDLIST_RIGHT(std::istream& in)
{
	return 
		!ParseLexeme(in, LexemeEnum::COMMA) || 
		(ParseLexeme(in, LexemeEnum::ID) && IDLIST_RIGHT(in));
}

bool Methods::ST(std::istream& inputStream)
{
	return 
		READ(inputStream) || 
		WRITE(inputStream) ||
		ASSIGN(inputStream);
}

bool Methods::TYPE(std::istream& inputStream)
{
	return 
		ParseLexeme(inputStream, LexemeEnum::INT) || 
		ParseLexeme(inputStream, LexemeEnum::FLOAT) || 
		ParseLexeme(inputStream, LexemeEnum::BOOL) || 
		ParseLexeme(inputStream, LexemeEnum::STRING);
}

bool Methods::READ(std::istream& inputStream)
{
	return 
		ParseLexeme(inputStream, LexemeEnum::READ) && 
		ParseLexeme(inputStream, LexemeEnum::LEFTPARENTHESIS) && 
		IDLIST(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS) && 
		ParseLexeme(inputStream, LexemeEnum::SEMICOLON);
}

bool Methods::WRITE(std::istream& inputStream)
{
	return 
		ParseLexeme(inputStream, LexemeEnum::WRITE) && 
		ParseLexeme(inputStream, LexemeEnum::LEFTPARENTHESIS) && 
		IDLIST(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS) && 
		ParseLexeme(inputStream, LexemeEnum::SEMICOLON);
}

bool Methods::ASSIGN(std::istream& inputStream)
{
	return 
		ParseLexeme(inputStream, LexemeEnum::ID) && 
		ParseLexeme(inputStream, LexemeEnum::COLONEQUAL) && 
		EXP(inputStream) && 
		ParseLexeme(inputStream, LexemeEnum::SEMICOLON);
}

bool Methods::EXP(std::istream& inputStream)
{
	return T(inputStream) && EXP_RIGHT(inputStream);
}

bool Methods::EXP_RIGHT(std::istream& inputStream)
{
	return 
		!ParseLexeme(inputStream, LexemeEnum::PLUS) || 
		(T(inputStream) && EXP_RIGHT(inputStream));
}

bool Methods::T(std::istream& inputStream)
{
	return F(inputStream) && T_RIGHT(inputStream);
}

bool Methods::T_RIGHT(std::istream& inputStream)
{
	return 
		!ParseLexeme(inputStream, LexemeEnum::STAR) || 
		(F(inputStream) && Methods::T_RIGHT(inputStream));
}

bool Methods::F(std::istream& inputStream)
{
	return 
		(ParseLexeme(inputStream, LexemeEnum::MINUS) && F(inputStream)) || 
		(ParseLexeme(inputStream, LexemeEnum::LEFTPARENTHESIS) && EXP(inputStream) && ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS)) || 
		ParseLexeme(inputStream, LexemeEnum::ID) || 
		ParseLexeme(inputStream, LexemeEnum::NUM);
}

void Methods::SkipWhitespaces(std::istream& in)
{
	char ch;
	while (std::isspace(ch = in.peek()))
	{
		if (ch == '\n')
		{
			++m_line;
			m_col = 1;
		}

		in.get();
		++m_col;
	}
}

std::string Methods::GetLastErrorMessage()
{
	std::ostringstream stream;
	stream << "FATAL at " << m_line << ':' << m_col << " with lexeme " << m_errorLexeme;
	return stream.str();
}
