#ifndef __MOVEABLE_H__
#define __MOVEABLE_H__

#define NUM_DIRECTION 4
#define NUM_SPRITE 2

#include <array>

#include "object.h"

/**
 * \enum Direction
 * \brief Orientation of Pac-Man relatively to the screen
 */
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Moveable : public Object
{
public:
    inline Direction getDirection() const
    {
        return direction_;
    }

    inline void setDirection(const Direction direction)
    {
        direction_ = direction;
    }

    void display();

protected:
    Direction direction_;                                                        //!< Direction of the object
    std::array<std::array<SDL_Rect, NUM_SPRITE>, NUM_DIRECTION> moving_sprites_; //!< Sprites location
};

#endif