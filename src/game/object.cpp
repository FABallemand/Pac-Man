#include "object.h"

Object::Object(int x, int y, Direction direction, std::string &texture_path, Window &window) : position_{x, y, 0, 0}, direction_{direction}, texture_{}
{
    // Load texture
    if (!texture_.loadFromFile(texture_path, window, 0, 0, 0)) // Change for SDL_color??
    {
        LOG(ERROR) << "Unable to load texture: " << texture_path;
        exit(1);
    }

    // Set width and height according to texture size
    position_.w = texture_.getWidth();
    position_.h = texture_.getHeight();
}

// SDL_Rect &Object::getPosition() const
// {
//     return position_;
// }

// Texture &Object::getTexture() const
// {
//     return texture_;
// }