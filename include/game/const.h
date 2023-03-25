#pragma once

namespace gconst
{
    namespace window
    {
        constexpr int w = 700; //!< Window width
        constexpr int h = 900; //!< Window height
    }

    namespace game
    {
        constexpr int nb_rows = 27;    //!< Number of rows
        constexpr int nb_columns = 21; //!< Number of columns
        constexpr int maze_w = 166;    //!< Maze width
        constexpr int maze_h = 216;    //!< Maze height
    }

    namespace object
    {
        namespace cell
        {
            constexpr int size = 32; //!< Cell size
        }

        namespace moveable
        {
            constexpr int nb_directions = 4;     //!< Number of possible directions (except NONE)
            constexpr int nb_sprite_frame = 3;   //!< Number of frame each sprite is displayed before going to the next sprite in the animation
            constexpr int neighborhood_size = 3; //!< Neighborhood size (in cell)

            namespace pacman
            {
                constexpr int size_s1 = 16;          //!< PacMan size (on sprite)
                constexpr int size_s2 = 11;          //!< PacMan size (on sprite)
                constexpr int size = 32;             //!< PacMan size
                constexpr int speed = 100;           //!< PacMan speed
                constexpr int nb_moving_sprites = 2; //!< Number of sprites in the moving animation
                constexpr int nb_dying_sprites = 10; //!< Number of sprites in the dying animation
            }

            namespace ghost
            {
                constexpr int size_s = 16; //!< Ghost size (on sprite)
                constexpr int size = 16;   //!< Ghost size
            }
        }

        namespace eatable
        {
            namespace gomme
            {
                constexpr int size_s = 4; //!< Gomme size (on sprite)
                constexpr int size = 16;  //!< Gomme size
                constexpr int score = 1;  //!< Gomme score
            }

            namespace super_gomme
            {
                constexpr int size_s = 9; //!< Super-Gomme size (on sprite)
                constexpr int size = 24;  //!< Super-Gomme size
                constexpr int score = 2;  //!< Super-Gomme score
            }

            namespace fruit
            {
                constexpr int score = 3; //!< Fruit score
            }
        }
    }
}