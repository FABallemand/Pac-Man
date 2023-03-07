#ifndef __MOVEABLE_H__
#define __MOVEABLE_H__

#include <array>

#include "object.h"

class Cell; // Forward declaration

/**
 * \enum MoveableState
 * \brief Describe the state of a Moveable object
 *
 */
enum MoveableState
{
    ALIVE,
    DYING,
    DEAD,
    VULNERABLE
};

using MovingSprites = std::array<std::array<SDL_Rect, NB_MOVING_SPRITES>, NB_DIRECTION>;

/**
 * \enum Direction
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
    Moveable(int x, int y, int w, int h, SDL_Rect *current_sprite, Direction direction = NONE) : Object{x, y, w, h, current_sprite}, direction_{direction}
    {
    }

    Direction getDirection() const
    {
        return direction_;
    }

    Cell *getCurrentCell() const
    {
        return current_cell_;
    }

    MoveableState getState() const
    {
        return state_;
    }

    void setDirection(const Direction direction)
    {
        direction_ = direction;
    }

protected:
    MoveableState state_ = ALIVE;  //!< State of the object
    Direction direction_ = NONE;   //!< Direction of the object
    int frame_count_ = 0;          //!< Frame count
    int sprite_count_ = 0;         //!< Sprite count (for animation)
    MovingSprites moving_sprites_; //!< Sprites location
    Cell *current_cell_ = nullptr; //!< Current cell

    /**
     * \brief Indicate whether a movement is legal or not
     *
     * \param direction Direction in which to move
     * \return true If Object is allowed to move in this direction
     * \return false If Object is not allowed to move in this direction
     */
    virtual bool allowedToMove(Direction direction) = 0;

    /**
     * \brief Handle movement of the moveable object
     *
     */
    virtual void move() = 0;
};

#endif