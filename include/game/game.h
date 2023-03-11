#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <vector>
#include <array>

#include "const.h"
#include "display_utils.h"

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

class Cell; // Forward declaration (why??)
using Board = std::array<std::array<Cell, NB_COLUMNS>, NB_ROWS>;

/**
 * \enum GameState
 * \brief Represents the stae of the Game object
 *
 */
enum GameState
{
    NORMAL,
    BLINK,
    END
};

class Game
{
public:
    Game();

    int getLifeRemaining() const
    {
        return life_remaining_;
    }

    int getGameScore() const
    {
        return game_score_;
    }

    GameState getGameState() const
    {
        return state_;
    }

    void setGameScore(int new_game_score)
    {
        game_score_ = new_game_score;
    }

    void incGameScore()
    {
        ++game_score_;
    }

    void changeGameState()
    {
        state_ = state_ == NORMAL ? BLINK : NORMAL;
    }

    bool update(const Uint8 *key_state, const float delta_t);

    void display(SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL

private:
    int life_remaining_ = 3;                   //!< Life remaining
    int game_score_ = 0;                       //!< Score
    GameState state_ = NORMAL;                 //!< Game state
    PacMan pacman_{CELL_SIZE, CELL_SIZE * 13}; //!< Pac-Man!!
    // std::vector<Ghost> ghosts_ = std::vector<Ghost>{Blinky{}, Clyde{}, Inky{}, Pinky{}};                //!< Ghosts
    std::vector<Ghost> ghosts_;                                                                         //!< Ghosts
    std::vector<Gomme> gommes_;                                                                         //!< Gommes
    std::vector<Fruit> fruits_;                                                                         //!< Fruits
    Board board_;                                                                                       //!< Board of cells
    std::array<SDL_Rect, 2> bg_ = {SDL_Rect{370, 3, MAZE_W, MAZE_H}, SDL_Rect{538, 3, MAZE_W, MAZE_H}}; //!< Background
    SDL_Rect maze_position_{0, 0, 0, 0};                                                                //!< Maze position on the window
    static constexpr int offset_gomme_ = (CELL_SIZE - GOMME_SIZE) / 2;
    static constexpr int offset_super_gomme_ = (CELL_SIZE - SUPER_GOMME_SIZE) / 2;

    void endOfGame();
    CellNeighborhood createNeighborhood(int i, int j);
};

#endif