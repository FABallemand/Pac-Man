#ifndef __GHOST_H__
#define __GHOST_H__

#include "moveable.h"

#define GHOST_W 16 //!< Ghost width
#define GHOST_H 16 //!< Ghost height

class Ghost : public Moveable
{
public:
    Ghost(int x, int y) : Moveable{x, y, GHOST_W, GHOST_H, &(moving_sprites_[0][0]), NONE}
    {
    }

    virtual void strategy() = 0;

protected:
    std::array<SDL_Rect, 4> eatable_sprites_ = {SDL_Rect{3, 195, GHOST_W, GHOST_H}, SDL_Rect{20, 195, GHOST_W, GHOST_H}, SDL_Rect{37, 195, GHOST_W, GHOST_H}, SDL_Rect{54, 195, GHOST_W, GHOST_H}};  //!< Sprites location
    std::array<SDL_Rect, 4> eaten_sprites_ = {SDL_Rect{71, 195, GHOST_W, GHOST_H}, SDL_Rect{89, 195, GHOST_W, GHOST_H}, SDL_Rect{105, 195, GHOST_W, GHOST_H}, SDL_Rect{122, 195, GHOST_W, GHOST_H}}; //!< Sprites location
};

#endif