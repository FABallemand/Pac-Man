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
    GHOST,
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

    Object(ObjectType type, int x, int y, int w, int h, SDL_Rect *current_sprite = nullptr) : object_type_{type}, position_{x, y, w, h}, current_sprite_{current_sprite}
    {
    }

public:
    virtual ~Object()
    {
    }

    int getX() const
    {
        return position_.x;
    }

    void setX()
    {
        position_.x = 66;
    }

    int getY() const
    {
        return position_.y;
    }

    int getW() const
    {
        return position_.w;
    }

    int getH() const
    {
        return position_.h;
    }

    bool operator==(Object o) const
    {
        return object_type_ == o.object_type_ && position_.x == o.position_.x && position_.y == o.position_.y;
    }

    ObjectType getType() const
    {
        return object_type_;
    }

    void display(SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL (position_)

protected:
    ObjectType object_type_;                      //!< Type
    SDL_Rect position_;                           //!< Board coordinates (x, y) and dimensions (w, h)
    SDL_Rect *current_sprite_ = nullptr;          //!< Current sprite
    SDL_Rect dead_sprite_ = SDL_Rect{0, 0, 1, 1}; //!< Dead sprite
};

#endif