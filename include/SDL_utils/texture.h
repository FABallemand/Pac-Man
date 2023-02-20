#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <SDL.h>

#include "window.h"

/**
 * \class Texture
 * \brief Class representing a texture
 *        Contains usefull methods to simplify use of SDL_Texture
 */
class Texture
{
public:
    Texture();

    ~Texture();

    SDL_Texture *getTexture() const;

    int getWidth();

    int getHeight();

    /**
     * \brief Loads image at specified path
     */
    bool loadFromFile(std::string path, Window window, int r = -1, int g = -1, int b = -1);

#if defined(SDL_TTF_MAJOR_VERSION)
    /**
     * \brief Creates an image from font string
     */
    bool loadFromRenderedText(std::string texture_text, SDL_Color text_color, TTF_Font *font, SDL_Renderer *renderer);
#endif

    /**
     * \brief Sets color modulation
     */
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    /**
     * \brief Sets blending
     */
    void setBlending(SDL_BlendMode blending);

    void setAlpha(Uint8 alpha);

    /**
     *\brief Renders texture at given point
     *\brief (note: center = NULL means the rotation/flipping will be done around the center of the texture)
     */
    void render(int x, int y, SDL_Renderer *renderer, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    /**
     * \brief Deallocates texture
     */
    void free();

protected:
    SDL_Texture *texture;

    int width;
    int height;
};

#endif