#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::identifier
{

// clang-format off

struct TokenIdentificator : Token {};

struct TokenIdentificatorId  : TokenIdentificator {};
struct TokenIdentificatorNum : TokenIdentificator {};

// clang-format on

} // namespace parser::lexeme::token::identifier
