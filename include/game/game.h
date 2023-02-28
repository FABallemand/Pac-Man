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

#define ROWS 36
#define COLUMNS 28
#define CELL_SIZE 25

class Cell; // Forward declaration (why??)
typedef std::array<std::array<Cell *, COLUMNS>, ROWS> Board; // Cell * ???

/**
 * \brief
 *
 */
enum GameState
{
    NORMAL,
    BLINK
};

// SDL_Rect normal_ = {200, 3, 168, 216};
// SDL_Rect blink_ = {200, 3, 168, 216};

class Game
{
public:
    Game() {}

    void display(SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL

private:
    static const int rows_ = ROWS;
    static const int columns_ = COLUMNS;
    int life_remaining_ = 3; //!< Life remaining
    int game_score_ = 0;     //!< Score
    // PacMan pacman_;                                         //!< Pac-Man!!
    std::vector<Ghost> ghosts_; //!< Ghosts
    // std::vector<Gomme> gommes_;                             //!< Gommes
    // std::vector<Fruit> fruits_;                             //!< Fruits
    Board board_;                                                                           //!< Board of cells
    std::array<SDL_Rect, 2> bg_ = {SDL_Rect{370, 3, 166, 216}, SDL_Rect{538, 3, 166, 216}}; //!< Background
};

#endif