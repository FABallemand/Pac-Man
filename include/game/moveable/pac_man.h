#ifndef __PAC_MAN_H__
#define __PAC_MAN_H__

#include "moveable.h"

typedef std::array<SDL_Rect, NB_DYING_SPRITES> DyingSprites;

class PacMan : public Moveable
{
public:
    PacMan(int x, int y);

    /**
     * \brief Handle user inputs to control PacMan
     *
     * \param key_state States of the keys
     */
    void handleUserInputs(const Uint8 *key_state);

    void display(SDL_Surface *sprite, SDL_Surface *window_surface);

private:
    SDL_Rect initial_sprite_{3, 89, PACMAN_W, PACMAN_H}; //!< Initial sprite
    DyingSprites dying_sprites_ = {SDL_Rect{3, 106, PACMAN_W, PACMAN_H}, SDL_Rect{22, 106, PACMAN_W, PACMAN_H},
                                   SDL_Rect{41, 106, PACMAN_W, PACMAN_H}, SDL_Rect{60, 106, PACMAN_W, PACMAN_H},
                                   SDL_Rect{79, 106, PACMAN_W, PACMAN_H}, SDL_Rect{98, 106, 16, PACMAN_H},
                                   SDL_Rect{115, 106, 12, PACMAN_H}, SDL_Rect{128, 106, 8, PACMAN_H},
                                   SDL_Rect{137, 106, 4, PACMAN_H}, SDL_Rect{142, 106, 13, PACMAN_H}}; //!< Sprites location

    bool allowedToMove(Direction direction);
};

#endif