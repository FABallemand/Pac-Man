#include "window.h"

bool Window::createWindow(char *title, int w, int h, bool resizable)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, resizable ? SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE : SDL_WINDOW_SHOWN);
    if (window != nullptr)
    {
        width = w;
        height = h;
        mouse_focus = true;
        keyboard_focus = true;
    }

    return window != nullptr;
}

bool Window::createSurface()
{
    return true;
}

bool Window::createRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        fprintf(stderr, "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void Window::handleEvent(SDL_Event &e, SDL_Renderer *&renderer)
{
    if (e.type == SDL_WINDOWEVENT)
    {
        bool updateCaption = false;

        switch (e.window.event)
        {
        // Get new dimensions and repaint on window size change
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            width = e.window.data1;
            height = e.window.data2;
            SDL_RenderPresent(renderer);
            break;

        // Repaint on exposure
        case SDL_WINDOWEVENT_EXPOSED:
            SDL_RenderPresent(renderer);
            break;

        // Mouse entered window
        case SDL_WINDOWEVENT_ENTER:
            mouse_focus = true;
            updateCaption = true;
            break;

        // Mouse left window
        case SDL_WINDOWEVENT_LEAVE:
            mouse_focus = false;
            updateCaption = true;
            break;

        // Window has keyboard focus
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            keyboard_focus = true;
            updateCaption = true;
            break;

        // Window lost keyboard focus
        case SDL_WINDOWEVENT_FOCUS_LOST:
            keyboard_focus = false;
            updateCaption = true;
            break;

        // Window minimized
        case SDL_WINDOWEVENT_MINIMIZED:
            minimized = true;
            break;

        // Window maxized
        case SDL_WINDOWEVENT_MAXIMIZED:
            minimized = false;
            break;

        // Window restored
        case SDL_WINDOWEVENT_RESTORED:
            minimized = false;
            break;
        }

        // Update window caption with new data
        if (updateCaption)
        {
            std::stringstream caption;
            caption << title << " - MouseFocus:" << ((mouse_focus) ? "On" : "Off") << " KeyboardFocus:" << ((keyboard_focus) ? "On" : "Off");
            SDL_SetWindowTitle(window, caption.str().c_str());
        }
    }
    // Enter exit full screen on return key
    else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
    {
        if (fullscreen)
        {
            SDL_SetWindowFullscreen(window, SDL_FALSE);
            fullscreen = false;
        }
        else
        {
            SDL_SetWindowFullscreen(window, SDL_TRUE);
            fullscreen = true;
            minimized = false;
        }
    }
}

void Window::free()
{
    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    if (surface != nullptr)
    {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
    if (renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}