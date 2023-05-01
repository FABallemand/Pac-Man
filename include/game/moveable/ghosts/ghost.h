#ifndef __GHOST_H__
#define __GHOST_H__

#include <fstream>
#include <cmath>

#include "moveable.h"

using GhostSpecialSprites = std::array<SDL_Rect, gconst::object::moveable::nb_directions>;
using SimpleMaze = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;

/**
 * \enum GhostState
 * \brief Describe the state of a ghost
 *
 */
enum GhostState
{
    GHOST_DEFAULT,
    GHOST_VULNERABLE,
    GHOST_VULNERABLE_BLINK,
    GHOST_EATEN
};

class Ghost : public Moveable
{
public:
    Ghost(int x, int y, std::string name) : Moveable{GHOST, x, y, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size, &(moving_sprites_[0][0]), NONE}, name_{name}
    {
        loadSimpleMaze();
    }

    GhostState getState() const
    {
        return state_;
    }

    void setState(GhostState state)
    {
        state_ = state;
    }

    void update(const float delta_t, int target_i, int traget_j);

protected:
    std::string name_;       //!< Name of the ghost (for logging purpose only)
    SimpleMaze ghost_board_; //!< Simple representation of the maze
    // State ==================================================================
    GhostState state_ = GHOST_DEFAULT; //!< State of the ghost
    // Sprites ================================================================
    static GhostSpecialSprites eatable_sprites_; //!< Sprites location
    static GhostSpecialSprites eaten_sprites_;   //!< Sprites location                                                                                                                                  //!< Simple representation of the maze

    /**
     * \brief
     *
     */
    void loadSimpleMaze(); // Argument -> file

    void strategy(int target_i, int target_j);

    Direction chase(int target_i, int target_j);

    int chaseRec(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j);

    // virtual void scatter() = 0;

    // virtual void frightened() = 0;

    // virtual void eaten() = 0;

    void turn() override;

    void fixDimensions() override;

    void move() override;

    void handleMovement() override;

    void updateSprite() override;

    int distance(int i1, int j1, int i2, int j2);
};

#endif