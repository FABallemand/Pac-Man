#include <SDL.h>
#include <iostream>

#include "const.h"
#include "SDL_utils.h"
#include "display_utils.h"
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
    initSDL(window, window_surface, "Pac-Man", WINDOW_W, WINDOW_H, false);

    // Load assets
    loadAssets(sprite);

    // New game
    LOG(GAME) << "Entering the game";
    Game game{};

    // Main loop
    bool quit = false;
    while (!quit)
    {
        LOG(INFO) << "NEW FRAME";

        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        // Keyboard
        int nbk;
        const Uint8 *key_state = SDL_GetKeyboardState(&nbk);
        if (key_state[SDL_SCANCODE_ESCAPE])
        {
            quit = true;
        }

        // Update game
        game.update(key_state);

        // Display
        game.display(sprite, window_surface);

        // Update window
        if (SDL_UpdateWindowSurface(window) != 0)
        {
            LOG(ERROR) << "Window could not be updated! SDL Error: " << SDL_GetError();
            exit(1);
        }

        // Frame rate 60 FPS
        SDL_Delay(16); // use SDL_GetTicks64() => precision
    }

    LOG(GAME) << "Quitting the game";

    // Unload assets
    unloadAssets(sprite);

    // Quit SDL
    quitSDL(window, window_surface);

    return 0;
}
