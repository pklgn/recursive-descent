#include "pch.h"

#include "Lexer.h"

namespace parser::lexer
{

void Lexer::SkipWs(InputStreamR stream, ParserContext& ctx)
{
	char ch;
	while (std::isspace(ch = stream.peek()))
	{
		if (ch == '\n')
		{
			++ctx.line;
			ctx.col = 1;
		}

		stream.get();
		++ctx.col;
	}
}

void Lexer::StrToLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char ch) { return std::tolower(ch); });
}

} // namespace parser::lexer
