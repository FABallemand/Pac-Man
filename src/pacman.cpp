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
    initSDL(window, window_surface, "Pac-Man", CELL_SIZE * NB_COLUMNS, CELL_SIZE * NB_ROWS, false);

    // Load assets
    loadAssets(sprite);

    // New game
    LOG(GAME) << "Entering the game";
    Game game{};

    // Timer
    Timer Timer;
    Timer.start();

    // FPS
    Uint64 frame_start_time, frame_end_time;
    int counted_frames = 0;

    // Main loop
    bool quit = false;
    while (!quit)
    {
        LOG(INFO) << "NEW FRAME";
        frame_start_time = SDL_GetTicks64();
        frame_end_time = frame_start_time + FRAME_DELAY;

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
        const Uint8 *key_state = SDL_GetKeyboardState(nullptr);
        if (key_state[SDL_SCANCODE_ESCAPE])
        {
            quit = true;
        }

        // Calculate and correct fps
        float avgFPS = counted_frames / (Timer.getTicks() / 1000.f); // Timer.getTicks() / 1000.f = current_time
        if (avgFPS > 2000000)
        {
            avgFPS = 0;
        }
        LOG(INFO) << "FPS: " << avgFPS;

        // Update game
        quit = quit ? quit : game.update(key_state);

        // Display
        game.display(sprite, window_surface);

        // Update window
        if (SDL_UpdateWindowSurface(window) != 0)
        {
            LOG(ERROR) << "Window could not be updated! SDL Error: " << SDL_GetError();
            exit(1);
        }

        counted_frames++;
        while (SDL_GetTicks64() < frame_end_time)
            ;
    }

    LOG(GAME) << "Quitting the game";

    SDL_Delay(500); // Delay

    // Unload assets
    unloadAssets(sprite);

    // Quit SDL
    quitSDL(window, window_surface);

    return 0;
}
