#include "inky.h"

Inky::Inky() : Ghost{0, 0, "Inky"}
{
    moving_sprites_ = {{{SDL_Rect{37, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{3, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{71, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}},
                        {SDL_Rect{105, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 159, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
    scatter_position_ = {25, 20};
    initial_position_ = {13, 9};
}