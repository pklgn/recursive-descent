#pragma once
#include "common.h"

inline static const TokensMap TOKENS_MAP = {
	{ "PROG", []() { return true; } },
	{ "VAR", []() { return true; } },
	{ "IDLIST", []() { return true; } },
	{ "LISTST", []() { return true; } },
	{ "TYPE", []() { return true; } },
	{ "ST", []() { return true; } },
	{ "ASSIGN", []() { return true; } },
};
