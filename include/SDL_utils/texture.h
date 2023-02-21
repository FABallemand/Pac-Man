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

    ~Texture()
    {
        free();
    }

    inline SDL_Texture *getTexture() const
    {
        return texture;
    }

    inline int getWidth()
    {
        return width;
    }

    inline int getHeight()
    {
        return height;
    }

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
    inline void setColor(Uint8 red, Uint8 green, Uint8 blue)
    {
        // Modulate texture
        SDL_SetTextureColorMod(texture, red, green, blue);
    }

    /**
     * \brief Sets blending
     */
    inline void setBlending(SDL_BlendMode blending)
    {
        // Set blending function
        SDL_SetTextureBlendMode(texture, blending);
    }

    inline void setAlpha(Uint8 alpha)
    {
        // Modulate texture alpha
        SDL_SetTextureAlphaMod(texture, alpha);
    }

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