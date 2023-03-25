#include "pinky.h"

Pinky::Pinky() : Ghost{0, 0}
{

    moving_sprites_ = {{{SDL_Rect{3, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{20, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{37, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{54, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{71, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{88, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{105, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{122, 141, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}}};
}

void Pinky::strategy()
{
    LOG(DEBUG) << "Pinky::strategy";
}