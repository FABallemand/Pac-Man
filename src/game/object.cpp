#include "object.h"

SDL_Rect Object::dead_sprite_ = SDL_Rect{0, 0, 1, 1};

void Object::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    if (SDL_SetColorKey(sprite, SDL_TRUE, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }
    SDL_BlitScaled(sprite, current_sprite_, window_surface, &position_);

    // For testing purpose
    if (object_type_ == GHOST)
    {
        SDL_Rect test1{position_.x, position_.y, 4, position_.h};
        SDL_FillRect(window_surface, &test1, 255);
        SDL_Rect test2{position_.x, position_.y, 4, 25};
        SDL_FillRect(window_surface, &test2, 255);
    }
}