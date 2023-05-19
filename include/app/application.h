#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <SDL.h>

#include "logger.h"
#include "SDL_utils.h"

#include "const.h"
#include "game.h"

/**
 * \class Application
 * \brief Represents the application that will run the game
 *
 */
class Application
{
public:
    Application()
    {
    }

    void run();

public:
    SDL_Window *window;          //!< Window
    SDL_Surface *window_surface; //!< Window surface
    SDL_Surface *sprite;         //!< Game sprite
};

#endif