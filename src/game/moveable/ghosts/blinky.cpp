#include "blinky.h"

Blinky::Blinky()
{

    moving_sprites_ = {{{SDL_Rect{3 ,123 ,16 ,16 }, SDL_Rect{20 ,123 ,16 ,16 }}, {SDL_Rect{37 ,123 ,16 ,16 }, SDL_Rect{54 ,123 ,16 ,16 }},
                        {SDL_Rect{71 ,123 ,16 ,16 }, SDL_Rect{88 ,123 ,16 ,16 }},{SDL_Rect{105 ,123 ,16 ,16 }, SDL_Rect{122 ,123 ,16 ,16 }}}};
}