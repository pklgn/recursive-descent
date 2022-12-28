#pragma once
#include "common/types/MetaTypes.h"

struct Methods
{
	Methods() = delete;

	static bool PROG(const ProgramText&, const Position&);
	static bool VAR(const ProgramText&, const Position&);
	static bool LISTST(const ProgramText&, const Position&);
	static bool LISTST_RIGHT(const ProgramText&, const Position&);
	static bool IDLIST(const ProgramText&, const Position&);
	static bool IDLIST_RIGHT(const ProgramText&, const Position&);
	static bool ST(const ProgramText&, const Position&);
	static bool TYPE(const ProgramText&, const Position&);
	static bool READ(const ProgramText&, const Position&);
	static bool WRITE(const ProgramText&, const Position&);
	static bool ASSIGN(const ProgramText&, const Position&);
	static bool EXP(const ProgramText&, const Position&);
	static bool T(const ProgramText&, const Position&);
	static bool F(const ProgramText&, const Position&);
};
