#include "screen.h"

void _fatal_error(const char *message) {
  fprintf(stderr, __FILE__ ": %s\n", message);
  const char *sdl_error = SDL_GetError();
  if (sdl_error[0]) fprintf(stderr, __FILE__ ": %s\n", sdl_error);
  exit(EXIT_FAILURE);
}

Screen *screen_new(const char *title, const int width, const int height) {
  Screen *t = malloc(sizeof (Screen));
  if (t == NULL) _fatal_error("memory allocation error"); 

  if (SDL_WasInit(SDL_INIT_VIDEO) == 0) _fatal_error("sdl video subsystem not initialized");

  t->window = SDL_CreateWindow(
    title,
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width,
    height,
    SDL_WINDOW_SHOWN
  );
  if (t->window == NULL) _fatal_error("sdl window creation error");

  t->renderer = SDL_CreateRenderer(
    t->window,
    -1,
    0
  );
  if (t->renderer == NULL) _fatal_error("sdl renderer creation error");

  return t;
}

void screen_free(Screen *t) {
  SDL_DestroyRenderer(t->renderer);
  SDL_DestroyWindow(t->window);
  free(t);
}

