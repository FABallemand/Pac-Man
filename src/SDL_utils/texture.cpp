#include "texture.h"

Texture::Texture()
{
    texture = nullptr;
    width = 0;
    height = 0;
}


bool Texture::loadFromFile(std::string path, Window window, int r, int g, int b)
{
    // Get rid of preexisting texture
    free();
    // The final texture
    SDL_Texture *new_texture = nullptr;

    // Load image at specified path
    SDL_Surface *loaded_surface = SDL_LoadBMP(path.c_str());
    if (loaded_surface == nullptr)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        // Convert surface to display format
        SDL_Surface *formatted_surface = SDL_ConvertSurfaceFormat(loaded_surface, SDL_GetWindowPixelFormat(window.getWindow()), 0);
        if (formatted_surface == nullptr)
        {
            printf("Unable to convert loaded surface to display format! SDL Error: %s\n", SDL_GetError());
        }

        // Color key image
        if (r >= 0 & g >= 0 && b >= 0)
        {
            SDL_SetColorKey(formatted_surface, SDL_TRUE, SDL_MapRGB(formatted_surface->format, r, g, b)); // Color keying (r,g,b)
        }
        new_texture = SDL_CreateTextureFromSurface(window.getRenderer(), formatted_surface);
        if (new_texture == nullptr)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            // Get image dimensions
            width = loaded_surface->w;
            height = loaded_surface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loaded_surface);
        SDL_FreeSurface(formatted_surface);
    }

    // Return success
    texture = new_texture;
    return texture != nullptr;
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool Texture::loadFromRenderedText(std::string texture_text, SDL_Color text_color, TTF_Font *font, SDL_Renderer *renderer)
{
    // Get rid of preexisting texture
    free();

    // Render text surface
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, texture_text.c_str(), text_color);
    if (text_surface == nullptr)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        // Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, text_surface);
        if (texture == nullptr)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            // Get image dimensions
            width = text_surface->w;
            height = text_surface->h;
        }

        // Get rid of old surface
        SDL_FreeSurface(text_surface);
    }

    // Return success
    return texture != nullptr;
}
#endif

void Texture::render(int x, int y, SDL_Renderer *renderer, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    // Set clip rendering dimensions
    SDL_Rect render_quad = {x, y, width, height};
    if (clip != nullptr)
    {
        render_quad.w = clip->w;
        render_quad.h = clip->h;
    }

    // Render to screen
    SDL_RenderCopyEx(renderer, texture, clip, &render_quad, angle, center, flip);
}

void Texture::free()
{
    // Free texture if it exists
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}