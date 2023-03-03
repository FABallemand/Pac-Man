#ifndef __MOVEABLE_H__
#define __MOVEABLE_H__

#include <array>

#include "object.h"

class Cell; // Forward declaration

using MovingSprites = std::array<std::array<SDL_Rect, NB_MOVING_SPRITE>, NB_DIRECTION>;

/**
 * \eNB Direction
 * \brief Orientation of Pac-Man relatively to the screen
 */
enum Direction
{
    LEFT,
    RIGHT,
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
    int frame_count_ = 0;                //!< Frame count
    int sprite_count_ = 0;               //!< Sprite count (for animation)
    MovingSprites moving_sprites_;       //!< Sprites location
    Cell *current_cell_;                 //!< Current cell

    /**
     * \brief Indicate whether a movement is legal or not
     *
     * \param direction Direction in which to move
     * \return true If Object is allowed to move in this direction
     * \return false If Object is not allowed to move in this direction
     */
    virtual bool allowedToMove(Direction direction) = 0;
};

#endif