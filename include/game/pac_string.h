#ifndef __PAC_STRING_H__
#define __PAC_STRING_H__

#include <string>
#include <algorithm>

#include "object.h"

/**
 * \class PacString
 * \brief Class used to display words in the overlay
 *
 */
class PacString
{
public:
    PacString(std::string to_print, int x, int y);

    void display(SDL_Surface *sprite, SDL_Surface *window_surface);

private:
    std::string to_print_;                          //!< Word to display
    std::vector<Object> word_;                      //!< Vector of letters to display
    static std::array<SDL_Rect, 27> letter_sprite_; //!< Letter sprites
    static std::array<SDL_Rect, 10> num_sprite_;    //!< Number sprites
    static SDL_Rect life_sprite_;                   //!< Life sprite
};

#endif