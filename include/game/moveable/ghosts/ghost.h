#ifndef __GHOST_H__
#define __GHOST_H__

#include <fstream>

#include "moveable.h"

using GhostSpecialSprites = std::array<SDL_Rect, gconst::object::moveable::nb_directions>;
using SimpleMaze = std::array<std::array<int, gconst::game::nb_rows>, gconst::game::nb_columns>;

class Ghost : public Moveable
{
public:
    Ghost(int x, int y) : Moveable{GHOST, x, y, gconst::object::moveable::ghost::size, gconst::object::moveable::ghost::size, &(moving_sprites_[0][0]), NONE}
    {
        loadSimpleMaze();
    }

    /**
     * \brief
     *
     */
    void loadSimpleMaze(); // Argument -> file

    void strategy();

    // virtual void scatter() = 0;

    void chase();

    // virtual void frightened() = 0;

    void update(const float delta_t);

protected:
    static constexpr GhostSpecialSprites eatable_sprites_ = {SDL_Rect{3, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                             SDL_Rect{20, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                             SDL_Rect{37, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                             SDL_Rect{54, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}; //!< Sprites location
    static constexpr GhostSpecialSprites eaten_sprites_ = {SDL_Rect{71, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                           SDL_Rect{89, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                           SDL_Rect{105, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s},
                                                           SDL_Rect{122, 195, gconst::object::moveable::ghost::size_s, gconst::object::moveable::ghost::size_s}}; //!< Sprites location
    SimpleMaze ghost_board_; //!< Simple representation of the maze

    void turn() override;

    void move();

    void handleMovement() override;

    void updateSprite() override;
};

#endif