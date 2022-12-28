#pragma once
#include <unordered_map>

enum class LexemeEnum
{
	ID = 0,
	NUM,

	BOOL,
	FLOAT,
	INT,
	STRING,

	ASSIGN,
	BEGIN,
	END,
	PROG,
	READ,
	VAR,
	WRITE,

	COLON,
	COLONEQUAL,
	COMMA,
	LEFTPARENTHESIS,
	PLUS,
	RIGHTPARENTHESIS,
	SEMICOLON,
	STAR,
};

const std::unordered_map<LexemeEnum, std::string> LEXEME = {
	{ LexemeEnum::PROG, "PROG" },
	{ LexemeEnum::BEGIN, "begin" },
	{ LexemeEnum::END, "end" },
	{ LexemeEnum::VAR, "VAR" },
	{ LexemeEnum::COLON, ":" }
};