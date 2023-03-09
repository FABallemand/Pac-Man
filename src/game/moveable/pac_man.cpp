#include "pac_man.h"
#include "cell.h"

PacMan::PacMan(int x, int y) : Moveable{x, y, PACMAN_W, PACMAN_H, &initial_sprite_}
{
    moving_sprites_ = {{{SDL_Rect{47, 89, S1_PACMAN_W, S1_PACMAN_H},  /*SDL_Rect{63, 89, S2_PACMAN_W, S1_PACMAN_H},  */SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},     // Left
                        {SDL_Rect{20, 89, S1_PACMAN_W, S1_PACMAN_H},  /*SDL_Rect{35, 89, S2_PACMAN_W, S1_PACMAN_H},  */SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},     // Right
                        {SDL_Rect{75, 89, S1_PACMAN_W, S1_PACMAN_H},  /*SDL_Rect{92, 94, S1_PACMAN_W, S2_PACMAN_H},  */SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},     // Up
                        {SDL_Rect{109, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{126, 94, S1_PACMAN_W, S2_PACMAN_H}, */SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}}}}; // Down
}

void PacMan::update(const Uint8 *key_state)
{
    LOG(DEBUG) << "PacMan::update";

    if (state_ == ALIVE)
    {
        // Handle user input
        handleUserInputs(key_state);
        allowedToMove(direction_);
        // Game movement
        move();
    }

    // Update sprite
    updateSprite();
}

void PacMan::handleUserInputs(const Uint8 *key_state)
{
    LOG(DEBUG) << "PacMan::handleUserInputs";
    if (key_state[SDL_SCANCODE_RIGHT])
    {
        direction_ = RIGHT;
    }
    else if (key_state[SDL_SCANCODE_LEFT])
    {
        direction_ = LEFT;
    }
    else if (key_state[SDL_SCANCODE_UP])
    {
        direction_ = UP;
    }
    else if (key_state[SDL_SCANCODE_DOWN])
    {
        direction_ = DOWN;
    }
    else if (key_state[SDL_SCANCODE_K]) // for testing purpose only !!!
    {
        state_ = DYING;
        sprite_count_ = 0;
    }
}

void PacMan::allowedToMove(Direction direction)
{
    if (direction == RIGHT && !neighborhood_[1][2]->isWalled())
    {
        allow_to_move_ = true;
    }
    else if (direction == LEFT && !neighborhood_[1][0]->isWalled())
    {
        allow_to_move_ = true;
    }
    else if (direction == UP && !neighborhood_[0][1]->isWalled())
    {
        allow_to_move_ = true;
    }
    else if (direction == DOWN && !(neighborhood_[2][1]->isWalled()))
    {
        allow_to_move_ = true;
    }
    else
    {
        allow_to_move_ = false;
    }
}

void PacMan::move()
{
    LOG(DEBUG) << "PacMan::move";
    if (direction_ == RIGHT && allow_to_move_)
    {
        position_.x += PACMAN_SPEED;
    }
    else if (direction_ == LEFT && allow_to_move_)
    {
        position_.x -= PACMAN_SPEED;
    }
    else if (direction_ == UP && allow_to_move_)
    {
        position_.y -= PACMAN_SPEED;
    }
    else if (direction_ == DOWN && allow_to_move_)
    {
        position_.y += PACMAN_SPEED;
    }
}

void PacMan::updateSprite()
{
    // Dead
    LOG(DEBUG) << "PacMan::updateSprite";
    if (state_ == DYING)
    {
        // current_sprite_ = sprite_count_ < NB_DYING_SPRITES ? &(dying_sprites_[sprite_count_]) : nullptr;
        if (sprite_count_ < NB_DYING_SPRITES)
        {
            current_sprite_ = &(dying_sprites_[sprite_count_++]);
        }
        else
        {
            current_sprite_ = &dead_sprite_;
            state_ = DEAD;
        }
    }
    else if (state_ == ALIVE)
    {
        // Alive
        if (direction_ != NONE)
        {
            if (allow_to_move_ == false)
            {
                sprite_count_ = 0; //pacman is then sutck against le wall with is mouth open
            }
            else if (++frame_count_ == NB_SPRITE_FRAME)
            {
                frame_count_ = 0;
                sprite_count_ = (++sprite_count_) % NB_MOVING_SPRITES;
            }
            current_sprite_ = &(moving_sprites_[direction_][sprite_count_]);
        }        
    }
    else
    {
        LOG(ERROR) << "Invalid state for PacMan object";
    }
}
