#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::op
{

// clang-format off

struct TokenDelimeter : Token {};

struct AssignmentOp       : TokenDelimeter {}; // :=
struct PlusOp             : TokenDelimeter {}; // +
struct MultiplyOp         : TokenDelimeter {}; // *
}