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

    int getX() const;

    int getY() const;

    int getW() const;

    int getH() const;

    Direction getDirection() const;

    // Texture &getTexture() const;

    void setDirection(Direction direction);

private:
    SDL_Rect position_;   //!< World coordinates (x, y) and dimensions (w, h)
    Direction direction_; //!< Direction
    Texture texture_;     //!< Texture
};

#endif