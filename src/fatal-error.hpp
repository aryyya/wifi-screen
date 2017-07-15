#pragma once

#include "SDL.h"
#include "SDL_net.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace nf
{
  enum ErrorType
  {
    SDL,
    SDL_NET
  };
  void fatal_error(const std::string& error_message);
  void fatal_error_sdl(const std::string& error_message, const ErrorType error_category);
}
