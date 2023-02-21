#include <SDL.h>

#include <iostream>

#include "SDL_utils.h"
#include "display_utils.h"

Window window{};
constexpr int screen_width = 700;
constexpr int screen_height = 900;

structlog LOGGER_CONFIG;

int main(int argc, char **argv)
{
    LOG(INFO) << "PACMAN" << screen_width << "x" << screen_height;
    // Init SDL
    initSDL(window, "Pac-Man", screen_width, screen_height, false);

    // Main loop
    bool quit = false;
    while (!quit)
    {
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
        const Uint8 *keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
            puts("LEFT");
        if (keys[SDL_SCANCODE_RIGHT])
            puts("RIGHT");

        // Update game

        // Display

        // Frame rate 60 FPS
        SDL_Delay(16); // use SDL_GetTicks64() => precision
    }

    // Quit SDL
    quitSDL(window);

    return 0;
}