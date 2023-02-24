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

// Logger
LogConf LOGGER_CONFIG;

int main(int argc, char **argv)
{
    // Init SDL
    initSDL(window, window_surface, "Pac-Man", screen_width, screen_height, false);

    // Load assets
    // loadAssets(sprite);
    if ((sprite = SDL_LoadBMP("../assets/img/pacman_sprites.bmp")) == nullptr)
    {
        LOG(ERROR) << "Failed to load assets";
        exit(1);
    }
    if (sprite == nullptr)
    {
        LOG(ERROR) << "WTF 1";
    }

    // New game
    Game game{};

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
        if (sprite == nullptr)
        {
            LOG(ERROR) << "WTF 2";
        }
        game.display(sprite, window_surface);

        // Frame rate 60 FPS
        SDL_Delay(16); // use SDL_GetTicks64() => precision
    }

    // Quit SDL
    quitSDL(window, window_surface);

    return 0;
}
