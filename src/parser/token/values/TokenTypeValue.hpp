#pragma once

#include "../definitions/TokenType.h"
#include "TokenValue.hpp"

namespace token
{

// clang-format off

template <>
constexpr std::string Value<BoolType>() { return "bool"; }

template <>
constexpr std::string Value<FloatType>() { return "float"; }

template <>
constexpr std::string Value<IntType>() { return "int"; }

template <>
constexpr std::string Value<StringType>() { return "string"; }

// clang-format on

} // namespace token
