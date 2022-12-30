#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::delimeter
{

// clang-format off

struct TokenDelimeter : Token {};

struct Colon            : TokenDelimeter {}; // :
struct Comma            : TokenDelimeter {}; // ,
struct LeftParenthesis  : TokenDelimeter {}; // (
struct RightParenthesis : TokenDelimeter {}; // )
struct Semicolon        : TokenDelimeter {}; // ;

// clang-format on

} // namespace parser::lexeme::token::delimeter
