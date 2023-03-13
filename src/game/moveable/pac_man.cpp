#include "pac_man.h"
#include "cell.h"

PacMan::PacMan(int x, int y) : Moveable{PACMAN, x, y, PACMAN_W, PACMAN_H, &initial_sprite_}
{
    moving_sprites_ = {{{SDL_Rect{47, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{63, 89, S2_PACMAN_W, S1_PACMAN_H},*/ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},     // Left
                        {SDL_Rect{20, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{35, 89, S2_PACMAN_W, S1_PACMAN_H},*/ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},     // Right
                        {SDL_Rect{75, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{92, 94, S1_PACMAN_W, S2_PACMAN_H},*/ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}},     // Up
                        {SDL_Rect{109, 89, S1_PACMAN_W, S1_PACMAN_H}, /*SDL_Rect{126, 94, S1_PACMAN_W, S2_PACMAN_H},*/ SDL_Rect{3, 89, S1_PACMAN_W, S1_PACMAN_H}}}}; // Down
}

void PacMan::eat(Object *eatable)
{
}

void PacMan::update(const Uint8 *key_state, const float delta_t)
{
    LOG(DEBUG) << "PacMan::update";

    if (state_ == ALIVE)
    {
        // Remember delta_t
        delta_t_ = delta_t;

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
    else
    {
        input_direction_ = NONE; // To avoid automatic turning
    }
}

void PacMan::turnLeft()
{
    switch (direction_)
    {
    case RIGHT:
        direction_ = LEFT;
        action_direction_ = LEFT;
        break;
    case UP:
        if (!neighborhood_[1][0]->isWall())
        {
            direction_ = LEFT;
            action_direction_ = LEFT;
        }
        else if ((position_.y > neighborhood_[1][1]->getY() + CELL_SIZE / 3) && !neighborhood_[0][0]->isWall())
        {
            direction_ = LEFT;
            action_direction_ = UP_LEFT;
        }
        break;
    case DOWN:
        if (!neighborhood_[1][0]->isWall())
        {
            direction_ = LEFT;
            action_direction_ = LEFT;
        }
        else if ((position_.y < neighborhood_[1][1]->getY() + CELL_SIZE / 3) && !neighborhood_[2][0]->isWall())
        {
            direction_ = LEFT;
            action_direction_ = DOWN_LEFT;
        }
        break;
    }
}

void PacMan::turnRight()
{
    switch (direction_)
    {
    case LEFT:
        direction_ = RIGHT;
        action_direction_ = RIGHT;
        break;
    case UP:
        if (!neighborhood_[1][2]->isWall())
        {
            direction_ = RIGHT;
            action_direction_ = RIGHT;
        }
        else if ((position_.y > neighborhood_[1][1]->getY() + CELL_SIZE / 3) && !neighborhood_[0][2]->isWall())
        {
            direction_ = RIGHT;
            action_direction_ = UP_RIGHT;
        }
        break;
    case DOWN:
        if (!neighborhood_[1][2]->isWall())
        {
            direction_ = RIGHT;
            action_direction_ = RIGHT;
        }
        else if ((position_.y < neighborhood_[1][1]->getY() + CELL_SIZE / 3) && !neighborhood_[2][2]->isWall())
        {
            direction_ = RIGHT;
            action_direction_ = DOWN_RIGHT;
        }
        break;
    }
}

void PacMan::turnUp()
{
    switch (direction_)
    {
    case LEFT:
        if (!neighborhood_[0][1]->isWall())
        {
            direction_ = UP;
            action_direction_ = UP;
        }
        else if ((position_.x < neighborhood_[1][1]->getX() + CELL_SIZE / 3) && !neighborhood_[0][0]->isWall())
        {
            direction_ = UP;
            action_direction_ = UP_LEFT;
        }
        break;
    case RIGHT:
        if (!neighborhood_[0][1]->isWall()) // UP
        {
            direction_ = UP;
            action_direction_ = UP;
        }
        else if ((position_.x > neighborhood_[1][1]->getX() + CELL_SIZE / 3) && !neighborhood_[0][2]->isWall()) // UP_RIGHT
        {
            direction_ = UP;
            action_direction_ = UP_RIGHT;
        }
        break;
    case DOWN:
        direction_ = UP;
        action_direction_ = UP;
        break;
    }
}

void PacMan::turnDown()
{
    switch (direction_)
    {
    case LEFT:
        if (!neighborhood_[2][1]->isWall())
        {
            direction_ = DOWN;
            action_direction_ = DOWN;
        }
        else if ((position_.x < neighborhood_[1][1]->getX() + CELL_SIZE / 3) && !neighborhood_[2][0]->isWall())
        {
            direction_ = DOWN;
            action_direction_ = DOWN_LEFT;
        }
        break;
    case RIGHT:
        if (!neighborhood_[2][1]->isWall())
        {
            direction_ = DOWN;
            action_direction_ = DOWN;
        }
        else if ((position_.x > neighborhood_[1][1]->getX() + CELL_SIZE / 3) && !neighborhood_[2][2]->isWall())
        {
            direction_ = DOWN;
            action_direction_ = DOWN_RIGHT;
        }
        break;
    case UP:
        direction_ = DOWN;
        action_direction_ = DOWN;
        break;
    }
}

void PacMan::turn()
{
    if (direction_ == NONE) // PacMan has no direction (beginning of the game)
    {
        direction_ = input_direction_;
        action_direction_ = input_direction_;
    }
    else if (input_direction_ != direction_) // Player wants to turn
    {
        switch (input_direction_)
        {
        case LEFT:
            turnLeft();
            break;
        case RIGHT:
            turnRight();
            break;
        case UP:
            turnUp();
            break;
        case DOWN:
            turnDown();
            break;
        default:
            LOG(ERROR) << "Invalid input direction";
        }
    }
}

void PacMan::fixDimensions()
{
    if (position_.x >= WINDOW_W - PACMAN_W)
    {
        position_.w = 0;
        position_.h = 0;
    }
    else
    {
        position_.w = PACMAN_W;
        position_.h = PACMAN_H;
    }
}

void PacMan::move()
{
    LOG(DEBUG) << "delta_t_ = " << delta_t_;
    LOG(DEBUG) << "PACMAN_SPEED * delta_t_ = " << PACMAN_SPEED * delta_t_;
    allowed_to_move_ = false;
    switch (action_direction_)
    {
    case LEFT:
        if (position_.x > neighborhood_[1][1]->getX() || !neighborhood_[1][0]->isWall())
        {
            position_.x -= round(PACMAN_SPEED * delta_t_);
            if (position_.x <= 0)
            {
                position_.x = WINDOW_W - 1;
                position_.w = PACMAN_W;
                position_.h = PACMAN_H;
            }
            fixDimensions();
            position_.y = neighborhood_[1][1]->getY();
            allowed_to_move_ = true;
        }
        break;
    case RIGHT:
        if (position_.x < neighborhood_[1][1]->getX() || !neighborhood_[1][2]->isWall())
        {
            position_.x += round(PACMAN_SPEED * delta_t_);
            if (position_.x >= WINDOW_W)
            {
                position_.x = 0;
                position_.w = PACMAN_W;
                position_.h = PACMAN_H;
            }
            fixDimensions();
            position_.y = neighborhood_[1][1]->getY();
            allowed_to_move_ = true;
        }
        break;
    case UP:
        if (position_.y > neighborhood_[1][1]->getY() || !neighborhood_[0][1]->isWall())
        {
            position_.x = neighborhood_[1][1]->getX();
            position_.y -= round(PACMAN_SPEED * delta_t_);
            allowed_to_move_ = true;
        }
        break;
    case DOWN:
        if (position_.y < neighborhood_[1][1]->getY() || !neighborhood_[2][1]->isWall())
        {
            position_.x = neighborhood_[1][1]->getX();
            position_.y += round(PACMAN_SPEED * delta_t_);
            allowed_to_move_ = true;
        }
        break;
    case UP_LEFT:
        position_.x = neighborhood_[0][0]->getX();
        position_.y = neighborhood_[0][0]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == UP)
            position_.y += move_diag_offset_;
        else
            position_.x += move_diag_offset_;
        break;
    case UP_RIGHT:
        position_.x = neighborhood_[0][2]->getX();
        position_.y = neighborhood_[0][2]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == UP)
            position_.y += move_diag_offset_;
        else
            position_.x -= move_diag_offset_;
        break;
    case DOWN_LEFT:
        position_.x = neighborhood_[2][0]->getX();
        position_.y = neighborhood_[2][0]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == DOWN)
            position_.y -= move_diag_offset_;
        else
            position_.x += move_diag_offset_;
        break;
    case DOWN_RIGHT:
        position_.x = neighborhood_[2][2]->getX();
        position_.y = neighborhood_[2][2]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == DOWN)
            position_.y -= move_diag_offset_;
        else
            position_.x -= move_diag_offset_;
        break;
    default:
        break;
    }
}

void PacMan::handleMovement()
{
    // Turn
    if (input_direction_ != NONE) // To avoid automatic turning
    {
        turn();
    }

    // Move
    move();
}

void PacMan::updateSprite()
{
    switch (state_)
    {
    case DYING:
        if (sprite_count_ < NB_DYING_SPRITES)
        {
            current_sprite_ = &(dying_sprites_[sprite_count_++]);
        }
        else
        {
            current_sprite_ = &dead_sprite_;
            state_ = DEAD;
        }
        break;
    case ALIVE:
        if (direction_ != NONE)
        {
            if (allowed_to_move_ == false)
            {
                sprite_count_ = 0; // PacMan is stuck against the wall with his mouth open
            }
            else if (++frame_count_ == NB_SPRITE_FRAME)
            {
                frame_count_ = 0;
                sprite_count_ = (++sprite_count_) % NB_MOVING_SPRITES;
            }
            current_sprite_ = &(moving_sprites_[direction_][sprite_count_]);
        }
        break;
    default:
        LOG(ERROR) << "Invalid state for PacMan object";
        break;
    }
}