#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <vector>
#include <array>

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
    static const int columns_ = 28;                       // Playable ?? Total!!
    // PacMan pacman_;                                       //!< Pac-Man!!
    // std::vector<Ghost> ghosts_;                           //!< Ghosts
    // std::vector<Gomme> gommes_;                           //!< Gommes
    // std::array<std::array<Gomme, columns_>, rows_> dots_; //!< Gommes (29x26)
    // std::vector<Fruit> fruits_;                           //!< Fruits
};

#endif