#include "pch.h"
#include <sstream>
#include <format>
#include "Methods.h"

void Methods::PrintMismatchError(LexemeEnum lexemeEnum)
{
	std::cout << "Mismatch was found in line " << m_line << " and column " << m_col
			  << "while matching the " << GetLexemeString(lexemeEnum) << "lexeme\n";
}

bool MatchLexeme(std::istream& inputStream, LexemeEnum expected)
{
	auto expectedLexeme = GetLexemeString(expected);
	char* actualLexeme = new char(); // memory leaks? wtf? ������? ����� new, delete �� ����
	inputStream.read(actualLexeme, expectedLexeme.size());
	bool areEqual = strcmp(expectedLexeme.c_str(), actualLexeme);

	if (!areEqual)
	{
		inputStream.seekg(-inputStream.gcount(), std::ios_base::cur);
	}
	delete actualLexeme; // ��� ������ �� ���

	return areEqual;
}

std::string GetLexemeString(LexemeEnum lexeme)
{
	return LEXEME.at(lexeme);
}

size_t GetLexemeLength(LexemeEnum lexeme)
{
	return GetLexemeString(lexeme).size();
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
		// ������� �� �������
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
		// ��� ���, ������ ��� ���� ������� �� �������
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
	// � ������� IDLIST -- � �������...
	// ���� ��������� ����
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
	return false;
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
