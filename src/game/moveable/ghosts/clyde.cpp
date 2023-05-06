#include "clyde.h"

Clyde::Clyde() : Ghost{0, 0, gconst::object::moveable::ghost::clyde_speed, "Clyde"}
{
    moving_sprites_ = {{{SDL_Rect{37, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{3, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{71, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{105, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 177, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
    scatter_position_ = {25, 1};
    initial_position_ = {13, 11};
}

Direction Clyde::chase(std::pair<int, int> target_position, Direction target_direction)
{
    int new_target_i, new_target_j;
    switch (target_direction)
    {
    case RIGHT:
        new_target_j = std::max(1, target_position.second - 4);
        for (; new_target_j <= target_position.second; ++new_target_j)
        {
            if (ghost_board_[target_position.first][new_target_j] == 0)
            {
                break;
            }
        }
        return find_path_(ghost_board_, {getI(), getJ()}, {target_position.first, new_target_j});
    case LEFT:
        new_target_j = std::min(gconst::game::nb_columns - 2, target_position.second + 4);
        for (; new_target_j >= target_position.second; --new_target_j)
        {
            if (ghost_board_[target_position.first][new_target_j] == 0)
            {
                break;
            }
        }
        return find_path_(ghost_board_, {getI(), getJ()}, {target_position.first, new_target_j});
    case DOWN:
        new_target_i = std::max(1, target_position.first - 4);
        for (; new_target_i <= target_position.first; ++new_target_i)
        {
            if (ghost_board_[new_target_i][target_position.second] == 0)
            {
                break;
            }
        }
        return find_path_(ghost_board_, {getI(), getJ()}, {new_target_i, target_position.second});
    case UP:
        new_target_i = std::min(gconst::game::nb_rows - 2, target_position.first + 4);
        for (; new_target_i >= target_position.first; --new_target_i)
        {
            if (ghost_board_[new_target_i][target_position.second] == 0)
            {
                break;
            }
        }
        return find_path_(ghost_board_, {getI(), getJ()}, {new_target_i, target_position.second});
    case NONE:
        // Scatter if Pac-Man has not moved yet
        return find_path_(ghost_board_, {getI(), getJ()}, scatter_position_);
    }

    // Error
    LOG(ERROR) << name_ << " : Strategy error";
    return NONE;
}