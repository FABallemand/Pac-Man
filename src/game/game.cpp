#include "game.h"

void Game::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    LOG(DEBUG) << "Game::display";

    // Background
    if (SDL_SetColorKey(sprite, false, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }
    SDL_BlitScaled(sprite, &(bg_[NORMAL]), window_surface, nullptr);
}