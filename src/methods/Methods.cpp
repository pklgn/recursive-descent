#include "pch.h"
#include <sstream>
#include <format>
#include "Methods.h"
#include "pch.h"

std::string GetLexemeString(LexemeEnum lexeme)
{
	return LEXEME.at(lexeme);
}

size_t GetLexemeLength(LexemeEnum lexeme)
{
	return GetLexemeString(lexeme).size();
}

void Methods::PrintMismatchError(LexemeEnum lexemeEnum)
{
	m_errorLexeme = GetLexemeString(lexemeEnum);
}

bool MatchLexeme(std::istream& inputStream, LexemeEnum expected)
{
	auto expectedLexeme = GetLexemeString(expected);
	char* actualLexeme = new char(); // memory leaks? wtf? почему? юзнул new, delete не вижу
	inputStream.read(actualLexeme, expectedLexeme.size());
	actualLexeme[expectedLexeme.size()] = '\0';
	bool areEqual = common::string::util::IEqualRawStrings(actualLexeme, expectedLexeme.c_str());

	if (!areEqual)
	{
		inputStream.seekg(-inputStream.gcount(), std::ios_base::cur);
	}

	return areEqual;
}

bool Methods::ParseLexeme(std::istream& inputStream, LexemeEnum lexemeEnum)
{
	SkipWhitespaces(inputStream);
	if (!MatchLexeme(inputStream, lexemeEnum))
	{
		PrintMismatchError(lexemeEnum);

		return false;
	}
	m_col += GetLexemeLength(lexemeEnum);

	return true;
}

bool Methods::PROG(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::PROG))
	{
		return false;
	}
	if (!ParseLexeme(inputStream, LexemeEnum::ID))
	{
		return false;
	}
	if (!Methods::VAR(inputStream))
	{
		return false;
	}
	if (!ParseLexeme(inputStream, LexemeEnum::BEGIN))
	{
		return false;
	}
	if (!Methods::LISTST(inputStream))
	{
		return false;
	}

	return ParseLexeme(inputStream, LexemeEnum::END);
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
	if (!Methods::ST(inputStream))
	{
		return false;
	}
	if (!Methods::LISTST_RIGHT(inputStream))
	{
		return false;
	}

	return true;
}

bool Methods::LISTST_RIGHT(std::istream& inputStream)
{
	// что делать
	// кто виноват
	if (!Methods::ST(inputStream))
	{
		// переход по эпсилон
		return true;
	}
	if (!Methods::LISTST_RIGHT(inputStream))
	{
		return false;
	}

	return true;
}

bool Methods::IDLIST(std::istream& in)
{
	return ParseLexeme(in, LexemeEnum::ID) && IDLIST_RIGHT(in);
}

bool Methods::IDLIST_RIGHT(std::istream& in)
{
	if (!ParseLexeme(in, LexemeEnum::COMMA))
	{
		// тут так, потому что есть переход по эпсилон
		return true;
	}

	return ParseLexeme(in, LexemeEnum::ID) && IDLIST_RIGHT(in);
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
	if (!ParseLexeme(inputStream, LexemeEnum::ID))
	{
		return false;
	}
	if (!ParseLexeme(inputStream, LexemeEnum::COLONEQUAL))
	{
		return false;
	}
	if (!Methods::EXP(inputStream))
	{
		return false;
	}
	if (!ParseLexeme(inputStream, LexemeEnum::SEMICOLON))
	{
		return false;
	}

	return true;
}

bool Methods::EXP(std::istream& inputStream)
{
	if (!Methods::T(inputStream))
	{
		return false;
	}
	if (!Methods::EXP_RIGHT(inputStream))
	{
		return false;
	}

	return true;
}

bool Methods::EXP_RIGHT(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::PLUS))
	{
		// обработка эпсилон
		return true;
	}
	if (!Methods::T(inputStream))
	{
		return false;
	}
	if (!Methods::EXP_RIGHT(inputStream))
	{
		return false;
	}

	return true;
}

bool Methods::T(std::istream& inputStream)
{
	if (!Methods::F(inputStream))
	{
		return false;
	}
	if (!Methods::T_RIGHT(inputStream))
	{
		return false;
	}

	return true;
}

bool Methods::T_RIGHT(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::STAR))
	{
		// обработка эпсилон
		return true;
	}
	if (!Methods::F(inputStream))
	{
		return false;
	}

	return Methods::T_RIGHT(inputStream);
}

bool Methods::F(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::MINUS))
	{
		if (!ParseLexeme(inputStream, LexemeEnum::LEFTPARENTHESIS))
		{
			if (!ParseLexeme(inputStream, LexemeEnum::ID))
			{
				if (!ParseLexeme(inputStream, LexemeEnum::NUM))
				{
					return false;
				}

				return true;
			}

			return true;
		}

		if (!Methods::EXP(inputStream))
		{
			return false;
		}
		if (!ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS))
		{
			return false;
		}

		return true;
	}

	if (!Methods::F(inputStream))
	{
		return false;
	}

	return true;
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
