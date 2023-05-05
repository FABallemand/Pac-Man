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
    if(target_direction == NONE)
    {
        // Scatter if Pac-Man has not moved yet
        LOG(DEBUG) << name_ << " : scatter";
        return find_path_(ghost_board_, {getI(), getJ()}, scatter_position_);
    }
    long offset_i = (random() % 9) - 4;
    long offset_j = (random() % 9) - 4;
    while((target_position.first+offset_i<1 ||target_position.first+offset_i > gconst::game::nb_rows-2 ) || 
          (target_position.second+offset_j<1 ||target_position.second+offset_j > gconst::game::nb_columns-2)|| 
          (ghost_board_[target_position.first+offset_i][target_position.second+offset_j] == 1))
    {
        //if the cells drew is not valid we redraw till it becomes valide.
        offset_i = (random() % 9) - 4;
        offset_j = (random() % 9) - 4;
    }
    return find_path_(ghost_board_, {getI(), getJ()}, {target_position.first+offset_i,target_position.second+offset_j});
}