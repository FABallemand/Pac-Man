#include "pac_man.h"

PacMan::PacMan(int x, int y) : Moveable{x, y, PACMAN_W, PACMAN_H, &initial_sprite_, NONE}
{
    moving_sprites_ = {{{SDL_Rect{20, 89, 15, 16}, SDL_Rect{35, 89, 11, 16}}, {SDL_Rect{47, 89, 15, 16}, SDL_Rect{63, 89, 11, 16}}, {SDL_Rect{75, 89, 16, 16}, SDL_Rect{92, 89, 16, 16}}, {SDL_Rect{109, 89, 16, 16}, SDL_Rect{126, 89, 16, 16}}}};
}

void PacMan::handleUserInputs(const Uint8 *key_state)
{
    if(key_state[SDL_SCANCODE_RIGHT])
    {
        direction_ = RIGHT;
    }
    if(key_state[SDL_SCANCODE_LEFT])
    {
        direction_ = LEFT;
    }
    if(key_state[SDL_SCANCODE_UP])
    {
        direction_ = UP;
    }
    if(key_state[SDL_SCANCODE_DOWN])
    {
        direction_ = DOWN;
    }
    current_sprite_ = &(moving_sprites_[direction_][0]);
}

void PacMan::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    LOG(DEBUG) << "PacMan::display";

    if (SDL_SetColorKey(sprite, SDL_TRUE, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }

    SDL_BlitScaled(sprite, current_sprite_, window_surface, &position_);
}