#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <vector>
#include <array>

// Cell
#include "cell.h"

// Pac-Man
#include "pac_man.h"

// Ghosts
#include "ghost.h"
#include "blinky.h"
#include "clyde.h"
#include "inky.h"
#include "pinky.h"

// Eatable
#include "gomme.h"
#include "fruit.h"

class Game
{
public:
    Game() {}

private:
    static const int rows_ = 36;
    static const int columns_ = 28;
    int life_remaining_;                                    //!< Life remaining
    int game_score_;                                        //!< Score
    PacMan pacman_;                                         //!< Pac-Man!!
    std::vector<Ghost> ghosts_;                             //!< Ghosts
    std::vector<Gomme> gommes_;                             //!< Gommes
    std::vector<Fruit> fruits_;                             //!< Fruits
    std::array<std::array<Cell *, columns_>, rows_> board_; //!< Board of cells
};

#endif