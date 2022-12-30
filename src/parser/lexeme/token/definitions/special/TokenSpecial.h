#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::special
{

// clang-format off

struct TokenSpecial : Token {};

struct Identifier  : TokenSpecial {}; // id
struct Number      : TokenSpecial {}; // num

// clang-format on

} // namespace parser::lexeme::token::identifier
