#include "pac_string.h"

std::array<SDL_Rect, 27> PacString::letter_sprite_ = {{SDL_Rect{11, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // A
                                                       SDL_Rect{19, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // B
                                                       SDL_Rect{27, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // C
                                                       SDL_Rect{35, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // D
                                                       SDL_Rect{43, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // E
                                                       SDL_Rect{51, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // F
                                                       SDL_Rect{59, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // G
                                                       SDL_Rect{67, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // H
                                                       SDL_Rect{75, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // I
                                                       SDL_Rect{83, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // J
                                                       SDL_Rect{91, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // K
                                                       SDL_Rect{99, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s}, // L
                                                       SDL_Rect{107, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s}, // M
                                                       SDL_Rect{115, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s}, // N
                                                       SDL_Rect{123, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s}, // O
                                                       SDL_Rect{3, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},   // P
                                                       SDL_Rect{11, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // Q
                                                       SDL_Rect{19, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // R
                                                       SDL_Rect{27, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // S
                                                       SDL_Rect{35, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // T
                                                       SDL_Rect{43, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // U
                                                       SDL_Rect{51, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // V
                                                       SDL_Rect{59, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // W
                                                       SDL_Rect{67, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // X
                                                       SDL_Rect{75, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // Y
                                                       SDL_Rect{83, 68, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},  // Z
                                                       SDL_Rect{3, 60, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s}}}; //[SPACE]

std::array<SDL_Rect, 10> PacString::num_sprite_ = {{SDL_Rect{ 3, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{11, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{19, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{27, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{35, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{43, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{51, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{59, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{67, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s},
                                                    SDL_Rect{75, 52, gconst::game::object::pacchar::size_s, gconst::game::object::pacchar::size_s}}};

SDL_Rect PacString::life_sprite_ = {168,76,12,12};

void PacString::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    for (auto o : word_)
    {
        o.display(sprite, window_surface);
    }
}