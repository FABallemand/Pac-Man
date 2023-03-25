#include "clyde.h"

Clyde::Clyde() : Ghost{0, 0}
{
    moving_sprites_ = {{{SDL_Rect{3, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{20, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{37, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{54, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{71, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{88, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{105, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{122, 177, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}}};
}

void Clyde::strategy()
{
    LOG(DEBUG) << "Clyde::strategy";
}