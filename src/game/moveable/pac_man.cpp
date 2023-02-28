#include "pac_man.h"

PacMan::PacMan()
{
    moving_sprites_ = {{{SDL_Rect{20 ,89 ,15 ,16 }, SDL_Rect{35 ,89 ,11 ,16}}, {SDL_Rect{47,89,15,16}, SDL_Rect{63,89,11,16}},
                        {SDL_Rect{75,89,16,16}, SDL_Rect{92,89,16,16}},{SDL_Rect{109,89,16,16}, SDL_Rect{126,89,16,16}}}};
}

void PacMan::display(SDL_Surface *sprite, SDL_Surface *window_surface) const
{
    LOG(DEBUG) << "PacMan::display";

    if (SDL_SetColorKey(sprite, false, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }

    SDL_Rect t = SDL_Rect{25,25,50,50};
    SDL_BlitScaled(sprite, &(initial_sprite_), window_surface, &t);
}