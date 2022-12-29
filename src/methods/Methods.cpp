#include "pch.h"
#include <sstream>
#include <format>
#include "Methods.h"

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
	std::cout << "Mismatch was found in line " << m_line << " and column " << m_col
			  << "while matching the " << GetLexemeString(lexemeEnum) << "lexeme\n";
}

bool MatchLexeme(std::istream& inputStream, LexemeEnum expected)
{
	auto expectedLexeme = GetLexemeString(expected);
	char* actualLexeme = new char(); // memory leaks? wtf? почему? юзнул new, delete не вижу
	inputStream.read(actualLexeme, expectedLexeme.size());
	bool areEqual = strcmp(expectedLexeme.c_str(), actualLexeme);

	if (!areEqual)
	{
		inputStream.seekg(-inputStream.gcount(), std::ios_base::cur);
	}
	delete actualLexeme; // вот теперь всё гуд

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

	if (!ParseLexeme(inputStream, LexemeEnum::END))
	{
		return false;
	}

	return true;
}

bool Methods::VAR(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::VAR))
	{
		return false;
	}

	if (!Methods::IDLIST(inputStream))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::COLON))
	{
		return false;
	}

	if (!Methods::TYPE(inputStream))
	{
		return false;
	}

	return true;
}

bool Methods::LISTST(std::istream& inputStream)
{
	if (!Methods::ST(inputStream))
	{
		if (!Methods::LISTST_RIGHT(inputStream))
		{
			return false;
		}
	}

	return true;
}

bool Methods::LISTST_RIGHT(std::istream& inputStream)
{
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
	if (!MatchLexeme(in, LexemeEnum::ID))
	{
		std::cout << m_line << ':' << m_col << "expected 'id'";
		return false;
	}

	m_col += GetLexemeLength(LexemeEnum::ID);

	IDLIST_RIGHT(in);
}

bool Methods::IDLIST_RIGHT(std::istream& in)
{
	SkipWhitespaces(in);
	if (!MatchLexeme(in, LexemeEnum::COMMA))
	{
		// тут так, потому что есть переход по эпсилон
		return true;
	}
	SkipWhitespaces(in);
	if (!MatchLexeme(in, LexemeEnum::ID))
	{
		std::cout << m_line << ':' << m_col << "expected 'id'";
		return false;
	}
	m_col += GetLexemeLength(LexemeEnum::ID);

	IDLIST_RIGHT(in);
	// Я написал IDLIST -- я доволен...
	// Всем спокойной ночи
}

bool Methods::ST(std::istream& inputStream)
{
	if (!Methods::READ(inputStream))
	{
		if (!Methods::WRITE(inputStream))
		{
			if (!Methods::ASSIGN(inputStream))
			{
				return false;
			}
		}
	}

	return true;
}

bool Methods::TYPE(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::INT))
	{
		if (!ParseLexeme(inputStream, LexemeEnum::FLOAT))
		{
			if (!ParseLexeme(inputStream, LexemeEnum::BOOL))
			{
				if (!ParseLexeme(inputStream, LexemeEnum::STRING))
				{
					return false;
				}
			}

		}
	}

	return true;
}

bool Methods::READ(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::READ))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::LEFTPARENTHESIS))
	{
		return false;
	}

	if (!Methods::IDLIST(inputStream))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::SEMICOLON))
	{
		return false;
	}

	return true;
}

bool Methods::WRITE(std::istream& inputStream)
{
	if (!ParseLexeme(inputStream, LexemeEnum::WRITE))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::LEFTPARENTHESIS))
	{
		return false;
	}

	if (!Methods::IDLIST(inputStream))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS))
	{
		return false;
	}

	if (!ParseLexeme(inputStream, LexemeEnum::SEMICOLON))
	{
		return false;
	}

	return true;
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

	if (!Methods::T_RIGHT(inputStream))
	{
		return false;
	}

	return true;
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
			}
		}

		if (!Methods::EXP(inputStream))
		{
			return false;
		}

		if (!ParseLexeme(inputStream, LexemeEnum::RIGHTPARENTHESIS))
		{
			return false;
		}
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
		}

		in.get();
		++m_col;
	}
}
