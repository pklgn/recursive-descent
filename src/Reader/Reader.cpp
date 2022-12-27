#include "pch.h"

#include "Reader.h"

Reader::Reader(RInputStream input, ROutputStream output)
	: m_inputStream(input)
	, m_outputStream(output)
{
}

bool Reader::Parse()
{
	std::string word, phrase;
	while (m_inputStream >> word)
	{
		phrase += word + ' ';
	}
}
