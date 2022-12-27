#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::type
{

// clang-format off

struct TokenType : Token {};

struct TokenTypeBool   : TokenType {};
struct TokenTypeFloat  : TokenType {};
struct TokenTypeInt    : TokenType {};
struct TokenTypeString : TokenType {};

// clang-format on

} // namespace parser::lexeme::token::type
