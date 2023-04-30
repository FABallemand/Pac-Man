#ifndef __GHOST_H__
#define __GHOST_H__

#include <fstream>
#include <cmath>

#include "moveable.h"

using GhostSpecialSprites = std::array<SDL_Rect, gconst::object::moveable::nb_directions>;
using SimpleMaze = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;

class Ghost : public Moveable
{
public:
    Ghost(int x, int y, std::string name) : Moveable{GHOST, x, y, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size, &(moving_sprites_[0][0]), NONE}, name_{name}
    {
        loadSimpleMaze();
    }

    void update(const float delta_t, int target_i, int traget_j);

protected:
    std::string name_;
    SimpleMaze ghost_board_;
    /*static constexpr*/ GhostSpecialSprites eatable_sprites_ = {SDL_Rect{3, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                                 SDL_Rect{20, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                                 SDL_Rect{37, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                                 SDL_Rect{54, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}; //!< Sprites location
    /*static constexpr*/ GhostSpecialSprites eaten_sprites_ = {SDL_Rect{71, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                               SDL_Rect{89, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                               SDL_Rect{105, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                               SDL_Rect{122, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}; //!< Sprites location                                                                                                                                  //!< Simple representation of the maze

    /**
     * \brief
     *
     */
    void loadSimpleMaze(); // Argument -> file

    void strategy(int target_i, int target_j);

    // virtual void scatter() = 0;

    Direction chase(int target_i, int target_j);

    // virtual void frightened() = 0;

    void turnLeft();

    void turnRight(); // Move to moveable?

    void turnUp();

    void turnDown();

    void turn() override;

    void move();

    void handleMovement() override;

    void updateSprite() override;

    int chaseRec(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j);

    int distance(int i1, int j1, int i2, int j2);
};

#endif