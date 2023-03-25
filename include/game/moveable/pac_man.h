#ifndef __PAC_MAN_H__
#define __PAC_MAN_H__

#include "moveable.h"
#include <cmath>
using DyingSprites = std::array<SDL_Rect, gconst::object::moveable::pacman::nb_dying_sprites>;

/**
 * \class PacMan
 * \brief Everything's in the name :)
 *
 */
class PacMan : public Moveable
{
public:
    PacMan(int x, int y);

    ~PacMan()
    {
    }

    void eat(Object *eatable);

    void update(const Uint8 *key_state, const float delta_t);

private:
    Direction input_direction_ = NONE;                                              //!< User wanted direction
    Direction action_direction_ = NONE;                                             //!< Action
    /*static constexpr*/ SDL_Rect initial_sprite_{3, 89, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}; //!< Initial sprite
    /*static constexpr*/ DyingSprites dying_sprites_ = {SDL_Rect{3, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, SDL_Rect{22, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                                        SDL_Rect{41, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, SDL_Rect{60, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1},
                                                        SDL_Rect{79, 106, gconst::object::moveable::pacman::size_s1, gconst::object::moveable::pacman::size_s1}, SDL_Rect{98, 106, 16, gconst::object::moveable::pacman::size_s1},
                                                        SDL_Rect{115, 106, 12, gconst::object::moveable::pacman::size_s1}, SDL_Rect{128, 106, 8, gconst::object::moveable::pacman::size_s1},
                                                        SDL_Rect{137, 106, 4, gconst::object::moveable::pacman::size_s1}, SDL_Rect{142, 106, 13, gconst::object::moveable::pacman::size_s1}}; //!< Dying sprites

    static constexpr int move_diag_offset_ = (2 / 3) * gconst::object::cell::size;

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