#include "screen.hpp"

nf::Screen::Screen(const std::string& title, const int width, const int height)
              : title(title), width(width), height(height)
{
  if (SDL_WasInit(SDL_INIT_VIDEO) == 0) nf::fatal_error("sdl video subsystem was not initialized");

  window = SDL_CreateWindow(
    title.c_str(),
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    this->width,
    this->height,
    SDL_WINDOW_SHOWN
  );
  if (window == nullptr) nf::fatal_error_sdl("sdl window creation error", nf::ErrorType::SDL);

  renderer = SDL_CreateRenderer(
    window,
    -1,
    0
  );
  if (renderer == nullptr) nf::fatal_error_sdl("sdl renderer creation error", nf::ErrorType::SDL);
}

nf::Screen::~Screen()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}
