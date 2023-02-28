#include "inky.h"

Inky::Inky()
{
    moving_sprites_ = {{{SDL_Rect{3 ,159 ,16 ,16 }, SDL_Rect{20 ,159 ,16 ,16 }}, {SDL_Rect{37 ,159 ,16 ,16 }, SDL_Rect{54 ,159 ,16 ,16 }},
                        {SDL_Rect{71 ,159 ,16 ,16 }, SDL_Rect{88 ,159 ,16 ,16 }},{SDL_Rect{105 ,159 ,16 ,16 }, SDL_Rect{122 ,159 ,16 ,16 }}}};
}