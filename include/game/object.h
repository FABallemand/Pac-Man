#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <SDL.h>

#include "const.h"
#include "logger.h"

/**
 * \enum ObjectType
 * \brief Represents the type of an object
 *
 */
enum ObjectType
{
    UNDEFINED = 0,
    PACMAN = 1,
    GHOST = 2,
    GOMME = 3,
    SUPER_GOMME,
    FRUIT,
    CELL
};

/**
 * \class Object
 * \brief Abstract class used to represent every object in the game
 *
 */
class Object
{
protected:
    Object() : object_type_{UNDEFINED} // Used by Board type
    {
    }

    Object(ObjectType object_type, int x, int y, int w, int h, SDL_Rect *current_sprite = nullptr) : object_type_{object_type}, position_{x, y, w, h}, current_sprite_{current_sprite}
    {
    }

    void fillObject(ObjectType object_type, int x, int y, int w, int h, SDL_Rect *sprite)
    {
        object_type_ = object_type;
        position_.x = x;
        position_.y = y;
        position_.w = w;
        position_.h = h;
        current_sprite_ = sprite;
    }

public:
    virtual ~Object()
    {
    }

    int getX() const
    {
        return position_.x;
    }

    void setX(int x)
    {
        position_.x = x;
    }

    int getY() const
    {
        return position_.y;
    }

    void setY(int y)
    {
        position_.y = y;
    }

    int getW() const
    {
        return position_.w;
    }

    int getH() const
    {
        return position_.h;
    }

    int getI() const
    {
        return position_.y / gconst::object::cell::size;
    }

    int getJ() const
    {
        return position_.x / gconst::object::cell::size;
    }

    ObjectType getType() const
    {
        return object_type_;
    }

    /**
     * \brief Compare to objects relatively to their type et position
     *
     * \remark Required to use std::find
     * \warning Should not be used with moveable objects
     *
     * \param o Object
     * \return true If objects are equal
     * \return false If object are not equal
     */
    bool operator==(Object o) const
    {
        return object_type_ == o.object_type_ && position_.x == o.position_.x && position_.y == o.position_.y;
    }

    /**
     * \brief Display object
     *
     * \param sprite Sprite containing object sprites
     * \param window_surface Surface to draw on
     */
    void display(SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL (position_)

protected:
    // General ================================================================
    ObjectType object_type_; //!< Type
    SDL_Rect position_;      //!< Board coordinates (x, y) and dimensions (w, h)
    // Display ================================================================
    SDL_Rect *current_sprite_ = nullptr; //!< Current sprite
    static SDL_Rect dead_sprite_;        //!< Dead sprite
};

#endif