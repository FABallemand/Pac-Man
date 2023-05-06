#include "ghost.h"

GhostSpecialSprites Ghost::eatable_sprites_ = {SDL_Rect{20, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                               SDL_Rect{3, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                               SDL_Rect{37, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                               SDL_Rect{54, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}};

GhostSpecialSprites Ghost::eaten_sprites_ = {SDL_Rect{89, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                             SDL_Rect{71, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                             SDL_Rect{105, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                             SDL_Rect{122, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}};

void Ghost::update(const float delta_t, int target_i, int target_j, Direction direction)
{
    LOG(DEBUG) << name_ << " : POSITION = (" << getI() << "," << getJ() << ")(" << position_.x << "," << position_.y << ")";
    // No movement during respawn
    if (state_ == GHOST_STOP)
    {
        return;
    }

    // Remember delta_t
    delta_t_ = delta_t;

    // Reset ghost when back at initial position
    if (state_ == GHOST_EATEN && getI() == initial_position_.first && getJ() == initial_position_.second)
    {
        state_ = GHOST_DEFAULT;
    }

    // Handle strategy
    if (getY() % gconst::object::cell::size == 0 && getX() % gconst::object::cell::size == 0)
    {
        strategy(target_i, target_j, direction);
    }

    // Handle movement
    handleMovement();

    // Update sprite
    updateSprite();
}

void Ghost::respawn()
{
    state_ = GHOST_DEFAULT;
    direction_ = NONE;
    action_direction_ = NONE;
    position_.x = initial_position_.second * gconst::object::cell::size;
    position_.y = initial_position_.first * gconst::object::cell::size;
    fixDimensions();
    sprite_count_ = 0;
    current_sprite_ = &(moving_sprites_[0][0]);
}

void Ghost::loadSimpleMaze()
{
    // Open file
    std::ifstream level{"../assets/level/maze.lvl", std::ios::in};

    if (level.is_open())
    {
        int row = 0;
        std::string line;
        const std::string delimiter = ",";
        while (std::getline(level, line))
        {
            size_t start_pos = 0;
            size_t end_pos;
            int col = 0;
            while ((end_pos = line.find(delimiter, start_pos)) != std::string::npos)
            {
                int cell_type = std::stoi(line.substr(start_pos, end_pos));
                ghost_board_[row][col] = cell_type == 3 ? 1 : 0; // Keep only walls
                start_pos = end_pos + delimiter.length();
                ++col;
            }
            ++row;
        }
    }
    else
    {
        LOG(ERROR) << "Unable to open level file";
    }

    // Close file
    level.close();
}

void Ghost::strategy(int target_i, int target_j, Direction target_direction)
{
    switch (state_)
    {
    case GHOST_DEFAULT:
        action_direction_ = chase({target_i, target_j}, target_direction);
        break;
    case GHOST_VULNERABLE:
        action_direction_ = find_path_(ghost_board_, {getI(), getJ()}, scatter_position_);
        break;
    case GHOST_VULNERABLE_BLINK:
        action_direction_ = find_path_(ghost_board_, {getI(), getJ()}, scatter_position_);
        break;
    case GHOST_EATEN:
        action_direction_ = find_path_(ghost_board_, {getI(), getJ()}, initial_position_);
        break;
    default:
        LOG(ERROR) << "Invalid state";
    }
}

void Ghost::followPath()
{
    // Go in the same direction
    if ((direction_ == LEFT && (getI() == 13 || ghost_board_[getI()][getJ() - 1] == 0)) || (direction_ == RIGHT && (getI() == 13 || ghost_board_[getI()][getJ() + 1] == 0)) ||
        (direction_ == UP && ghost_board_[getI() - 1][getJ()] == 0) || (direction_ == DOWN && ghost_board_[getI() + 1][getJ()] == 0))
    {
        return;
    }

    // Change direction
    if ((getI() == 13 || ghost_board_[getI()][getJ() - 1] == 0) && direction_ != RIGHT)
    {
        direction_ = LEFT;
    }
    if ((getI() == 13 || ghost_board_[getI()][getJ() + 1] == 0) && direction_ != LEFT)
    {
        direction_ = RIGHT;
    }
    if (ghost_board_[getI() - 1][getJ()] == 0 && direction_ != DOWN)
    {
        direction_ = UP;
    }
    if (ghost_board_[getI() + 1][getJ()] == 0 && direction_ != UP)
    {
        direction_ = DOWN;
    }
}

void Ghost::turn()
{
    if (state_ != GHOST_EATEN)
    {
        // Forbid turn-around
        if ((action_direction_ == LEFT && direction_ == RIGHT) || (action_direction_ == RIGHT && direction_ == LEFT) ||
            (action_direction_ == UP && direction_ == DOWN) || (action_direction_ == DOWN && direction_ == UP))
        {
            followPath();
            return;
        }
    }

    direction_ = action_direction_;
}

void Ghost::fixDimensions()
{
    if (position_.x >= gconst::window::w - gconst::object::moveable::ghost::size)
    {
        position_.w = 0;
        position_.h = 0;
    }
    else
    {
        position_.w = gconst::object::moveable::ghost::size;
        position_.h = gconst::object::moveable::ghost::size;
    }
}

void Ghost::move()
{
    switch (direction_)
    {
    case LEFT:
        position_.x -= round(speed_ * delta_t_);
        position_.y = getI() * gconst::object::cell::size;
        if (getI() == 13 && (getJ() < 4 || getJ() > 16))
        {
            LOG(DEBUG) << name_ << " : HANDLE SHORTCUT";
            handleShortcut();
        }
        else if (ghost_board_[getI()][getJ()] == 1)
        {
            position_.x = (getJ() + 1) * gconst::object::cell::size;
        }
        break;
    case RIGHT:
        position_.x += round(speed_ * delta_t_);
        position_.y = getI() * gconst::object::cell::size;
        if (getI() == 13 && (getJ() < 4 || getJ() > 16))
        {
            LOG(DEBUG) << name_ << " : HANDLE SHORTCUT";
            handleShortcut();
        }
        else if (ghost_board_[getI()][getJ()] == 1)
        {
            position_.x = (getJ() - 1) * gconst::object::cell::size;
        }
        break;
    case UP:
        position_.x = getJ() * gconst::object::cell::size;
        position_.y -= round(speed_ * delta_t_);
        if (ghost_board_[getI()][getJ()] == 1)
        {
            position_.y = (getI() + 1) * gconst::object::cell::size;
        }
        break;
    case DOWN:
        position_.x = getJ() * gconst::object::cell::size;
        position_.y += round(speed_ * delta_t_);
        if (ghost_board_[getI()][getJ()] == 1)
        {
            position_.y = (getI() - 1) * gconst::object::cell::size;
        }
        break;
    default:
        LOG(ERROR) << "Ghost pathfinding error";
        break;
    }
}

void Ghost::handleMovement()
{
    // Turn
    turn();

    // Move
    move();
}

void Ghost::updateSprite()
{
    switch (state_)
    {
    case GHOST_DEFAULT:
        if (direction_ != NONE)
        {
            if (++frame_count_ == gconst::object::moveable::nb_sprite_frame)
            {
                frame_count_ = 0;
                sprite_count_ = (++sprite_count_) % gconst::object::moveable::ghost::nb_moving_sprites;
            }
            current_sprite_ = &(moving_sprites_[direction_][sprite_count_]);
        }
        break;
    case GHOST_VULNERABLE:
        if (++frame_count_ == gconst::object::moveable::nb_sprite_frame)
        {
            frame_count_ = 0;
            sprite_count_ = (++sprite_count_) % gconst::object::moveable::ghost::nb_special_sprites;
        }
        current_sprite_ = &(eatable_sprites_[sprite_count_]);
        break;
    case GHOST_VULNERABLE_BLINK:
        if (++frame_count_ == gconst::object::moveable::nb_sprite_frame)
        {
            frame_count_ = 0;
            sprite_count_ = (++sprite_count_) % (2 * gconst::object::moveable::ghost::nb_special_sprites);
        }
        current_sprite_ = &(eatable_sprites_[sprite_count_]);
        break;
    case GHOST_EATEN:
        current_sprite_ = &(eaten_sprites_[direction_]);
        break;
    default:
        LOG(ERROR) << name_ << " | Invalid state";
        break;
    }
}