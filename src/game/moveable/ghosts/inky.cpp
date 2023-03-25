#include "inky.h"

Inky::Inky() : Ghost{0, 0}
{
    moving_sprites_ = {{{SDL_Rect{3, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{20, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{37, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{54, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{71, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{88, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}, {SDL_Rect{105, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}, SDL_Rect{122, 159, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size}}}};
}

void Inky::strategy()
{
    LOG(DEBUG) << "Inkyy::strategy";
}