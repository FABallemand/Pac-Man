#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <SDL.h>

#include "display_utils.h"

class Object
{
protected:
    Object() : position_{0, 0, 0, 0}
    {
    }

    Object(int x, int y) : position_{x, y, 0, 0}
    {
    }

    virtual ~Object()
    {
    }

public:
    inline int getX() const
    {
        return position_.x;
    }

    inline int getY() const
    {
        return position_.y;
    }

    inline int getW() const
    {
        return position_.w;
    }

    inline int getH() const
    {
        return position_.h;
    }

    virtual void display() const = 0;

protected:
    SDL_Rect position_; //!< Board coordinates (x, y) and dimensions (w, h) SDL_Point ???
};

#endif