#ifndef __GHOST_H__
#define __GHOST_H__

#include <fstream>
#include <cmath>

#include "moveable.h"
#include "path_finder.h"

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
    GHOST_EATEN,
    GHOST_STOP
};

class Ghost : public Moveable
{
public:
    Ghost(int x, int y, int speed, std::string name) : Moveable{GHOST, x, y, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size, speed, &(moving_sprites_[0][0]), NONE}, name_{name}
    {
        loadSimpleMaze();
    }

    std::string getName() const
    {
        return name_;
    }

    GhostState getState() const
    {
        return state_;
    }

    void setState(GhostState state)
    {
        if (state_ != GHOST_EATEN)
        {
            state_ = state;
        }
    }

    void update(const float delta_t, int target_i, int traget_j, Direction direction);

    void respawn();

protected:
    std::string name_;       //!< Name of the ghost (for logging purpose only)
    SimpleMaze ghost_board_; //!< Simple representation of the maze
    // State ==================================================================
    GhostState state_ = GHOST_DEFAULT; //!< State of the ghost
    // Movement ===============================================================
    std::pair<int, int> scatter_position_; //!< Vulnerable position
    PathFinder find_path_{};               //!< Path finder
    // Sprites ================================================================
    static GhostSpecialSprites eatable_sprites_; //!< Sprites location
    static GhostSpecialSprites eaten_sprites_;   //!< Sprites location                                                                                                                                  //!< Simple representation of the maze

    /**
     * \brief
     *
     */
    void loadSimpleMaze(); // Argument -> file

    void strategy(int target_i, int target_j, Direction target_direction = NONE);

    virtual Direction chase(std::pair<int, int> target_position, Direction target_direction) = 0;

    void followPath();

    void turn() override;

    void fixDimensions() override;

    void move() override;

    void handleMovement() override;

    void updateSprite() override;
};

#endif