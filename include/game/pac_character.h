#ifndef __PAC_CHAR_H__
#define __PAC_CHAR_H__

#include <SDL.h>
#include <array>

#include "const.h"
#include "logger.h"
#include "object.h"
#include <cstring>


class PacChar : public Object
{
public:
    PacChar(char c){printable_char_ = c;}

private:
    char printable_char_;
    std::array<SDL_Rect,27> char_sprite_ = {{SDL_Rect{12,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // A
                                             SDL_Rect{20,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // B
                                             SDL_Rect{28,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // C
                                             SDL_Rect{36,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // D
                                             SDL_Rect{44,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // E
                                             SDL_Rect{52,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // F
                                             SDL_Rect{60,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // G
                                             SDL_Rect{68,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // H
                                             SDL_Rect{76,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // I
                                             SDL_Rect{84,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // J
                                             SDL_Rect{92,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // K
                                             SDL_Rect{100,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},   // L
                                             SDL_Rect{108,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},   // M
                                             SDL_Rect{116,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},   // N
                                             SDL_Rect{124,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},   // O
                                             SDL_Rect{4,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},     // P
                                             SDL_Rect{12,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // Q
                                             SDL_Rect{20,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // R
                                             SDL_Rect{28,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // S
                                             SDL_Rect{36,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // T
                                             SDL_Rect{44,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // U
                                             SDL_Rect{52,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // V
                                             SDL_Rect{60,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // W
                                             SDL_Rect{68,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // X
                                             SDL_Rect{76,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // Y
                                             SDL_Rect{84,69,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s},    // Z
                                             SDL_Rect{4,61,gconst::object::pacchar::size_s,gconst::object::pacchar::size_s}}};   //[SPACE]
};

#endif