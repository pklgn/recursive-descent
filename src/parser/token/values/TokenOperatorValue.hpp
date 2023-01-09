#pragma once

#include "../definitions/TokenOperator.h"
#include "TokenValue.hpp"

namespace token
{

// clang-format off

template <>
constexpr std::string Value<AssignmentOp>() { return ":="; }

template <>
constexpr std::string Value<PlusOp>() { return "+"; }

template <>
constexpr std::string Value<MultiplyOp>() { return "*"; }

template <>
constexpr std::string Value<UnaryMinusOp>() { return "-"; }

// clang-format on

} // namespace token
