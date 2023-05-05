#include "pinky.h"

Pinky::Pinky() : Ghost{0, 0, "Pinky"}
{
    moving_sprites_ = {{{SDL_Rect{37, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{3, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{71, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{105, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
    scatter_position_ = {1, 1};
    initial_position_ = {13, 10};
}

Direction Pinky::chase(std::pair<int, int> target_position, Direction target_direction)
{
    int new_target_i, new_target_j;
    switch (target_direction)
    {
    case LEFT:
        new_target_j = std::max(1, target_position.second - 4);
        while (ghost_board_[target_position.first][new_target_j] == 1)
        {
            ++new_target_j;
        }
        LOG(DEBUG) << name_ << " : target = (" << target_position.first << "," << new_target_j << ")";
        return find_path_(ghost_board_, {getI(), getJ()}, {target_position.first, new_target_j}); // ghost_board_ should be a static member of PathFinder
    case RIGHT:
        new_target_j = std::min(gconst::game::nb_columns - 2, target_position.second + 4);
        while (ghost_board_[target_position.first][new_target_j] == 1)
        {
            --new_target_j;
        }
        LOG(DEBUG) << name_ << " : target = (" << target_position.first << "," << new_target_j << ")";
        return find_path_(ghost_board_, {getI(), getJ()}, {target_position.first, new_target_j});
    case UP:
        new_target_i = std::max(1, target_position.first - 4);
        while (ghost_board_[new_target_i][target_position.second] == 1)
        {
            ++new_target_i;
        }
        LOG(DEBUG) << name_ << " : target = (" << new_target_j << "," << target_position.second << ")";
        return find_path_(ghost_board_, {getI(), getJ()}, {new_target_i, target_position.second});
    case DOWN:
        new_target_i = std::min(gconst::game::nb_rows - 2, target_position.first + 4);
        while (ghost_board_[new_target_i][target_position.second] == 1)
        {
            --new_target_i;
        }
        LOG(DEBUG) << name_ << " : target = (" << new_target_j << "," << target_position.second << ")";
        return find_path_(ghost_board_, {getI(), getJ()}, {new_target_i, target_position.second});
    case NONE:
        // Scatter if Pac-Man has not moved yet
        LOG(DEBUG) << name_ << " : scatter";
        return find_path_(ghost_board_, {getI(), getJ()}, scatter_position_);
    }

    // Error
    LOG(ERROR) << name_ << " : Strategy error";
    return NONE;
}