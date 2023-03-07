#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <SDL.h>

#include "const.h"
#include "display_utils.h"

class Object
{
protected:
    Object() : position_{0, 0, 0, 0}, current_sprite_{nullptr}
    {
    }

    Object(int x, int y, int w, int h, SDL_Rect *current_sprite = nullptr) : position_{x, y, w, h}, current_sprite_{current_sprite}
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

    void display(SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL (position_)
protected:
    SDL_Rect position_;                  //!< Board coordinates (x, y) and dimensions (w, h)
    SDL_Rect *current_sprite_ = nullptr; //!< Current sprite

};

#endif