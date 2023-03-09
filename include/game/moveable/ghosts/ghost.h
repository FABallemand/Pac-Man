#ifndef __GHOST_H__
#define __GHOST_H__

#include "moveable.h"

using GhostSpecialSprites = std::array<SDL_Rect, NB_DIRECTION>;

class Ghost : public Moveable
{
public:
    Ghost(int x, int y) : Moveable{x, y, GHOST_W, GHOST_H, &(moving_sprites_[0][0]), NONE}
    {
    }

    virtual void strategy() = 0;

protected:
    GhostSpecialSprites eatable_sprites_ = {SDL_Rect{3, 195, S_GHOST_W, S_GHOST_H},
                                            SDL_Rect{20, 195, S_GHOST_W, S_GHOST_H},
                                            SDL_Rect{37, 195, S_GHOST_W, S_GHOST_H},
                                            SDL_Rect{54, 195, S_GHOST_W, S_GHOST_H}}; //!< Sprites location
    GhostSpecialSprites eaten_sprites_ = {SDL_Rect{71, 195, S_GHOST_W, S_GHOST_H},
                                          SDL_Rect{89, 195, S_GHOST_W, S_GHOST_H},
                                          SDL_Rect{105, 195, S_GHOST_W, S_GHOST_H},
                                          SDL_Rect{122, 195, S_GHOST_W, S_GHOST_H}}; //!< Sprites location

    void allowedToMove(Direction direction) override;

    void move();
};

#endif