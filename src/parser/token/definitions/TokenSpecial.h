#pragma once

#include "BaseToken.h"

namespace token
{

// clang-format off

struct TokenSpecial : Token {};

struct Identifier  : TokenSpecial {}; // id
struct Number      : TokenSpecial {}; // num
struct None        : TokenSpecial {}; //

// clang-format on

} // namespace token
