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
typedef std::array<std::array<Cell *, NB_COLUMNS>, NB_ROWS> Board;

/**
 * \brief
 *
 */
enum GameState
{
    NORMAL,
    BLINK
};

class Game
{
public:
    Game()
    {
        int isWalled[NB_ROWS][NB_COLUMNS] = {
                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
                                    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1}, 
                                    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1}, 
                                    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1}, 
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
                                    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1}, 
                                    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1}, 
                                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 1, 1, 2, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 3, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {2, 2, 2, 2, 2, 0, 2, 2, 1, 0, 0, 0, 1, 2, 2, 0, 2, 2, 2, 2, 2}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1}, 
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
                                    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1}, 
                                    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
                                    {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1}, 
                                    {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1}, 
                                    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, 
                                    {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1}, 
                                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                                    };

        for(int i=0;i<NB_ROWS;i++)
        {
            for(int j=0;j<NB_COLUMNS;j++)
            {
                switch (isWalled[i][j])
                {
                case 0:
                    /* Create empty cell and add pac-gomme */
                    break;
                case 1:
                    /* Create Wall */
                    break;
                case 2:
                    /* Create empty cell without gomme*/
                    break;
                case 3:
                    /* code fantome Wall*/
                    break;
                case 4:
                    /* code empty cell and add super-pac-gomme*/
                    break;
                default:
                    break;
                }
            }
        }
    }

    void display(SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL

    void handleUserInputs(const Uint8 *key_state);

private:
    int life_remaining_ = 3;    //!< Life remaining
    int game_score_ = 0;        //!< Score
    GameState state_ = NORMAL;  //!< Game state
    PacMan pacman_{CELLSIZE, CELLSIZE};     //!< Pac-Man!!
    std::vector<Ghost> ghosts_; //!< Ghosts
    // std::vector<Gomme> gommes_;                             //!< Gommes
    // std::vector<Fruit> fruits_;                             //!< Fruits
    Board board_;                                                                                       //!< Board of cells
    std::array<SDL_Rect, 2> bg_ = {SDL_Rect{370, 3, MAZE_W, MAZE_H}, SDL_Rect{538, 3, MAZE_W, MAZE_H}}; //!< Background (add #define for width and heigth)

    SDL_Rect maze_position_{0,0, 0, 0};
};

#endif