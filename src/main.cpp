#include "SDL.h"
#include "SDL_net.h"
#include "fatal-error.hpp"
#include "network.hpp"
#include "screen.hpp"

namespace
{
  void
  _initialize()
  {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) nf::fatal_error_sdl("sdl initialization error", nf::ErrorType::SDL);
    if (SDLNet_Init() != 0) nf::fatal_error_sdl("sdl net initialization error", nf::ErrorType::SDL_NET);
  }

  void
  _terminate()
  {
    SDLNet_Quit();
    SDL_Quit();
  }
}

int
main()
{
  _initialize();

  nf::Screen screen("wifi-screen", 640, 480);
  nf::Network network(54321);

  bool run = true;
  while (run) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_QUIT: run = false; break;
      }
    }

    network.receive_data();
  }

  _terminate();
}
