#pragma once

#include "../definitions/TokenKeyword.h"
#include "TokenValue.hpp"

namespace token
{

// clang-format off

template <>
constexpr std::string Value<BeginKeyword>() { return "begin"; }

template <>
constexpr std::string Value<EndKeyword>() { return "end"; }

template <>
constexpr std::string Value<ProgKeyword>() { return "prog"; }

template <>
constexpr std::string Value<ReadKeyword>() { return "read"; }

template <>
constexpr std::string Value<VarKeyword>() { return "var"; }

template <>
constexpr std::string Value<WriteKeyword>() { return "write"; }

// clang-format on

} // namespace token
