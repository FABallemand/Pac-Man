#include "blinky.h"

Blinky::Blinky() : Ghost{0, 0} // Temporary
{
    moving_sprites_ = {{{SDL_Rect{3, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{20, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}, {SDL_Rect{37, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{54, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}, {SDL_Rect{71, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{88, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}, {SDL_Rect{105, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}, SDL_Rect{122, 123, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}}};
}