#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::keyword
{

// clang-format off

struct TokenKeyword : Token {};

struct TokenKeywordAssign : TokenKeyword {};
struct TokenKeywordBegin  : TokenKeyword {};
struct TokenKeywordEnd    : TokenKeyword {};
struct TokenKeywordProg   : TokenKeyword {};
struct TokenKeywordRead   : TokenKeyword {};
struct TokenKeywordVar    : TokenKeyword {};
struct TokenKeywordWrite  : TokenKeyword {};

// clang-format on

} // namespace parser::lexeme::token::keyword
