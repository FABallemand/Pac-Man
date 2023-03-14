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

    void run()
    {
        // Init SDL
        initSDL(window, window_surface, (char *)"Pac-Man", CELL_SIZE * NB_COLUMNS, CELL_SIZE * NB_ROWS, false);

        // Load assets
        loadAssets(sprite);

        // New game
        LOG(GAME) << "Entering the game";
        Game game{};

        game.run(window, window_surface, sprite);

        LOG(GAME) << "Quitting the game";

        SDL_Delay(500); // Delay

        // Unload assets
        unloadAssets(sprite);

        // Quit SDL
        quitSDL(window, window_surface);
    }

public:
    SDL_Window *window;          //!< Window
    SDL_Surface *window_surface; //!< Window surface
    SDL_Surface *sprite;         //!< Game sprite
};

#endif