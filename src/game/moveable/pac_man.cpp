#include "pac_man.h"

PacMan::PacMan(int x, int y) : Moveable{x, y, CELLSIZE, CELLSIZE, &initial_sprite_, NONE}
{
    moving_sprites_ = {{{SDL_Rect{47, 89, 15, PACMAN_H}, SDL_Rect{63, 89, 11, PACMAN_H}},     // Left
                        {SDL_Rect{20, 89, 15, PACMAN_H}, SDL_Rect{35, 89, 11, PACMAN_H}},     // Right
                        {SDL_Rect{75, 89, 16, PACMAN_H}, SDL_Rect{92, 89, 16, PACMAN_H}},     // Up
                        {SDL_Rect{109, 89, 16, PACMAN_H}, SDL_Rect{126, 89, 16, PACMAN_H}}}}; // Down
}

void PacMan::handleUserInputs(const Uint8 *key_state)
{
    if (key_state[SDL_SCANCODE_RIGHT] && allowedToMove(RIGHT))
    {
        direction_ = RIGHT;
    }
    else if (key_state[SDL_SCANCODE_LEFT] && allowedToMove(LEFT))
    {
        direction_ = LEFT;
    }
    else if (key_state[SDL_SCANCODE_UP] && allowedToMove(UP))
    {
        direction_ = UP;
    }
    else if (key_state[SDL_SCANCODE_DOWN] && allowedToMove(DOWN))
    {
        direction_ = DOWN;
    }
    else
    {
        return;
    }
    current_sprite_ = &(moving_sprites_[direction_][frame_count_]);
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

bool PacMan::allowedToMove(Direction direction)
{
    return true;
}