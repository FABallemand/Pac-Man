#ifndef __PAC_MAN_H__
#define __PAC_MAN_H__

#include "moveable.h"

class PacMan : public Moveable
{
public:
private:
    std::array<SDL_Rect, 10> dying_sprites_; //!< Sprites location
};

#endif