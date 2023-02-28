#include "inky.h"

Inky::Inky() : Ghost{0, 0}
{
    moving_sprites_ = {{{SDL_Rect{3, 159, GHOST_W, GHOST_H}, SDL_Rect{20, 159, GHOST_W, GHOST_H}}, {SDL_Rect{37, 159, GHOST_W, GHOST_H}, SDL_Rect{54, 159, GHOST_W, GHOST_H}}, {SDL_Rect{71, 159, GHOST_W, GHOST_H}, SDL_Rect{88, 159, GHOST_W, GHOST_H}}, {SDL_Rect{105, 159, GHOST_W, GHOST_H}, SDL_Rect{122, 159, GHOST_W, GHOST_H}}}};
}

void Inky::strategy()
{
    LOG(DEBUG) << "Inkyy::strategy";
}