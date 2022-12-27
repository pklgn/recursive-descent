#pragma once

#include "../BaseToken.h"

namespace parser::lexeme::token::delimeter
{

// clang-format off

struct TokenDelimeter : Token {};

struct TokenDelimeterColon            : TokenDelimeter {}; // :
struct TokenDelimeterColonEqual       : TokenDelimeter {}; // :=
struct TokenDelimeterComma            : TokenDelimeter {}; // ,
struct TokenDelimeterLeftParenthesis  : TokenDelimeter {}; // (
struct TokenDelimeterPlus             : TokenDelimeter {}; // +
struct TokenDelimeterRightParenthesis : TokenDelimeter {}; // )
struct TokenDelimeterSemicolon        : TokenDelimeter {}; // ;
struct TokenDelimeterStar             : TokenDelimeter {}; // *

// clang-format on

} // namespace parser::lexeme::token::delimeter
