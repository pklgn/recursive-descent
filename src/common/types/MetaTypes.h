#pragma once
#include <vector>
#include <string>

using ProgramText = std::vector<std::string>;

struct Position
{
	size_t line;
	size_t index;
};