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
    Window();

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

    SDL_Window *getWindow() const;

    SDL_Surface *getSurface() const;

    SDL_Renderer *getRenderer();

    int getWidth();

    int getHeight();

    /**
     * \brief Handles window events
     */
    void handleEvent(SDL_Event &e, SDL_Renderer *&renderer);

    // Window focii
    bool hasMouseFocus();
    bool hasKeyboardFocus();
    bool isMinimized();

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