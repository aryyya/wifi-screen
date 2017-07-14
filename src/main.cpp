#include "SDL.h"
#include "screen.h"
#include <stdbool.h>
#include <stdio.h>

void init();
void term();

int main() {
  init();

  Screen *screen = screen_new("wifi-screen", 640, 480);

  bool run = true;
  while (run) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_QUIT: run = false; break;
      }
    }
  }

  screen_free(screen);

  term();
}

void init() {
  SDL_Init(SDL_INIT_VIDEO);
}

void term() {

}
