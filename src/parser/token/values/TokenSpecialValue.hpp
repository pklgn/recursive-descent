#pragma once

#include "../definitions/TokenSpecial.h"
#include "TokenValue.hpp"

namespace token
{

// clang-format off

template <>
constexpr std::string Value<Identifier>() { return "id"; }

template <>
constexpr std::string Value<Number>() { return "num"; }

template <>
constexpr std::string Value<None>() { return ""; }

// clang-format on

} // namespace token
