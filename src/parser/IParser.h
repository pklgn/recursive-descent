#pragma once

#include <string>

#include "IParser_fwd.h"
#include "common_parser.h"

namespace parser
{

class IParser
{
public:
	using Lexeme = common::Lexeme;

	// TODO: const? noexept? constexpr?

	virtual ~IParser() = default;
};

} // namespace parser
