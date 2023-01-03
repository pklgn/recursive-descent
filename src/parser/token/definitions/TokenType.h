#pragma once

#include "TokenKeyword.h"

namespace token
{

// clang-format off

struct TypeKeyword : TokenKeyword {};

struct BoolType   : TypeKeyword {}; // bool
struct FloatType  : TypeKeyword {}; // float
struct IntType    : TypeKeyword {}; // int
struct StringType : TypeKeyword {}; // string

// clang-format on

} // namespace token
