#ifndef __PAC_MAN_H__
#define __PAC_MAN_H__

#include <cmath>

#include "moveable.h"
#include "timer.h"

using PacManDyingSprites = std::array<SDL_Rect, gconst::object::moveable::pacman::nb_dying_sprites>;

/**
 * \enum PacManState
 * \brief Describe the state of Pac-Man
 *
 */
enum PacManState
{
    PACMAN_ALIVE,
    PACMAN_DYING,
    PACMAN_DEAD
};

/**
 * \class PacMan
 * \brief Everything's in the name :)
 *
 */
class PacMan : public Moveable
{
public:
    PacMan();

    ~PacMan()
    {
    }

    PacManState getState() const
    {
        return state_;
    }

    void setState(PacManState state)
    {
        state_ = state;
    }

    Direction getDirection() const
    {
        return direction_;
    }

    CellNeighborhood &getNeighborhood()
    {
        return neighborhood_;
    }

    Cell *getCurrentCell()
    {
        return neighborhood_[1][1];
    }

    void setNeighborhood(CellNeighborhood neighborhood)
    {
        neighborhood_ = neighborhood;
    }

    void update(const Uint8 *key_state, const float delta_t);

    void respawn();

private:
    // State ==================================================================
    PacManState state_ = PACMAN_ALIVE; //!< State of Pac-Man
    // Movement ===============================================================
    bool allowed_to_move_ = true;      //!< Allowed to move indicator
    Direction input_direction_ = NONE; //!< User wanted direction
    CellNeighborhood neighborhood_;    //!< Cell neighborhood of the object
    // Sprites ================================================================
    static SDL_Rect initial_sprite_;          //!< Initial sprite
    static PacManDyingSprites dying_sprites_; //!< Dying sprites

    /**
     * \brief Handle user inputs to control PacMan
     *
     * \param key_state States of the keys
     */
    void handleUserInputs(const Uint8 *key_state);

    void turnLeft();

    void turnRight(); // Move to moveable?

    void turnUp();

    void turnDown();

    void turn() override;

    void fixDimensions() override;

    void move() override;

    void handleMovement() override;

    void updateSprite() override;
};

#endif