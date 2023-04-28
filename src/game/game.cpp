#include "game.h"

Game::Game()
{
    loadMaze();
    printf("TEST\n");
    ghosts_.push_back((Ghost *)&blinky_);
    ghosts_.push_back((Ghost *)&clyde_);
    ghosts_.push_back((Ghost *)&inky_);
    ghosts_.push_back((Ghost *)&pinky_);
}

void Game::run(SDL_Window *window, SDL_Surface *window_surface, SDL_Surface *sprite)
{
    // Timer
    Timer timer;
    timer.start();

    // Physics
    float previous_time = 0.f;
    float current_time = 0.f;

    // FPS
    int counted_frames = 0;

    // Main loop
    bool quit = false;
    while (!quit)
    {
        // LOG(INFO) << "NEW FRAME";

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
        float avgFPS = counted_frames / (timer.getTicks() / 1000.f); // Timer.getTicks() / 1000.f = current_time
        if (avgFPS > 2000000)
        {
            avgFPS = 0;
        }
        // LOG(INFO) << "FPS: " << avgFPS;

        // Update game
        previous_time = current_time;
        current_time = timer.getTicks() / 1000.f;
        quit = quit ? quit : update(key_state, current_time - previous_time);

        // Display
        display(window, sprite, window_surface);

        SDL_Delay(16); // If game is too slow -> go through walls...
        ++counted_frames;
    }
}

bool Game::update(const Uint8 *key_state, const float delta_t)
{
    // Update PacMan
    pacman_.update(key_state, delta_t);

    // Update PacMan neighborhood
    if (pacman_.getNeighborhood()[1][1] != &board_[pacman_.getY() / 32][pacman_.getX() / 32])
    {
        pacman_.setNeighborhood(createNeighborhood((pacman_.getY() + gconst::object::cell::size / 2) / gconst::object::cell::size, (pacman_.getX() + gconst::object::cell::size / 2) / gconst::object::cell::size));
    }

    // Eat
    Cell *cell_to_update = pacman_.getCurrentCell();
    Eatable *eatable = cell_to_update->getEatable();
    if (eatable)
    {
        eatObject(eatable);
        cell_to_update->setEatable(nullptr);
    }

    // Check game state change
    checkGameStateChange();

    // Check for end of the game
    if (pacman_.getState() == DEAD)
    {
        state_ = END;
        SDL_Delay(3000);
        return true;
    }
    return false;
}

void Game::display(SDL_Window *window, SDL_Surface *sprite, SDL_Surface *window_surface)
{
    // Clear window
    SDL_FillRect(window_surface, nullptr, 0);

    // Background/Maze
    if (state_ == BLINK)
    {
        SDL_BlitScaled(sprite, &(bg_[BLINK]), window_surface, nullptr);
    }
    else
    {
        SDL_BlitScaled(sprite, &(bg_[NORMAL]), window_surface, nullptr);
    }

    // Eatable
    for (Gomme g : gommes_) // Gommes
    {
        if (g.getState() != EATEN)
        {
            g.display(sprite, window_surface);
        }
    }
    for (SuperGomme sg : super_gommes_) // Super-Gommes
    {
        if (sg.getState() != EATEN)
        {
            sg.display(sprite, window_surface);
        }
    }
    // for (auto f : fruits_) // Fruits
    // {
    //     f.display();
    // }

    // Ghosts
    for (Ghost *g : ghosts_)
    {
        g->display(sprite, window_surface);
    }

    // Pac-Man
    pacman_.display(sprite, window_surface);

    // Update window
    if (SDL_UpdateWindowSurface(window) != 0)
    {
        LOG(ERROR) << "Window could not be updated! SDL Error: " << SDL_GetError();
        exit(1);
    }
}

void Game::createCell(int i, int j, int type)
{
    LOG(DEBUG) << "Game::createCell(" << i << "," << j << "," << type << ")";
    switch (type)
    {
    case 0:
        board_[i][j] = Cell{i, j}; // Create empty cell
        break;
    case 1:
        gommes_[Gomme::nb_gommes_].fillGomme(i, j);               // Create Gomme
        board_[i][j] = Cell{i, j, &(gommes_[Gomme::nb_gommes_])}; // Create empty Cell with Gomme inside
        // LOG(DEBUG) << "# gommes_ # i, j, type : " << gommes_[Gomme::nb_gommes_].getY() / gconst::object::cell::size << "," << gommes_[Gomme::nb_gommes_].getX() / gconst::object::cell::size << "," << gommes_[Gomme::nb_gommes_].getType();
        // LOG(DEBUG) << "# board_[i][j] # i, j, type : " << board_[i][j].getEatable()->getY() / gconst::object::cell::size << "," << board_[i][j].getEatable()->getX() / gconst::object::cell::size << "," << board_[i][j].getEatable()->getType();
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
        pacman_.setX(j * gconst::object::cell::size);
        pacman_.setY(i * gconst::object::cell::size);
        pacman_.setNeighborhood(createNeighborhood(i, j)); // Tell pacman where he is
        break;
    case 6:
        board_[i][j] = Cell{i, j};
        inky_.setX(j * gconst::object::cell::size);
        inky_.setY(i * gconst::object::cell::size);
        break;
    case 7:
        board_[i][j] = Cell{i, j};
        pinky_.setX(j * gconst::object::cell::size);
        pinky_.setY(i * gconst::object::cell::size);
        break;
    case 8:
        board_[i][j] = Cell{i, j};
        clyde_.setX(j * gconst::object::cell::size);
        clyde_.setY(i * gconst::object::cell::size);
        break;
    case 9:
        board_[i][j] = Cell{i, j};
        blinky_.setX(j * gconst::object::cell::size);
        blinky_.setY(i * gconst::object::cell::size);
        break;
    default:
        LOG(ERROR) << "Incorrect maze";
        break;
    }
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

    LOG(DEBUG) << "==== In loading maze ====";
    LOG(DEBUG) << "# gommes_ #";
    for (Gomme g : gommes_)
    {
        LOG(DEBUG) << "i, j, type : " << g.getY() / gconst::object::cell::size << "," << g.getX() / gconst::object::cell::size << "," << g.getType();
    }
    LOG(DEBUG) << "# board_ #";
    for (auto row : board_)
    {
        for (Cell c : row)
        {
            if (c.getEatable())
                LOG(DEBUG) << "i, j, type : " << c.getEatable()->getY() / gconst::object::cell::size << "," << c.getEatable()->getX() / gconst::object::cell::size << "," << c.getEatable()->getType();
        }
    }
    LOG(DEBUG) << "=========================";
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

void Game::eatObject(Object *object)
{
    switch (object->getType())
    {
    case GOMME:
    {
        auto it = std::find(gommes_.begin(), gommes_.end(), *object); // TEMPLATE
        if (it != gommes_.end())
        {
            updateScore(it->getEffect());
            LOG(DEBUG) << "game_score_ = " << game_score_;
            it->setState(EATEN);
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
            LOG(DEBUG) << "game_score_ = " << game_score_;
            it->setState(EATEN);
            changeGameState(SUPER);
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

    if (state == SUPER)
    {
        state_timer_.start();
        // pacman_.setState(SUPER); // Not very useful
        for (Ghost *g : ghosts_)
        {
            g->setState(VULNERABLE);
        }
    }
    else if (state == SUPER_BLINK)
    {
        state_timer_.start();
        for (Ghost *g : ghosts_)
        {
            g->setState(VULNERABLE_BLINK);
        }
    }
    else if (state_ != NORMAL && state == NORMAL)
    {
        for (Ghost *g : ghosts_)
        {
            g->setState(ALIVE);
        }
    }

    // Change state
    state_ = state;
}

void Game::checkGameStateChange()
{
    if (state_ == SUPER && state_timer_.getTicks() > gconst::game::super_duration)
    {
        changeGameState(SUPER_BLINK);
    }
    else if (state_ == SUPER_BLINK && state_timer_.getTicks() > gconst::game::blink_duration)
    {
        changeGameState(NORMAL);
    }
}