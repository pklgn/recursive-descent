#pragma once

#include <functional>
#include <iostream>
#include <string>

#include "../../common.h"
#include"../IdList/IdList.h"

//class WriteFn
//{
//public:
//	WriteFn(std::istream& in, std::ostream& out)
//		: m_in(in)
//		, m_out(out)
//	{
//	}

//	std::function<bool()> Get(TokensMap& tMap)
//	{
//		return [this]() {
//			std::string writeStr;
//			m_in >> writeStr;
//			if (writeStr != "WRITE(")
//			{
//				return false;
//			}

//			if (!tMap["IDLIST"](tMap))
//			{
//				return false;
//			}

//			if (m_in.get() != ')')
//			{
//				return false;
//			}

//			return true;
//		};
//	}

//private:
//	std::istream& m_in;
//	std::ostream& m_out;
//};

bool WriteFn()
{
	std::string str;
	m_in >> str;
	if (str != "WRITE(")
	{
		return false;
	}

	if (!IdList())
	{
		return false;
	}

	m_in >> str;
	if (str != ')')
	{
		return false;
	}

	return true;
}