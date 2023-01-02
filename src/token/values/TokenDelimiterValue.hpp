#pragma once

#include "../definitions/TokenDelimeter.h"
#include "TokenValue.hpp"

namespace token
{

// clang-format off

template <>
constexpr std::string Value<Colon>() { return ":"; }

template <>
constexpr std::string Value<Comma>() { return ","; }

template <>
constexpr std::string Value<LeftParenthesis>() { return "("; }

template <>
constexpr std::string Value<RightParenthesis>() { return ")"; }

template <>
constexpr std::string Value<Semicolon>() { return ";"; }

// clang-format on

} // namespace token
