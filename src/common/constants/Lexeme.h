#pragma once
#include <unordered_map>

enum class LexemeEnum
{
	ID,
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
	MINUS,
	RIGHTPARENTHESIS,
	SEMICOLON,
	STAR,
};

const std::unordered_map<LexemeEnum, std::string> LEXEME = {
	{ LexemeEnum::PROG, "PROG" },
	{ LexemeEnum::BEGIN, "begin" },
	{ LexemeEnum::END, "end" },
	{ LexemeEnum::VAR, "VAR" },
	{ LexemeEnum::COLON, ":" },
	{ LexemeEnum::ID, "id" },
	{ LexemeEnum::NUM, "num" },
	{ LexemeEnum::BOOL, "bool" },
	{ LexemeEnum::FLOAT, "float" },
	{ LexemeEnum::INT, "int" },
	{ LexemeEnum::STRING, "string" },
	{ LexemeEnum::READ, "READ" },
	{ LexemeEnum::WRITE, "WRITE" },
	{ LexemeEnum::ASSIGN, "ASSIGN" },
	{ LexemeEnum::COLONEQUAL, ":=" },
	{ LexemeEnum::COMMA, "," },
	{ LexemeEnum::LEFTPARENTHESIS, "(" },
	{ LexemeEnum::PLUS, "+" },
	{ LexemeEnum::MINUS, "-" },
	{ LexemeEnum::RIGHTPARENTHESIS, ")" },
	{ LexemeEnum::SEMICOLON, ";" },
	{ LexemeEnum::STAR, "*" },
};