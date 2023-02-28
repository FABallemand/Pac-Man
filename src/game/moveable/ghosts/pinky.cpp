#include "pinky.h"

Pinky::Pinky()
{

    moving_sprites_ = {{{SDL_Rect{3 ,141 ,16 ,16 }, SDL_Rect{20 ,141 ,16 ,16 }}, {SDL_Rect{37 ,141 ,16 ,16 }, SDL_Rect{54 ,141 ,16 ,16 }},
                        {SDL_Rect{71 ,141 ,16 ,16 }, SDL_Rect{88 ,141 ,16 ,16 }},{SDL_Rect{105 ,141 ,16 ,16 }, SDL_Rect{122 ,141 ,16 ,16 }}}};
}