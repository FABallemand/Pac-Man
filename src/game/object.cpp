#include "object.h"

SDL_Rect Object::dead_sprite_ = SDL_Rect{0, 0, 1, 1};

void Object::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    if (SDL_SetColorKey(sprite, SDL_TRUE, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }
    SDL_BlitScaled(sprite, current_sprite_, window_surface, &position_);
}