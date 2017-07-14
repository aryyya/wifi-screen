#include "SDL.h"
#include "screen.hpp"

void init();

int main() {
  init();

  nf::Screen screen("wifi-screen", 640, 480);

  bool run = true;
  while (run) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_QUIT: run = false; break;
      }
    }
  }
}

void init() {
  SDL_Init(SDL_INIT_VIDEO);
}
