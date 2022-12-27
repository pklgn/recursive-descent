#pragma once

#include <iostream>

class Reader
{
public:
	using RInputStream = std::istream&;
	using ROutputStream = std::ostream&;

	Reader(RInputStream input, ROutputStream output);

	bool Parse();

private:
	RInputStream m_inputStream;
	ROutputStream m_outputStream;
};
