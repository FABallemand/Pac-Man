#include "object.h"

Object::Object() : position_{0, 0, 0, 0}, direction_{UNKNOWN}, texture_{}
{
#ifdef DEBUG
    printInfo("new object created");
#endif
}

Object::Object(int x, int y, int w, int h, Direction direction, std::string texture_path, Window &window) : position_{x, y, w, h}, direction_{direction}, texture_{}
{
    if (!texture_.loadFromFile(texture_path, window, 0, 0, 0)) // Change for SDL_color
    {
        printError("Unable to load texture: %s", texture_path);
        exit(1);
    }
}

Object::Object(SDL_Rect &position, Direction direction, std::string texture_path, Window &window) : position_{position}, direction_{direction}, texture_{}
{
    if (!texture_.loadFromFile(texture_path, window, 0, 0, 0)) // Change for SDL_color
    {
        printError("Unable to load texture: %s", texture_path);
        exit(1);
    }
}

// SDL_Rect &Object::getPosition() const
// {
//     return position_;
// }
// Texture &Object::getTexture() const
// {
//     return texture_;
// }