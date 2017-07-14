#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Screen {
  SDL_Window *window;
  SDL_Renderer *renderer;
} Screen;

Screen *screen_new(const char *title, const int width, const int height);
void screen_free(Screen *t);

#endif

