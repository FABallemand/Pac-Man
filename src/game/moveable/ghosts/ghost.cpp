#include "ghost.h"

void Ghost::display(SDL_Surface *sprite, SDL_Surface *window_surface) // SAME AS PACMAN??? Move to Object??
{
    LOG(DEBUG) << "Ghost::display";

    if (SDL_SetColorKey(sprite, SDL_TRUE, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }
    SDL_BlitScaled(sprite, current_sprite_, window_surface, &position_);
}

bool Ghost::allowedToMove(Direction direction)
{
    return true;
}