#ifndef __PAC_MAN_H__
#define __PAC_MAN_H__

#include "moveable.h"

class PacMan : public Moveable
{
public:
    PacMan();
    virtual void display(SDL_Surface *sprite, SDL_Surface *window_surface) const;

private:
    SDL_Rect initial_sprite_ = SDL_Rect{3,89,16,16};
    std::array<SDL_Rect, 10> dying_sprites_ = {SDL_Rect{3,106,18,14}, SDL_Rect{22,106,18,14}, SDL_Rect{41,106,18,14},
                                                SDL_Rect{60,106,18,14}, SDL_Rect{79,106,18,14}, SDL_Rect{98,106,16,14}, 
                                                SDL_Rect{115,106,12,14}, SDL_Rect{128,106,8,14}, SDL_Rect{137,106,4,14},
                                                SDL_Rect{142,106,13,14}}; //!< Sprites location
};

#endif