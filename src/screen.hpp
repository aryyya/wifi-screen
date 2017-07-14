#pragma once

#include "SDL.h"
#include "fatal-error.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

namespace nf
{
  class Screen
  {
  private:
    std::string title;
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
  public:
    Screen(const std::string& title, const int width, const int height);
    ~Screen();
  };
}
