#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <SDL.h>

#include "texture.h"

/**
 * \enum Direction
 * \brief Orientation of the object relatively to the screen
 */
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Object
{
public:
    Object();

    Object(int x, int y, int w, int h, Direction direction, Texture &texture);

    Object(SDL_Rect &position, Direction direction, Texture &texture);

private:
    SDL_Rect position_;   //!< World coordinates (x, y) and dimensions (w, h)
    Direction direction_; //!< Direction
    Texture texture_;     //!< Texture
};

#endif