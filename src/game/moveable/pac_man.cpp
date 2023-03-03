#include "pac_man.h"

PacMan::PacMan(int x, int y) : Moveable{x, y, CELL_SIZE, CELL_SIZE, &initial_sprite_, NONE}
{
    moving_sprites_ = {{{SDL_Rect{47, 89, PACMAN_W, PACMAN_H}, SDL_Rect{63, 89, PACMAN_W, PACMAN_H}, SDL_Rect{3, 89, PACMAN_W, PACMAN_H}},     // Left
                        {SDL_Rect{20, 89, PACMAN_W, PACMAN_H}, SDL_Rect{35, 89, PACMAN_W, PACMAN_H}, SDL_Rect{3, 89, PACMAN_W, PACMAN_H}},     // Right
                        {SDL_Rect{75, 89, PACMAN_W, PACMAN_H}, SDL_Rect{92, 89, PACMAN_W, PACMAN_H}, SDL_Rect{3, 89, PACMAN_W, PACMAN_H}},     // Up
                        {SDL_Rect{109, 89, PACMAN_W, PACMAN_H}, SDL_Rect{126, 89, PACMAN_W, PACMAN_H}, SDL_Rect{3, 89, PACMAN_W, PACMAN_H}}}}; // Down
}

void PacMan::update(const Uint8 *key_state)
{
    LOG(DEBUG) << "PacMan::update";

    // Handle user input
    handleUserInputs(key_state);

    // Game movement
    move();

    // Update sprite
    if (direction_ != NONE)
    {
        if (++frame_count_ == NB_SPRITE_FRAME)
        {
            frame_count_ = 0;
            sprite_count_ = (++sprite_count_) % NB_MOVING_SPRITE;
        }
        current_sprite_ = &(moving_sprites_[direction_][sprite_count_]);
    }
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
}

bool PacMan::allowedToMove(Direction direction)
{
    return true;
}

void PacMan::move()
{
    if (direction_ == RIGHT && allowedToMove(RIGHT))
    {
        position_.x += PACMAN_SPEED;
    }
    else if (direction_ == LEFT && allowedToMove(LEFT))
    {
        position_.x -= PACMAN_SPEED;
    }
    else if (direction_ == UP && allowedToMove(UP))
    {
        position_.y -= PACMAN_SPEED;
    }
    else if (direction_ == DOWN && allowedToMove(DOWN))
    {
        position_.y += PACMAN_SPEED;
    }
}