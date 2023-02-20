#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__

#include <SDL.h>
#include <iostream>

#include "window.h"
#include "display_utils.h"

/**
 * \brief
 *
 * \param window Reference to the window to initialise
 * \param window_name Name of the window
 * \param screen_width Width of the screen
 * \param screen_height Height of the screen
 * \param resizable Enable window resizing
 * \return true On success
 * \return false If an error occured (corresponding error message in stderr)
 * 
 *  \remark window_name is type char* because the SDL createWindow function requires a char*
 */
bool initSDL(Window &window, char *window_name, int screen_width, int screen_height, bool resizable);

/**
 * \brief Free window and quit SDL (and SDL subsystems)
 *
 * \param window Game window
 */
void quitSDL(Window &window);

#endif