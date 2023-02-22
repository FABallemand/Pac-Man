#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__

#include <SDL.h>
#include <iostream>

#include "display_utils.h"

bool initSDL(SDL_Window *window, SDL_Surface *window_surface, char *window_name, int screen_width, int screen_height, bool resizable);

void quitSDL(SDL_Window *window, SDL_Surface *window_surface);

#endif