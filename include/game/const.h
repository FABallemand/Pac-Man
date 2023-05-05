#pragma once

/**
 * \namespace gconst
 * \brief Contains all global constants
 *
 */
namespace gconst
{
    namespace window
    {
        constexpr int w = 700; //!< Window width
        constexpr int h = 900; //!< Window height
    }

    namespace game
    {
        constexpr int nb_rows = 27;           //!< Number of rows
        constexpr int nb_columns = 21;        //!< Number of columns
        constexpr int maze_w = 166;           //!< Maze width
        constexpr int maze_h = 216;           //!< Maze height
        constexpr int nb_gommes = 188;        //!< Number of Gommes
        constexpr int nb_super_gommes = 4;    //!< Number of Super-Gommes
        constexpr int nb_ghosts = 4;          //!< Number of Ghosts
        constexpr int super_duration = 10000; //!< Duration of SUPER state
        constexpr int blink_duration = 2000;  //!< Duration of BLINK state
    }

    namespace object
    {
        namespace cell
        {
            constexpr int size = 32; //!< Cell size
        }

        namespace pacchar
        {
            constexpr int size_s = 7; //!< Char size (on sprite)
        }

        namespace moveable
        {
            constexpr int nb_directions = 4;     //!< Number of possible directions (except NONE)
            constexpr int nb_sprite_frame = 3;   //!< Number of frame each sprite is displayed before going to the next sprite in the animation
            constexpr int neighborhood_size = 3; //!< Neighborhood size (in cell)

            namespace pacman
            {
                constexpr int size_s1 = 16;                                            //!< PacMan size (on sprite)
                constexpr int size_s2 = 11;                                            //!< PacMan size (on sprite)
                constexpr int size = 32;                                               //!< PacMan size
                constexpr int speed = 100;                                             //!< PacMan speed
                constexpr int move_diag_offset = (2 / 3) * gconst::object::cell::size; //!< Offset to which Pac-Man can move diagonaly
                constexpr int nb_moving_sprites = 2;                                   //!< Number of sprites in the moving animation
                constexpr int nb_dying_sprites = 10;                                   //!< Number of sprites in the dying animation
            }

            namespace ghost
            {
                constexpr int size_s = 16;            //!< Ghost size (on sprite)
                constexpr int size = 32;              //!< Ghost size
                constexpr int speed = 50;             //!< Ghost speed
                constexpr int nb_moving_sprites = 2;  //!< Number of sprites in the moving animation
                constexpr int nb_special_sprites = 2; //!< Number of sprites in the moving animation
                constexpr int score = 100;            //!< Ghost base score
                constexpr int chase_time = 2000;      //!< Time before Inky change target
            }
        }

        namespace eatable
        {
            namespace gomme
            {
                constexpr int size_s = 4;                                                                             //!< Gomme size (on sprite)
                constexpr int size = 16;                                                                              //!< Gomme size
                constexpr int score = 10;                                                                             //!< Gomme score
                constexpr int gomme_offset = (gconst::object::cell::size - gconst::object::eatable::gomme::size) / 2; //!< Gomme display offset
            }

            namespace super_gomme
            {
                constexpr int size_s = 9;                                                                                         //!< Super-Gomme size (on sprite)
                constexpr int size = 32;                                                                                          //!< Super-Gomme size
                constexpr int score = 50;                                                                                         //!< Super-Gomme score
                constexpr int super_gomme_offset = (gconst::object::cell::size - gconst::object::eatable::super_gomme::size) / 2; //!< Super-Gomme display offset
            }

            namespace fruit
            {
                constexpr int size_s = 16;                                      //!< Fruit size (on sprite)
                constexpr int size = 32;                                        //!< Fruit size
                constexpr int score[9] = {0,100,300,500,700,1000,2000,3000,5000}; //!< Fruit score
                constexpr int i = 15;                                           //!< Fruit position i
                constexpr int j = 10;                                           //!< Fruit position i
                constexpr int time = 10000;                                     //!< Time before fruit expiration
                constexpr int spawn_interval = 4000;                           //!< score interval between to fruit spawning
            }
        }
    }
}