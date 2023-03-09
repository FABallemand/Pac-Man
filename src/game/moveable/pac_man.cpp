#include "pac_man.h"
#include "cell.h"

PacMan::PacMan(int x, int y) : Moveable{x, y, PACMAN_W, PACMAN_H, &initial_sprite_}
{
    moving_sprites_ = {{{SDL_Rect{47, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{63, 89, S2_PACMAN_W, S1_PACMAN_H},  */ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},    // Left
                        {SDL_Rect{20, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{35, 89, S2_PACMAN_W, S1_PACMAN_H},  */ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},    // Right
                        {SDL_Rect{75, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{92, 94, S1_PACMAN_W, S2_PACMAN_H},  */ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},    // Up
                        {SDL_Rect{109, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{126, 94, S1_PACMAN_W, S2_PACMAN_H}, */ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}}}}; // Down
}

void PacMan::update(const Uint8 *key_state)
{
    LOG(DEBUG) << "PacMan::update";

    if (state_ == ALIVE)
    {
        // Handle user input
        handleUserInputs(key_state);

        // Handle movement
        handleMovement();
    }

    // Update sprite
    updateSprite();
}

void PacMan::handleUserInputs(const Uint8 *key_state)
{
    LOG(DEBUG) << "PacMan::handleUserInputs";
    if (key_state[SDL_SCANCODE_RIGHT])
    {
        input_direction_ = RIGHT;
    }
    else if (key_state[SDL_SCANCODE_LEFT])
    {
        input_direction_ = LEFT;
    }
    else if (key_state[SDL_SCANCODE_UP])
    {
        input_direction_ = UP;
    }
    else if (key_state[SDL_SCANCODE_DOWN])
    {
        input_direction_ = DOWN;
    }
    else if (key_state[SDL_SCANCODE_K]) // for testing purpose only !!!
    {
        state_ = DYING;
        sprite_count_ = 0;
    }
}

void PacMan::turn()
{
    if (input_direction_ != direction_) // If user wants to turn
    {
        switch (direction_)
        {
        case NONE:
            LOG(ERROR) << "IMPOSSIBLE";
            break;
        case RIGHT:
            switch (input_direction_)
            {
            case LEFT:
                direction_ = input_direction_;        // Update direction
                action_direction_ = input_direction_; // Update action
                break;
            case UP:
                if (!neighborhood_[0][1]->isWalled()) // UP
                {
                    direction_ = input_direction_; // Update direction
                    action_direction_ = UP;        // Update action
                }
                else if ((position_.x > neighborhood_[1][1]->getX() + CELL_SIZE / 2) && !neighborhood_[0][2]->isWalled()) // UP_RIGHT
                {
                    direction_ = input_direction_; // Update direction
                    action_direction_ = UP_RIGHT;  // Update action
                }
                break;
            case DOWN:
                if (!neighborhood_[2][1]->isWalled() || !neighborhood_[2][2]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            }
            break;
        case LEFT:
            switch (input_direction_)
            {
            case RIGHT:
                direction_ = input_direction_;
                break;
            case UP:
                if (!neighborhood_[0][0]->isWalled() || !neighborhood_[0][1]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            case DOWN:
                if (!neighborhood_[2][0]->isWalled() || !neighborhood_[2][1]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            }
            break;
        case UP:
            switch (input_direction_)
            {
            case RIGHT:
                if (!neighborhood_[1][2]->isWalled() || !neighborhood_[0][2]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            case LEFT:
                if (!neighborhood_[1][0]->isWalled() || !neighborhood_[0][0]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            case DOWN:
                direction_ = input_direction_;
                break;
            }
            break;
        case DOWN:
            switch (input_direction_)
            {
            case RIGHT:
                if (!neighborhood_[1][2]->isWalled() || !neighborhood_[2][2]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            case LEFT:
                if (!neighborhood_[1][0]->isWalled() || !neighborhood_[2][0]->isWalled())
                {
                    direction_ = input_direction_;
                }
                break;
            case UP:
                direction_ = input_direction_;
                break;
            }
            break;
        }
    }
}

void PacMan::align()
{
    // SWITCH
    if (direction_ == RIGHT)
    {
        if (position_.x <= neighborhood_[1][1]->getX() + CELL_SIZE / 2)
        {
            position_.y = neighborhood_[1][1]->getY();
        }
        else
        {
            position_.y = neighborhood_[1][2]->getY();
        }
    }
    else if (direction_ == LEFT)
    {
        if (position_.x > neighborhood_[1][1]->getX() + CELL_SIZE / 2)
        {
            position_.y = neighborhood_[1][1]->getY();
        }
        else
        {
            position_.y = neighborhood_[1][0]->getY();
        }
    }
    else if (direction_ == UP)
    {
        if (position_.y <= neighborhood_[1][1]->getY() + CELL_SIZE / 2)
        {
            position_.x = neighborhood_[1][1]->getX();
        }
        else
        {
            position_.x = neighborhood_[0][1]->getX();
        }
    }
    else if (direction_ == DOWN)
    {
        if (position_.y <= neighborhood_[1][1]->getY() + CELL_SIZE / 2)
        {
            position_.x = neighborhood_[1][1]->getX();
        }
        else
        {
            position_.x = neighborhood_[2][1]->getX();
        }
    }
}

void PacMan::move()
{
    LOG(DEBUG) << "PacMan::move";

    align(); // Align PacMan

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

void PacMan::handleMovement()
{
    // Turn
    turn();

    // Move
    move();
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
                sprite_count_ = 0; // pacman is then sutck against le wall with is mouth open
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
