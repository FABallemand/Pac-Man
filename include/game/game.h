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

// Overlay
#include "pac_string.h"

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

    void run(SDL_Window *window, SDL_Surface *window_surface, SDL_Surface *sprite);

    bool update(const Uint8 *key_state, const float delta_t);

    void display(SDL_Window *window, SDL_Surface *sprite, SDL_Surface *window_surface); // No const due to SDL

private:
    // Physics ==================================================================
    float previous_time_ = 0.f;
    float current_time_ = 0.f;
    // State ==================================================================
    Timer game_timer_{};             //!< Global gmae timer
    int life_remaining_ = 3;         //!< Life remaining
    int game_score_ = 0;             //!< Score
    GameState state_ = GAME_DEFAULT; //!< Game state
    Timer state_timer_{};            //!< Timer
    int eating_streak_ = 0;          //!< Number of ghosts eaten in a row
    int level = 1;
    // Objects ================================================================
    Board board_; //!< Board of cells
    // Moveable
    PacMan pacman_{};               //!< Pac-Man!!
    Blinky blinky_{};               //!< Blinky (red)
    Clyde clyde_{};                 //!< Clyde (orange)
    Inky inky_{};                   //!< Inky (blue)
    Pinky pinky_{};                 //!< Pinky (pink)
    std::array<Ghost *, 4> ghosts_; //!< Ghosts
    // Eatable
    std::array<Gomme, gconst::game::nb_gommes> gommes_;                   //!< Gommes
    std::array<SuperGomme, gconst::game::nb_super_gommes> super_gommes_;  //!< Super-Gommes
    FruitType next_fruit_type_ = FRUIT_NONE;                              //!< Next type of fruit to appear
    int score_to_reach_ = gconst::object::eatable::fruit::spawn_interval; //!< Score to reach before next fruit
    Fruit fruit_{};                                                       //!< Fruit
    // Display ================================================================
    int frame_count_ = 0;                                                             //!< Frame count
    int current_sprite_ = 0;                                                          //!< Current sprite
    PacString score_string_{"score 0", gconst::game::score_x, gconst::game::score_y}; //!< Score display
    PacString life_string_{"$$$", gconst::game::life_x, gconst::game::life_y};        //!< Remaining life display
    PacString level_string_{"level 1", gconst::game::level_x, gconst::game::level_y}; //!< Level display
    // Parameters =============================================================
    static constexpr std::array<SDL_Rect, 2> bg_{SDL_Rect{370, 3, gconst::game::maze_w, gconst::game::maze_h}, SDL_Rect{541, 3, gconst::game::maze_w, gconst::game::maze_h}}; //!< Background
    static SDL_Rect maze_position_;                                                                                                                                           //!< Maze position on the window

    void createCell(int i, int j, int type);

    CellNeighborhood createNeighborhood(int i, int j);

    void loadMaze();

    void eatObject(Object *object);

    /**
     * \brief Handle battle or collision between Pac-Man and a ghost
     *
     * \param ghost Pointer to the ghost
     */
    void handleBattle(Ghost *ghost);

    void handleFruitBattle();

    /**
     * \brief Update score string
     *
     */
    void updateScoreString()
    {
        score_string_ = PacString("score " + std::to_string(game_score_), gconst::game::score_x, gconst::game::score_y);
    }

    /**
     * \brief Update score
     *
     * \param effect Lambda function used to update score
     */
    void updateScore(std::function<int(int)> effect)
    {
        if (effect != nullptr)
        {
            game_score_ = effect(game_score_);
        }
        updateScoreString();
    }

    /**
     * \brief Update score
     *
     * \param effect Lambda function used to update score
     */
    void updateScore(std::function<int(std::pair<int, int>)> effect)
    {
        if (effect != nullptr)
        {
            game_score_ = effect({game_score_, fruit_.getType()});
        }
        updateScoreString();
    }

    /**
     * \brief Update Pac-Man
     *
     * \param key_state State of the keyboard
     * \param delta_t Elapsed time between two frames
     */
    void updatePacMan(const Uint8 *key_state, const float delta_t);

    /**
     * \brief Update ghosts
     *
     * \param delta_t Elapsed time between two frames
     */
    void updateGhosts(const float delta_t);

    /**
     * \brief Update all eatables in the game (Gommes, SuperGommes, Fruits)
     *
     */
    void updateEatables();

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

    /**
     * \brief Reset Pac-Man and ghosts position (used when Pac-Man dies)
     *
     */
    void respawn();

    /**
     * \brief reinitialize the board
     *
     */
    void nextLevel();

    /**
     * \brief Quit the game when Pac-Man dies for the third time
     *
     * \return true If game is finished
     */
    bool quitGame();
    
    /**
     * \brief Make the board blink for time_ms millisecond
     * 
     * \param time_ms 
     * \param window 
     * \param sprite 
     * \param window_surface 
     */
    void blink_board(Uint32 time_ms, SDL_Window *window, SDL_Surface *sprite, SDL_Surface *window_surface);
};

#endif