#ifndef __GHOST_H__
#define __GHOST_H__

#include "moveable.h"

class Ghost : public Moveable
{
public:
protected:
    std::array<SDL_Rect, 4> eatable_sprites_; //!< Sprites location
    std::array<SDL_Rect, 4> eaten_sprites_;   //!< Sprites location
};

#endif