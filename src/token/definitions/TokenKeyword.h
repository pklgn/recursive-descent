#pragma once

#include "BaseToken.h"

namespace token
{

// clang-format off

struct TokenKeyword : Token {};

struct BeginKeyword  : TokenKeyword {};
struct EndKeyword    : TokenKeyword {};
struct ProgKeyword   : TokenKeyword {};
struct ReadKeyword   : TokenKeyword {};
struct VarKeyword    : TokenKeyword {};
struct WriteKeyword  : TokenKeyword {};

// clang-format on

} // namespace token
