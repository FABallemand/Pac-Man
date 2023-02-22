#include "SDL_utils.h"

bool initSDL(SDL_Window *window, SDL_Surface *window_surface, char *window_name, int screen_width, int screen_height, bool resizable)
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        LOG(ERROR) << "SDL could not initialize! SDL Error: " << SDL_GetError();
        success = false;
    }
    else
    {
        window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, resizable ? SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE : SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            LOG(ERROR) << "Window could not be created! SDL Error: " << SDL_GetError();
            success = false;
        }
    }
    return success;
}

void quitSDL(SDL_Window *window, SDL_Surface *window_surface)
{
    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    if (window_surface != nullptr)
    {
        SDL_FreeSurface(window_surface);
        window_surface = nullptr;
    }

    // Quit SDL
    SDL_Quit();
}