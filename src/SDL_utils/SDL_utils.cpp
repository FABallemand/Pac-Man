#include "SDL_utils.h"

void initSDL(SDL_Window *window, SDL_Surface *window_surface, char *window_name, int window_width, int window_height, bool resizable)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        LOG(ERROR) << "SDL could not initialize! SDL Error: " << SDL_GetError();
        exit(1);
    }
    else
    {
        window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, resizable ? SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE : SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            LOG(ERROR) << "Window could not be created! SDL Error: " << SDL_GetError();
            exit(1);
        }

        window_surface = SDL_GetWindowSurface(window);
        if (window_surface == nullptr)
        {
            LOG(ERROR) << "Window surface could not be retreived! SDL Error: " << SDL_GetError();
            exit(1);
        }
    }
}

void loadAssets(SDL_Surface *sprite)
{
    if ((sprite = SDL_LoadBMP("../assets/img/pacman_sprites.bmp")) == nullptr)
    {
        LOG(ERROR) << "Failed to load assets";
        exit(1);
    }
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