#ifndef __GHOST_H__
#define __GHOST_H__

#include "moveable.h"

class Ghost : public Moveable
{
public:
protected:
    std::array<SDL_Rect, 4> eatable_sprites_ = {SDL_Rect{3,195,16,16},SDL_Rect{20,195,16,16},SDL_Rect{37,195,16,16},SDL_Rect{54,195,16,16}}; //!< Sprites location
    std::array<SDL_Rect, 4> eaten_sprites_ = {SDL_Rect{71,195,16,16},SDL_Rect{89,195,16,16},SDL_Rect{105,195,16,16},SDL_Rect{122,195,16,16}};   //!< Sprites location
};

#endif