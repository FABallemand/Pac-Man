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
    PacString(std::string to_print, int x, int y)
    {
        to_print_ = to_print;
        std::transform(to_print_.begin(), to_print_.end(), to_print_.begin(), [](unsigned char c)
                       { return std::tolower(c); });
        int i = 0;
        for (char c : to_print_)
        {
            if (c >= 97 && c <= 122)
            {
                word_.emplace_back(UNDEFINED, x + i * gconst::game::object::cell::size, y, gconst::game::object::cell::size, gconst::game::object::cell::size, &(letter_sprite_[c - 97]));
            }
            else if (c == 32)
            {
                word_.emplace_back(UNDEFINED, x + i * gconst::game::object::cell::size, y, gconst::game::object::cell::size, gconst::game::object::cell::size, &(letter_sprite_[26]));
            }
            else if (c >= 48 && c <= 57)
            {
                word_.emplace_back(UNDEFINED, x + i * gconst::game::object::cell::size, y, gconst::game::object::cell::size, gconst::game::object::cell::size, &(num_sprite_[c - 48]));
            }
            else if (c == '$')
            {
                word_.emplace_back(UNDEFINED, x + i * gconst::game::object::cell::size, y, gconst::game::object::cell::size, gconst::game::object::cell::size, &life_sprite_);
            }
            else
            {
                LOG(ERROR) << "Invalid character: " << c;
            }
            ++i;
        }
    }

    void display(SDL_Surface *sprite, SDL_Surface *window_surface);

private:
    std::string to_print_;                          //!< Word to display
    std::vector<Object> word_;                      //!< Vector of letters to display
    static std::array<SDL_Rect, 27> letter_sprite_; //!< Letter sprites
    static std::array<SDL_Rect, 10> num_sprite_;    //!< Number sprites
    static SDL_Rect life_sprite_;                   //!< Life sprite
};

#endif