#pragma once

#include "SDL.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace nf
{
  void fatal_error(const std::string& error_message);
  void fatal_error_sdl(const std::string& error_message);
}
