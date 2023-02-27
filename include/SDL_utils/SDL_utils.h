#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__

#include <SDL.h>
#include <iostream>

#include "display_utils.h"

/**
 * \brief Initialise SDL
 *
 * \param window SDL window to initialise
 * \param window_surface Surface of the SDL window
 * \param window_name Name of the window
 * \param window_width Width of the window
 * \param window_height Height of the window
 * \param resizable
 */
void initSDL(SDL_Window *&window, SDL_Surface *&window_surface, char *window_name, int window_width, int window_height, bool resizable);

/**
 * \brief Load required game assets
 *
 * \param sprite General sprite containing all required sprites
 */
void loadAssets(SDL_Surface *&sprite);

/**
 * \brief Unload required game assets
 * 
 * \param sprite General sprite containing all required sprites
 */
void unloadAssets(SDL_Surface *&sprite);

/**
 * \brief Quit SDL
 *
 * \param window SDL window to quit
 * \param window_surface Surface of the SDL window
 */
void quitSDL(SDL_Window *&window, SDL_Surface *&window_surface);

#endif