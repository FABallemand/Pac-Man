#include "pinky.h"

Pinky::Pinky() : Ghost{0, 0}
{

    moving_sprites_ = {{{SDL_Rect{3, 141, GHOST_W, GHOST_H}, SDL_Rect{20, 141, GHOST_W, GHOST_H}}, {SDL_Rect{37, 141, GHOST_W, GHOST_H}, SDL_Rect{54, 141, GHOST_W, GHOST_H}}, {SDL_Rect{71, 141, GHOST_W, GHOST_H}, SDL_Rect{88, 141, GHOST_W, GHOST_H}}, {SDL_Rect{105, 141, GHOST_W, GHOST_H}, SDL_Rect{122, 141, GHOST_W, GHOST_H}}}};
}

void Pinky::strategy()
{
    LOG(DEBUG) << "Pinky::strategy";
}