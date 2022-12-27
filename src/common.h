#pragma once

#include <functional>
#include <map>
#include <string>

using Token = std::string;
using Handler = std::function<bool(std::string)>;
using TokensMap = std::map<Token, Handler>;