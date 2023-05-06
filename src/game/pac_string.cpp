#include "pac_string.h"

std::array<SDL_Rect, 27> PacString::letter_sprite_ = {{SDL_Rect{12, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // A
                                                       SDL_Rect{20, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // B
                                                       SDL_Rect{28, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // C
                                                       SDL_Rect{36, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // D
                                                       SDL_Rect{44, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // E
                                                       SDL_Rect{52, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // F
                                                       SDL_Rect{60, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // G
                                                       SDL_Rect{68, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // H
                                                       SDL_Rect{76, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // I
                                                       SDL_Rect{84, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // J
                                                       SDL_Rect{92, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // K
                                                       SDL_Rect{100, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s}, // L
                                                       SDL_Rect{108, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s}, // M
                                                       SDL_Rect{116, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s}, // N
                                                       SDL_Rect{124, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s}, // O
                                                       SDL_Rect{4, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},   // P
                                                       SDL_Rect{12, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // Q
                                                       SDL_Rect{20, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // R
                                                       SDL_Rect{28, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // S
                                                       SDL_Rect{36, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // T
                                                       SDL_Rect{44, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // U
                                                       SDL_Rect{52, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // V
                                                       SDL_Rect{60, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // W
                                                       SDL_Rect{68, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // X
                                                       SDL_Rect{76, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // Y
                                                       SDL_Rect{84, 69, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s},  // Z
                                                       SDL_Rect{4, 61, gconst::object::pacchar::size_s, gconst::object::pacchar::size_s}}}; //[SPACE]

std::array<SDL_Rect, 10> PacString::num_sprite_ = {{SDL_Rect{4, 53, 7, 7},
                                                    SDL_Rect{12, 53, 7, 7},
                                                    SDL_Rect{20, 53, 7, 7},
                                                    SDL_Rect{28, 53, 7, 7},
                                                    SDL_Rect{36, 53, 7, 7},
                                                    SDL_Rect{44, 53, 7, 7},
                                                    SDL_Rect{52, 53, 7, 7},
                                                    SDL_Rect{60, 53, 7, 7},
                                                    SDL_Rect{68, 53, 7, 7},
                                                    SDL_Rect{76, 53, 7, 7}}};

SDL_Rect PacString::life_sprite_ = {168,76,12,12};

void PacString::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    for (auto o : word_)
    {
        o.display(sprite, window_surface);
    }
}