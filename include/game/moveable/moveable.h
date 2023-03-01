#ifndef __MOVEABLE_H__
#define __MOVEABLE_H__

#define NB_DIRECTION 4
#define NB_SPRITE 2

#include <array>

#include "object.h"

typedef std::array<std::array<SDL_Rect, NB_SPRITE>, NB_DIRECTION> MovingSprites;

/**
 * \eNB Direction
 * \brief Orientation of Pac-Man relatively to the screen
 */
enum Direction
{
    RIGHT,
    LEFT,
    UP,
    DOWN,
    NONE // Only for initial position
};

class Moveable : public Object
{
public:
    Moveable(int x, int y, int w, int h, SDL_Rect *current_sprite, Direction direction = NONE) : Object{x, y, w, h}, current_sprite_{current_sprite}, direction_{direction}
    {
    }

    inline Direction getDirection() const
    {
        return direction_;
    }

    inline void setDirection(const Direction direction)
    {
        direction_ = direction;
    }

protected:
    SDL_Rect *current_sprite_ = nullptr; //!< Current sprite
    Direction direction_ = NONE;         //!< Direction of the object
    MovingSprites moving_sprites_;       //!< Sprites location
};

#endif