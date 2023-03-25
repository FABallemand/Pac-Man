#ifndef __MOVEABLE_H__
#define __MOVEABLE_H__

#include <array>

#include "object.h"

class Cell; // Forward declaration

using CellNeighborhood = std::array<std::array<Cell *, gconst::object::moveable::neighborhood_size>, gconst::object::moveable::neighborhood_size>;

/**
 * \enum MoveableState
 * \brief Describe the state of a moveable object
 *
 */
enum MoveableState
{
    ALIVE,
    DYING,
    DEAD,
    VULNERABLE
};

using MovingSprites = std::array<std::array<SDL_Rect, gconst::object::moveable::pacman::nb_moving_sprites>, gconst::object::moveable::nb_directions>;

/**
 * \enum Direction
 * \brief Orientation of a moveable object
 *
 * \remark Relative to the screen
 */
enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE, // Only for initial position
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT
};

/**
 * \class Moveable
 * \brief Represents an object that has the ability to move
 *
 */
class Moveable : public Object
{
public:
    Moveable(ObjectType type, int x, int y, int w, int h, SDL_Rect *current_sprite, Direction direction = NONE) : Object{type, x, y, w, h, current_sprite}, direction_{direction}
    {
    }

    MoveableState getState() const
    {
        return state_;
    }

    Direction getDirection() const
    {
        return direction_;
    }

    CellNeighborhood &getNeighborhood()
    {
        return neighborhood_;
    }

    Cell *getCurrentCell()
    {
        return neighborhood_[1][1];
    }

    void setDirection(const Direction direction)
    {
        direction_ = direction;
    }

    void setNeighborhood(CellNeighborhood neighborhood)
    {
        neighborhood_ = neighborhood;
    }

protected:
    MoveableState state_ = ALIVE;   //!< State of the object
    Direction direction_ = NONE;    //!< Direction of the object
    float delta_t_ = 0.0;           //!< Elapsed time since last update
    int frame_count_ = 0;           //!< Frame count
    int sprite_count_ = 0;          //!< Sprite count (for animation)
    MovingSprites moving_sprites_;  //!< Sprites location
    CellNeighborhood neighborhood_; //!< Current cell
    bool allowed_to_move_ = true;   //!< IsPacmanStuck boolean

    /**
     * \brief Turn moveable object on the board
     *
     */
    virtual void turn() = 0;

    /**
     * \brief Move the moveable object on the board
     *
     */
    virtual void move() = 0;

    /**
     * \brief Handle movement of the moveable object
     *
     */
    virtual void handleMovement() = 0;

    /**
     * \brief Update sprite to display
     *
     */
    virtual void updateSprite() = 0;
};

#endif