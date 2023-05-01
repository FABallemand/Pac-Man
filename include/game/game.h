#ifndef __GAME_H__
#define __GAME_H__

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>

#include "const.h"
#include "logger.h"
#include "timer.h"

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
using Board = std::array<std::array<Cell, gconst::game::nb_columns>, gconst::game::nb_rows>;

/**
 * \enum GameState
 * \brief Represents the stae of the Game object
 *
 */
enum GameState
{
    GAME_DEFAULT,
    GAME_BLINK,
    GAME_END,
    GAME_SUPER,
    GAME_SUPER_BLINK
};

/**
 * \class Game
 * \brief Represents a game of Pac-Man
 *
 */
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

    // Backkgroung state
    // void changeGameState()
    // {
    //     state_ = (state_ == NORMAL) ? BLINK : NORMAL;
    // }

    void run(SDL_Window *window, SDL_Surface *window_surface, SDL_Surface *sprite);

    bool update(const Uint8 *key_state, const float delta_t);

    void display(SDL_Window *window, SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL

private:
    // State ==================================================================
    int life_remaining_ = 3;        //!< Life remaining
    int game_score_ = 0;            //!< Score
    GameState state_ = GAME_DEFAULT; //!< Game state
    Timer state_timer_ = Timer();   //!< Timer
    // Objects ================================================================
    // Moveable
    PacMan pacman_{gconst::object::cell::size, gconst::object::cell::size * 13}; //!< Pac-Man!!
    Blinky blinky_{};
    Clyde clyde_{};
    Inky inky_{};
    Pinky pinky_{};
    std::vector<Ghost *> ghosts_; //!< Ghosts
    // std::array<Ghost, gconst::game::nb_ghosts> ghosts_{Blinky{}, Clyde{}, Inky{}, Pinky{}}; //!< Ghosts
    // Eatable
    std::array<Gomme, gconst::game::nb_gommes> gommes_;                  //!< Gommes
    std::array<SuperGomme, gconst::game::nb_super_gommes> super_gommes_; //!< Super-Gommes
    std::vector<Fruit> fruits_;                                          //!< Fruits
    Board board_;                                                        //!< Board of cells
    // Parameters =============================================================
    const std::array<SDL_Rect, 2> bg_ = {SDL_Rect{370, 3, gconst::game::maze_w, gconst::game::maze_h}, SDL_Rect{538, 3, gconst::game::maze_w, gconst::game::maze_h}}; //!< Background
    const SDL_Rect maze_position_{0, 0, 0, 0};                                                                                                                        //!< Maze position on the window

    static constexpr int gomme_offset_ = (gconst::object::cell::size - gconst::object::eatable::gomme::size) / 2;
    static constexpr int super_gomme_offset_ = (gconst::object::cell::size - gconst::object::eatable::super_gomme::size) / 2; // Declaration must be placed in gomme

    void createCell(int i, int j, int type);

    void loadMaze();

    CellNeighborhood createNeighborhood(int i, int j);

    void eatObject(Object *object);

    void updateScore(std::function<int(int)> effect)
    {
        if (effect != nullptr)
        {
            game_score_ = effect(game_score_);
        }
        else
        {
            LOG(DEBUG) << "NULL";
        }
    }

    /**
     * \brief Change state of the game and start timer if needed
     *
     * \param state New state of the game
     */
    void changeGameState(GameState state);

    /**
     * \brief Check for game state change
     *
     */
    void checkGameStateChange();
};

#endif