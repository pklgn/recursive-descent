#pragma once

#include "BaseToken.h"

namespace token
{

// clang-format off

struct TokenOperator : Token {};

struct AssignmentOp       : TokenOperator {}; // :=
struct PlusOp             : TokenOperator {}; // +
struct MultiplyOp         : TokenOperator {}; // *
struct UnaryMinusOp       : TokenOperator {}; // -

} // namespace token
