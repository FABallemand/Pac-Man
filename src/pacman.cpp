#include <SDL.h>
#include <iostream>

#include "const.h"
#include "SDL_utils.h"
#include "display_utils.h"
#include "timer.h"
#include "game.h"

// Window
SDL_Window *window = nullptr;
SDL_Surface *window_surface = nullptr;

// Assets
SDL_Surface *sprite = nullptr;

// Logger
LogConf LOGGER_CONFIG;

int main(int argc, char **argv)
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

    return 0;
}
