#pragma once
#include "common/types/MetaTypes.h"

struct Methods
{
	Methods() = delete;

	static bool PROG(std::istream&,  Position&);
	static bool VAR(std::istream&,  Position&);
	static bool LISTST(std::istream&,  Position&);
	static bool LISTST_RIGHT(std::istream&,  Position&);
	static bool IDLIST(std::istream&,  Position&);
	static bool IDLIST_RIGHT(std::istream&,  Position&);
	static bool ST(std::istream&,  Position&);
	static bool TYPE(std::istream&,  Position&);
	static bool READ(std::istream&,  Position&);
	static bool WRITE(std::istream&,  Position&);
	static bool ASSIGN(std::istream&,  Position&);
	static bool EXP(std::istream&,  Position&);
	static bool T(std::istream&,  Position&);
	static bool F(std::istream&,  Position&);
};
