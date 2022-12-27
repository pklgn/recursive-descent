#pragma once
#include <functional>
#include <sstream>
#include "common.h"

using Id = std::string;

const char ID_DELIMETER = ',';

bool IsDelimeter(char ch)
{

}

struct IdList
{
	bool operator()(std::string& str)
	{
		std::istringstream iss(str);
		Id currId;
		char delim;
		while (!iss.fail())
		{
			iss >> currId;

			iss >> delim;
			if (delim != ID_DELIMETER)
			{
				return false;
			}
		}

	}
};