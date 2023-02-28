#include "clyde.h"

Clyde::Clyde() : Ghost{0, 0}
{
    moving_sprites_ = {{{SDL_Rect{3, 177, GHOST_W, GHOST_H}, SDL_Rect{20, 177, GHOST_W, GHOST_H}}, {SDL_Rect{37, 177, GHOST_W, GHOST_H}, SDL_Rect{54, 177, GHOST_W, GHOST_H}}, {SDL_Rect{71, 177, GHOST_W, GHOST_H}, SDL_Rect{88, 177, GHOST_W, GHOST_H}}, {SDL_Rect{105, 177, GHOST_W, GHOST_H}, SDL_Rect{122, 177, GHOST_W, GHOST_H}}}};
}

void Clyde::strategy()
{
    LOG(DEBUG) << "Clyde::strategy";
}