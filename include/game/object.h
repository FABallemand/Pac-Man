#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <SDL.h>

#include "texture.h"
#include "display_utils.h"

/**
 * \enum Direction
 * \brief Orientation of the object relatively to the screen
 */
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UNKNOWN
};

class Object
{
public:
    Object();

    Object(int x, int y, int w, int h, Direction direction, std::string texture_path, Window &window);

    Object(SDL_Rect &position, Direction direction, std::string texture_path, Window &window);

    // SDL_Rect &getPosition() const;

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

    inline Direction getDirection() const
    {
        return direction_;
    }

    // Texture &getTexture() const;

    inline void setDirection(const Direction direction)
    {
        direction_ = direction;
    }

private:
    SDL_Rect position_;   //!< World coordinates (x, y) and dimensions (w, h)
    Direction direction_; //!< Direction
    Texture texture_;     //!< Texture
};

#endif