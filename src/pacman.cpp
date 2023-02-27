#include <SDL.h>

#include <iostream>

#include "SDL_utils.h"
#include "display_utils.h"
#include "game.h"

// Window
SDL_Window *window = nullptr;
SDL_Surface *window_surface = nullptr;
constexpr int screen_width = 700;
constexpr int screen_height = 900;

SDL_Rect full_screen{0, 0, screen_width, screen_height};

// Assets
SDL_Surface *sprite = nullptr;

SDL_Rect test = {200, 3, 168, 216};

// Logger
LogConf LOGGER_CONFIG;

int main(int argc, char **argv)
{
    // Init SDL
    initSDL(window, window_surface, "Pac-Man", screen_width, screen_height, false);

    // Load assets
    loadAssets(sprite);

    // New game
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
        const Uint8 *keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
            puts("LEFT");
        if (keys[SDL_SCANCODE_RIGHT])
            puts("RIGHT");

        // Update game

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

    // Quit SDL
    quitSDL(window, window_surface);

    return 0;
}
