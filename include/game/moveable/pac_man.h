#ifndef __PAC_MAN_H__
#define __PAC_MAN_H__

#include "moveable.h"

using DyingSprites = std::array<SDL_Rect, NB_DYING_SPRITES>;

/**
 * \class PacMan
 * \brief Everything's in the name :)
 *
 */
class PacMan : public Moveable
{
public:
    PacMan(int x, int y);

    void update(const Uint8 *key_state, const float delta_t);

private:
    float delta_t_;                                            //!< Elapsed time since last update
    Direction input_direction_ = NONE;                         //!< User wanted direction
    Direction action_direction_ = NONE;                        //!< Action
    SDL_Rect initial_sprite_{3, 89, S1_PACMAN_W, S1_PACMAN_H}; //!< Initial sprite
    DyingSprites dying_sprites_ = {SDL_Rect{3, 106, S1_PACMAN_W, S1_PACMAN_H}, SDL_Rect{22, 106, S1_PACMAN_W, S1_PACMAN_H},
                                   SDL_Rect{41, 106, S1_PACMAN_W, S1_PACMAN_H}, SDL_Rect{60, 106, S1_PACMAN_W, S1_PACMAN_H},
                                   SDL_Rect{79, 106, S1_PACMAN_W, S1_PACMAN_H}, SDL_Rect{98, 106, 16, S1_PACMAN_H},
                                   SDL_Rect{115, 106, 12, S1_PACMAN_H}, SDL_Rect{128, 106, 8, S1_PACMAN_H},
                                   SDL_Rect{137, 106, 4, S1_PACMAN_H}, SDL_Rect{142, 106, 13, S1_PACMAN_H}}; //!< Dying sprites

    static constexpr int move_diag_offset_ = (2 / 3) * CELL_SIZE;

    /**
     * \brief Handle user inputs to control PacMan
     *
     * \param key_state States of the keys
     */
    void handleUserInputs(const Uint8 *key_state);

    void turnLeft();

    void turnRight();

    void turnUp();

    void turnDown();

    void turn() override;

    void fixDimensions();

    void move();

    void handleMovement() override;

    void updateSprite() override;
};

#endif