#include "pac_man.h"
#include "cell.h"

SDL_Rect PacMan::initial_sprite_{3, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1};

PacManDyingSprites PacMan::dying_sprites_{SDL_Rect{3, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{22, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{41, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{60, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{79, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{98, 106, 16, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{115, 106, 12, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{128, 106, 8, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{137, 106, 4, gconst::object::moveable::pacman::size_s1},
                                          SDL_Rect{142, 106, 13, gconst::object::moveable::pacman::size_s1}};

PacMan::PacMan() : Moveable{PACMAN, 0, 0, gconst::object::moveable::pacman::size, gconst::object::moveable::pacman::size, gconst::object::moveable::pacman::speed, &initial_sprite_}
{
    moving_sprites_ = {{{SDL_Rect{47, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, /*SDL_Rect{63, 89, gconst::object::moveable::pacman::size_s2, gconst::object::moveable::pacman::size_s1},*/ SDL_Rect{3, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}},     // Left
                        {SDL_Rect{20, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, /*SDL_Rect{35, 89, gconst::object::moveable::pacman::size_s2, gconst::object::moveable::pacman::size_s1},*/ SDL_Rect{3, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}},     // Right
                        {SDL_Rect{75, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, /*SDL_Rect{92, 94, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s2},*/ SDL_Rect{3, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}},     // Up
                        {SDL_Rect{109, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, /*SDL_Rect{126, 94, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s2},*/ SDL_Rect{3, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}}}}; // Down
    initial_position_ = {20, 10};
}

void PacMan::update(const Uint8 *key_state, const float delta_t)
{
    if(state_ == PACMAN_ALIVE)
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
        state_ = PACMAN_DYING;
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
        else if ((position_.y > neighborhood_[1][1]->getY() + gconst::object::cell::size / 3) && !neighborhood_[0][0]->isWall())
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
        else if ((position_.y < neighborhood_[1][1]->getY() + gconst::object::cell::size / 3) && !neighborhood_[2][0]->isWall())
        {
            direction_ = LEFT;
            action_direction_ = DOWN_LEFT;
        }
        break;
    default:
        LOG(ERROR) << "ERROR : DEFAULT";
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
        else if ((position_.y > neighborhood_[1][1]->getY() + gconst::object::cell::size / 3) && !neighborhood_[0][2]->isWall())
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
        else if ((position_.y < neighborhood_[1][1]->getY() + gconst::object::cell::size / 3) && !neighborhood_[2][2]->isWall())
        {
            direction_ = RIGHT;
            action_direction_ = DOWN_RIGHT;
        }
        break;
    default:
        LOG(ERROR) << "ERROR : DEFAULT";
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
        else if ((position_.x < neighborhood_[1][1]->getX() + gconst::object::cell::size / 3) && !neighborhood_[0][0]->isWall())
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
        else if ((position_.x > neighborhood_[1][1]->getX() + gconst::object::cell::size / 3) && !neighborhood_[0][2]->isWall()) // UP_RIGHT
        {
            direction_ = UP;
            action_direction_ = UP_RIGHT;
        }
        break;
    case DOWN:
        direction_ = UP;
        action_direction_ = UP;
        break;
    default:
        LOG(ERROR) << "ERROR : DEFAULT";
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
        else if ((position_.x < neighborhood_[1][1]->getX() + gconst::object::cell::size / 3) && !neighborhood_[2][0]->isWall())
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
        else if ((position_.x > neighborhood_[1][1]->getX() + gconst::object::cell::size / 3) && !neighborhood_[2][2]->isWall())
        {
            direction_ = DOWN;
            action_direction_ = DOWN_RIGHT;
        }
        break;
    case UP:
        direction_ = DOWN;
        action_direction_ = DOWN;
        break;
    default:
        LOG(ERROR) << "ERROR : DEFAULT";
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
    if (position_.x >= gconst::window::w - gconst::object::moveable::pacman::size)
    {
        position_.w = 0;
        position_.h = 0;
    }
    else
    {
        position_.w = gconst::object::moveable::pacman::size;
        position_.h = gconst::object::moveable::pacman::size;
    }
}

void PacMan::move()
{
    allowed_to_move_ = false;
    switch (action_direction_)
    {
    case LEFT:
        if (position_.x > neighborhood_[1][1]->getX() || !neighborhood_[1][0]->isWall())
        {
            position_.x -= round(speed_ * delta_t_);
            handleShortcut();
            position_.y = neighborhood_[1][1]->getY();
            allowed_to_move_ = true;
        }
        break;
    case RIGHT:
        if (position_.x < neighborhood_[1][1]->getX() || !neighborhood_[1][2]->isWall())
        {
            position_.x += round(speed_ * delta_t_);
            handleShortcut();
            position_.y = neighborhood_[1][1]->getY();
            allowed_to_move_ = true;
        }
        break;
    case UP:
        if (position_.y > neighborhood_[1][1]->getY() || !neighborhood_[0][1]->isWall())
        {
            position_.x = neighborhood_[1][1]->getX();
            position_.y -= round(speed_ * delta_t_);
            allowed_to_move_ = true;
        }
        break;
    case DOWN:
        if (position_.y < neighborhood_[1][1]->getY() || !neighborhood_[2][1]->isWall())
        {
            position_.x = neighborhood_[1][1]->getX();
            position_.y += round(speed_ * delta_t_);
            allowed_to_move_ = true;
        }
        break;
    case UP_LEFT:
        position_.x = neighborhood_[0][0]->getX();
        position_.y = neighborhood_[0][0]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == UP)
            position_.y += gconst::object::moveable::pacman::move_diag_offset;
        else
            position_.x += gconst::object::moveable::pacman::move_diag_offset;
        break;
    case UP_RIGHT:
        position_.x = neighborhood_[0][2]->getX();
        position_.y = neighborhood_[0][2]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == UP)
            position_.y += gconst::object::moveable::pacman::move_diag_offset;
        else
            position_.x -= gconst::object::moveable::pacman::move_diag_offset;
        break;
    case DOWN_LEFT:
        position_.x = neighborhood_[2][0]->getX();
        position_.y = neighborhood_[2][0]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == DOWN)
            position_.y -= gconst::object::moveable::pacman::move_diag_offset;
        else
            position_.x += gconst::object::moveable::pacman::move_diag_offset;
        break;
    case DOWN_RIGHT:
        position_.x = neighborhood_[2][2]->getX();
        position_.y = neighborhood_[2][2]->getY();
        action_direction_ = direction_; // move function uses action_direction_ in a switch
        if (direction_ == DOWN)
            position_.y -= gconst::object::moveable::pacman::move_diag_offset;
        else
            position_.x -= gconst::object::moveable::pacman::move_diag_offset;
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
    case PACMAN_ALIVE:
        if (direction_ != NONE)
        {
            if (allowed_to_move_ == false)
            {
                sprite_count_ = 0; // Pac-Man is stuck against the wall with his mouth open
            }
            else if (++frame_count_ == gconst::object::moveable::nb_sprite_frame)
            {
                frame_count_ = 0;
                sprite_count_ = (++sprite_count_) % gconst::object::moveable::pacman::nb_moving_sprites;
            }
            current_sprite_ = &(moving_sprites_[direction_][sprite_count_]);
        }
        break;
    case PACMAN_DYING:
        if (sprite_count_ < gconst::object::moveable::pacman::nb_dying_sprites)
        {
            current_sprite_ = &(dying_sprites_[sprite_count_++]);
        }
        else
        {
            current_sprite_ = &dead_sprite_;
            state_ = PACMAN_DEAD;
        }
        break;
    case PACMAN_DEAD:
        break;
    default:
        LOG(ERROR) << "updateSprite: Invalid state for PacMan object";
        break;
    }
}

void PacMan::respawn()
{
    state_ = PACMAN_ALIVE;
    direction_ = NONE;
    action_direction_ = NONE;
    input_direction_ = NONE;
    position_.x = initial_position_.second * gconst::object::cell::size;
    position_.y = initial_position_.first * gconst::object::cell::size;
    fixDimensions();
    sprite_count_ = 0;
    current_sprite_ = &(initial_sprite_);
}