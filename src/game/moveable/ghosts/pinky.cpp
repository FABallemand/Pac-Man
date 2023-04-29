#include "pinky.h"

Pinky::Pinky() : Ghost{0, 0, "Pinky"}
{
    moving_sprites_ = {{{SDL_Rect{3, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}, {SDL_Rect{37, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}, {SDL_Rect{71, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}, {SDL_Rect{105, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 141, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
}