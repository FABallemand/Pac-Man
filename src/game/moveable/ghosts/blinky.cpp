#include "blinky.h"

Blinky::Blinky() : Ghost{0, 0} // Temporary
{
    moving_sprites_ = {{{SDL_Rect{3, 123, GHOST_W, GHOST_H}, SDL_Rect{20, 123, GHOST_W, GHOST_H}}, {SDL_Rect{37, 123, GHOST_W, GHOST_H}, SDL_Rect{54, 123, GHOST_W, GHOST_H}}, {SDL_Rect{71, 123, GHOST_W, GHOST_H}, SDL_Rect{88, 123, GHOST_W, GHOST_H}}, {SDL_Rect{105, 123, GHOST_W, GHOST_H}, SDL_Rect{122, 123, GHOST_W, GHOST_H}}}};
}

void Blinky::strategy()
{
    LOG(DEBUG) << "Blinky::strategy";
}