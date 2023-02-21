#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>

#include <string>
#include <iostream>
#include <sstream>

/**
 * \class Window
 * \brief Class representing a window
 */
class Window
{
public:
    Window()
    {
        window = nullptr;
        surface = nullptr;
        renderer = nullptr;
        title = nullptr;
        width = 0;
        height = 0;
        mouse_focus = false;
        keyboard_focus = false;
        fullscreen = false;
        minimized = false;
    }

    /**
     * \brief Creates window
     */
    bool createWindow(char *title, int w, int h, bool resizable);

    // Creates surface -> USELESS
    bool createSurface();

    /**
     * \brief  Creates renderer
     */
    bool createRenderer();

    inline SDL_Window *getWindow() const
    {
        return window;
    }

    inline SDL_Surface *getSurface() const
    {
        return surface;
    }

    inline SDL_Renderer *getRenderer()
    {
        return renderer;
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
     * \brief Handles window events
     */
    void handleEvent(SDL_Event &e, SDL_Renderer *&renderer);

    // Window focii
    inline bool hasMouseFocus()
    {
        return mouse_focus;
    }
    inline bool hasKeyboardFocus()
    {
        return keyboard_focus;
    }
    inline bool isMinimized()
    {
        return minimized;
    }

    /**
     * \brief Deallocates
     */
    void free();

private:
    SDL_Window *window;
    SDL_Surface *surface = NULL; // former screen_surface, maybe useless...
    SDL_Renderer *renderer = NULL;
    char *title; // char * because SDL

    int width;
    int height;

    bool mouse_focus;
    bool keyboard_focus;
    bool fullscreen;
    bool minimized;
};

#endif