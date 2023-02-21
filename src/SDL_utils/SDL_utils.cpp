#include "SDL_utils.h"

bool initSDL(Window &window, char *window_name, int screen_width, int screen_height, bool resizable)
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    // if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        // printError("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!window.createWindow(window_name, screen_width, screen_height, resizable))
        {
            // printError("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            if (!window.createRenderer())
            {
                // printError("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            // else
            // {
            //     SDL_SetRenderDrawColor(window.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

            //     int imgFlags = IMG_INIT_PNG;
            //     if (!(IMG_Init(imgFlags) & imgFlags))
            //     {
            //         printError("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            //         success = false;
            //     }

            //     if (TTF_Init() == -1)
            //     {
            //         printError("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            //         success = false;
            //     }

            //     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            //     {
            //         printError("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
            //         success = false;
            //     }
            // }
        }
    }
    return success;
}

void quitSDL(Window &window)
{
    window.free();

    //Quit SDL subsystems
    // Mix_Quit();
    // TTF_Quit();
    // IMG_Quit();

    // Quit SDL
    SDL_Quit();
}