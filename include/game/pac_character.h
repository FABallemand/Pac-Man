#ifndef __PAC_CHAR_H__
#define __PAC_CHAR_H__

#include <SDL.h>
#include <array>
#include <cstring>

#include "const.h"
#include "logger.h"
#include "object.h"

class PacChar : public Object
{
public:
    PacChar(char c) { printable_char_ = c; }

private:
    char printable_char_;
    static std::array<SDL_Rect, 27> char_sprite_;
};

#endif