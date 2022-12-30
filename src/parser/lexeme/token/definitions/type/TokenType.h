#pragma once

#include "../keyword/TokenKeyword.h"

namespace parser::lexeme::token::type
{

// clang-format off

struct TypeKeyword : keyword::TokenKeyword {};

struct BoolType   : TypeKeyword {}; // bool
struct FloatType  : TypeKeyword {}; // float
struct IntType    : TypeKeyword {}; // int
struct StringType : TypeKeyword {}; // string

// clang-format on

} // namespace parser::lexeme::token::type
