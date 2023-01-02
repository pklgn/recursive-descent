#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>

#include "common_dirs_defines.h"

#include <catch2/catch_all.hpp>

namespace test
{

namespace StdFs = ::std::filesystem;

using StdPath = StdFs::path;

} // namespace test
