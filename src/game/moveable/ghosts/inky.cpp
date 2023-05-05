#include "inky.h"

Inky::Inky() : Ghost{0, 0, "Inky"}
{
    moving_sprites_ = {{{SDL_Rect{37, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{3, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{71, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{105, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
    scatter_position_ = {25, 19};
    initial_position_ = {13, 9};
}

Direction Inky::chase(std::pair<int, int> target_position, Direction target_direction)
{
    if (target_direction == NONE)
    {
        // Scatter if Pac-Man has not moved yet
        offset_i_ = scatter_position_.first;
        offset_j_ = scatter_position_.second;
        return find_path_(ghost_board_, {getI(), getJ()}, scatter_position_);
    }
    if ((chase_timer_.isStarted() && chase_timer_.getTicks() > gconst::object::moveable::ghost::chase_time) || !chase_timer_.isStarted())
    {
        if (!chase_timer_.isStarted())
        {
            chase_timer_.start();
        }
        offset_i_ = (random() % 9) - 4;
        offset_j_ = (random() % 9) - 4;
        while ((target_position.first + offset_i_ < 1 || target_position.first + offset_i_ > gconst::game::nb_rows - 2) ||
               (target_position.second + offset_j_ < 1 || target_position.second + offset_j_ > gconst::game::nb_columns - 2) ||
               (ghost_board_[target_position.first + offset_i_][target_position.second + offset_j_] == 1))
        {
            // If the cells drew is not valid we redraw till it becomes valide.
            offset_i_ = (random() % 9) - 4;
            offset_j_ = (random() % 9) - 4;
        }
    }
    return find_path_(ghost_board_, {getI(), getJ()}, {target_position.first + offset_i_, target_position.second + offset_j_});
}