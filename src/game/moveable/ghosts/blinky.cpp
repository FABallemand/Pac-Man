#include "blinky.h"

Blinky::Blinky() : Ghost{0, 0, gconst::object::moveable::ghost::blinky_speed, "Blinky"}
{
    moving_sprites_ = {{{SDL_Rect{37, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{3, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{71, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{105, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
    scatter_position_ = {1, 19};
    initial_position_ = {12, 10};
}

Direction Blinky::chase(std::pair<int, int> target_position, Direction target_direction)
{
    return find_path_(ghost_board_, {getI(), getJ()}, target_position);
}