#include "game.h"

SDL_Rect Game::maze_position_{0, 0, gconst::game::nb_columns *gconst::game::object::cell::size, gconst::game::nb_rows *gconst::game::object::cell::size};

Game::Game()
{
    // Load maze
    loadMaze();

    // Fill vector of ghosts
    ghosts_[0] = (Ghost *)&blinky_;
    ghosts_[1] = (Ghost *)&clyde_;
    ghosts_[2] = (Ghost *)&inky_;
    ghosts_[3] = (Ghost *)&pinky_;
}

void Game::run(SDL_Window *window, SDL_Surface *window_surface, SDL_Surface *sprite)
{
    // Timer
    game_timer_.start();

    // FPS
    int counted_frames = 0;

    // Main loop
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        // Keyboard
        const Uint8 *key_state = SDL_GetKeyboardState(nullptr);
        if (key_state[SDL_SCANCODE_ESCAPE])
        {
            quit = true;
        }

        // Calculate and correct fps
        float avgFPS = counted_frames / (game_timer_.getTicks() / 1000.f); // Timer.getTicks() / 1000.f = current_time
        if (avgFPS > 2000000)
        {
            avgFPS = 0;
        }
        // LOG(INFO) << "FPS: " << avgFPS;

        // Update game
        previous_time_ = current_time_;
        current_time_ = game_timer_.getTicks() / 1000.f;
        quit = quit ? quit : update(key_state, current_time_ - previous_time_);

        // Display
        if (state_ == GAME_BLINK)
        {
            blinkBoard(gconst::game::blink_duration, window, sprite, window_surface);
            changeGameState(GAME_DEFAULT);
        }
        else
        {
            display(window, sprite, window_surface);
        }

        SDL_Delay(16); // If game is too slow -> go through walls...
        ++counted_frames;
    }
}

bool Game::update(const Uint8 *key_state, const float delta_t)
{
    // Update Pac-Man
    updatePacMan(key_state, delta_t);

    // Update Ghosts
    updateGhosts(delta_t);

    // Update eatables
    updateEatables();

    // Check game state change
    checkGameStateChange();

    // Respawn if Pac-Man is dead
    if (pacman_.getState() == PACMAN_DEAD)
    {
        if (life_remaining_ > 0)
        {
            respawn();
        }
        else
        {

            return quitGame();
        }
    }

    // Change level
    if (Gomme::nb_gommes_ == 0 && SuperGomme::nb_super_gommes_ == 0)
    {
        nextLevel();
    }
    return false;
}

void Game::display(SDL_Window *window, SDL_Surface *sprite, SDL_Surface *window_surface)
{
    // Clear window
    SDL_FillRect(window_surface, nullptr, 0);

    // Background/Maze
    displayMaze();

    // Eatable
    displayeatable();

    // Ghosts
    displayGhosts();

    // Pac-Man
    pacman_.display(sprite, window_surface);

    // Overlay
    displayOverlay();

    // Update window
    if (SDL_UpdateWindowSurface(window) != 0)
    {
        LOG(ERROR) << "Window could not be updated! SDL Error: " << SDL_GetError();
        exit(1);
    }
}

void Game::respawn()
{
    SDL_Delay(1000);
    pacman_.respawn();
    pacman_.setNeighborhood(createNeighborhood(pacman_.getI(), pacman_.getJ()));
    for (Ghost *g : ghosts_)
    {
        g->respawn();
    }
}

bool Game::quitGame()
{
    LOG(INFO) << "GAME OVER!!!";
    LOG(INFO) << "YOUR SCORE IS: " << game_score_;
    SDL_Delay(2000);

    return true;
}

void Game::createCell(int i, int j, int type)
{
    // LOG(DEBUG) << "Game::createCell(" << i << "," << j << "," << type << ")";
    switch (type)
    {
    case 0:
        board_[i][j] = Cell{i, j}; // Create empty cell
        break;
    case 1:
        gommes_[Gomme::nb_gommes_].fillGomme(i, j);               // Create Gomme
        board_[i][j] = Cell{i, j, &(gommes_[Gomme::nb_gommes_])}; // Create empty Cell with Gomme inside
        ++Gomme::nb_gommes_;
        break;
    case 2:
        super_gommes_[SuperGomme::nb_super_gommes_].fillSuperGomme(i, j);          // Create SuperGomme
        board_[i][j] = Cell{i, j, &(super_gommes_[SuperGomme::nb_super_gommes_])}; // Create empty Cell with SuperGomme inside
        ++SuperGomme::nb_super_gommes_;
        break;
    case 3:
        board_[i][j] = Cell{i, j, WALL}; // Create wall
        break;
    case 4:
        board_[i][j] = Cell{i, j, GHOST_WALL}; // Create special wall
        break;
    case 5:
        board_[i][j] = Cell{i, j}; // Create empty cell
        pacman_.setX(j * gconst::game::object::cell::size);
        pacman_.setY(i * gconst::game::object::cell::size);
        pacman_.setNeighborhood(createNeighborhood(i, j)); // Tell pacman where he is
        break;
    case 6:
        board_[i][j] = Cell{i, j};
        inky_.setX(j * gconst::game::object::cell::size);
        inky_.setY(i * gconst::game::object::cell::size);
        break;
    case 7:
        board_[i][j] = Cell{i, j};
        pinky_.setX(j * gconst::game::object::cell::size);
        pinky_.setY(i * gconst::game::object::cell::size);
        break;
    case 8:
        board_[i][j] = Cell{i, j};
        clyde_.setX(j * gconst::game::object::cell::size);
        clyde_.setY(i * gconst::game::object::cell::size);
        break;
    case 9:
        board_[i][j] = Cell{i, j};
        blinky_.setX(j * gconst::game::object::cell::size);
        blinky_.setY(i * gconst::game::object::cell::size);
        break;
    default:
        LOG(ERROR) << "Incorrect maze";
        break;
    }
}

CellNeighborhood Game::createNeighborhood(int i, int j)
{
    CellNeighborhood res;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            res[x][y] = &board_[(i + x - 1) % gconst::game::nb_rows][(j + y - 1) % gconst::game::nb_columns];
        }
    }
    return res;
}

void Game::loadMaze()
{
    // Open file
    std::ifstream level{"../assets/level/maze.lvl", std::ios::in};

    if (level.is_open())
    {
        int row = 0;
        std::string line;
        const std::string delimiter = ",";
        while (std::getline(level, line))
        {
            size_t start_pos = 0;
            size_t end_pos;
            int col = 0;
            while ((end_pos = line.find(delimiter, start_pos)) != std::string::npos)
            {
                std::string cell_type = line.substr(start_pos, end_pos);
                createCell(row, col, std::stoi(cell_type));
                start_pos = end_pos + delimiter.length();
                ++col;
            }
            ++row;
        }
    }
    else
    {
        LOG(ERROR) << "Unable to open level file";
    }

    // Close file
    level.close();
}

void Game::handleBattle(Ghost *ghost)
{
    if (pacman_.getState() != PACMAN_ALIVE)
    {
        return;
    }

    // If ghost and Pac-Man are on the same cell
    else if (ghost->getI() == pacman_.getI() && ghost->getJ() == pacman_.getJ())
    {
        if (ghost->getState() == GHOST_DEFAULT)
        {
            // Pac-man lose a life and the postion of pacman (and the ghosts) are reset
            pacman_.setState(PACMAN_DYING);
            for (Ghost *g : ghosts_)
            {
                g->setState(GHOST_STOP);
            }
            --life_remaining_;
            life_string_ = PacString(std::string(life_remaining_, '$'), gconst::game::life_x, gconst::game::life_y);
        }
        else if (ghost->getState() == GHOST_VULNERABLE || ghost->getState() == GHOST_VULNERABLE_BLINK)
        {
            // Pac-Man eat ghost and ghost goes back to its initial position
            ghost->setState(GHOST_EATEN);
            eating_streak_ += 1;
            game_score_ += gconst::game::object::moveable::ghost::score * pow(2, eating_streak_);
        }
    }
}

void Game::handleFruitBattle()
{
    if (pacman_.getI() == fruit_.getI() && pacman_.getJ() == fruit_.getJ())
    {
        updateScore(fruit_.getEffect());
        fruit_.setFruitType(FRUIT_NONE);
    }
}

void Game::updatePacMan(const Uint8 *key_state, const float delta_t)
{
    // Update Pac-Man
    pacman_.update(key_state, delta_t);

    // Update Pac-Man neighborhood
    if (pacman_.getNeighborhood()[1][1] != &board_[pacman_.getY() / gconst::game::object::cell::size][pacman_.getX() / gconst::game::object::cell::size])
    {
        pacman_.setNeighborhood(createNeighborhood(pacman_.getI(), pacman_.getJ()));
    }
}

void Game::updateGhosts(const float delta_t)
{
    // Update Ghosts
    for (Ghost *g : ghosts_)
    {
        g->update(delta_t, pacman_.getI(), pacman_.getJ(), pacman_.getDirection());
        handleBattle(g);
    }
}

void Game::updateEatables()
{
    // Gommes and SuperGommes
    Cell *cell_to_update = pacman_.getCurrentCell();
    Eatable<int> *eatable = cell_to_update->getEatable();
    if (eatable)
    {
        eatObject(eatable);
        cell_to_update->setEatable(nullptr);
    }

    for (SuperGomme &sg : super_gommes_)
    {
        sg.updateSprite();
    }

    // Fruits
    if (fruit_.getFruitType() != FRUIT_NONE)
    {
        fruit_.update();
        handleFruitBattle();
    }
    if (game_score_ > score_to_reach_)
    {
        int next_fruit_type = (static_cast<int>(next_fruit_type_) + 1) % gconst::game::object::eatable::fruit::nb_fruit_type;
        next_fruit_type_ = static_cast<FruitType>(next_fruit_type == 0 ? ++next_fruit_type : next_fruit_type);
        fruit_.setFruitType(next_fruit_type_);
        score_to_reach_ += gconst::game::object::eatable::fruit::spawn_interval;
    }
}

void Game::eatObject(Object *object)
{
    switch (object->getType())
    {
    case GOMME:
    {
        auto it = std::find(gommes_.begin(), gommes_.end(), *object);
        if (it != gommes_.end())
        {
            updateScore(it->getEffect());
            it->setState(EATABLE_EATEN);
            --Gomme::nb_gommes_;
        }
        else
        {
            LOG(ERROR) << "Unable to find object";
        }
        break;
    }
    case SUPER_GOMME:
    {
        auto it = std::find(super_gommes_.begin(), super_gommes_.end(), *object);
        if (it != super_gommes_.end())
        {
            updateScore(it->getEffect());
            it->setState(EATABLE_EATEN);
            --SuperGomme::nb_super_gommes_;
            changeGameState(GAME_SUPER);
        }
        else
        {
            LOG(ERROR) << "Unable to find object";
        }
        break;
    }
    default:
        LOG(ERROR) << "PacMan cannot eat this type of object...beark";
    }
}

void Game::changeGameState(GameState state)
{

    switch (state)
    {
    case GAME_SUPER:
        state_timer_.start();
        for (Ghost *g : ghosts_)
        {
            g->setState(GHOST_VULNERABLE);
        }
        break;
    case GAME_SUPER_BLINK:
        state_timer_.start();
        for (Ghost *g : ghosts_)
        {
            if (g->getState() == GHOST_VULNERABLE)
            {
                g->setState(GHOST_VULNERABLE_BLINK);
            }
        }
        break;
    case GAME_DEFAULT:
        if (state_ != GAME_DEFAULT)
        {
            for (Ghost *g : ghosts_)
            {
                g->setState(GHOST_DEFAULT);
            }
            eating_streak_ = 0;
        }
        break;
    default:
        break;
    }

    // Change state
    state_ = state;
}

void Game::checkGameStateChange()
{
    if (state_ == GAME_SUPER && state_timer_.getTicks() > gconst::game::super_duration)
    {
        changeGameState(GAME_SUPER_BLINK);
    }
    else if (state_ == GAME_SUPER_BLINK && state_timer_.getTicks() > gconst::game::blink_duration)
    {
        changeGameState(GAME_DEFAULT);
    }
}

void Game::nextLevel()
{
    level_string_ = PacString("level " + std::to_string(++level), gconst::game::level_x, gconst::game::level_y);

    // Stop ghosts
    for (Ghost *g : ghosts_)
    {
        g->setState(GHOST_STOP);
    }

    // Remove fruit
    fruit_.setFruitType(FRUIT_NONE);

    // Game
    changeGameState(GAME_BLINK);
    game_timer_.stop();
    previous_time_ = 0.f;
    current_time_ = 0.f;

    // Gommes and SuperGommes
    loadMaze(); // Place gommes in cells
    for (Gomme &g : gommes_)
    {
        g.setState(EATABLE_DEFAULT);
    }
    for (SuperGomme &sg : super_gommes_)
    {
        sg.setState(EATABLE_DEFAULT);
    }

    // Pac-Man and Ghosts
    respawn();

    game_timer_.start();
}

void Game::blinkBoard(uint32_t time_ms, SDL_Window *window, SDL_Surface *sprite, SDL_Surface *window_surface)
{
    game_timer_.start();
    while (game_timer_.getTicks() < time_ms)
    {
        display(window, sprite, window_surface);
    }
    game_timer_.stop();
    game_timer_.start();
}