#pragma once
#include "common/types/MetaTypes.h"
#include "pch.h"

struct Methods
{
	Methods() = delete;

	static bool PROG(std::istream&);
	static bool VAR(std::istream&);
	static bool LISTST(std::istream&);
	static bool LISTST_RIGHT(std::istream&);
	static bool IDLIST(std::istream&);
	static bool IDLIST_RIGHT(std::istream&);
	static bool ST(std::istream&);
	static bool TYPE(std::istream&);
	static bool READ(std::istream&);
	static bool WRITE(std::istream&);
	static bool ASSIGN(std::istream&);
	static bool EXP(std::istream&);
	static bool EXP_RIGHT(std::istream&);
	static bool T(std::istream&);
	static bool T_RIGHT(std::istream&);
	static bool F(std::istream&);

	static std::string GetLastErrorMessage();

private:
	static bool ParseLexeme(std::istream&, LexemeEnum);
	static void SkipWhitespaces(std::istream& in);

	inline static size_t m_line = 1;
	inline static size_t m_col = 0;
	inline static std::string m_errorLexeme;
};
