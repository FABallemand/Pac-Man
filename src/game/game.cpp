#include "game.h"

Game::Game()
{
    loadMaze();
}

void Game::run(SDL_Window *window, SDL_Surface *window_surface, SDL_Surface *sprite)
{
    // Timer
    Timer timer;
    timer.start();

    // Physics
    float previous_time = 0;
    float current_time = 0;

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
        // LOG(INFO) << "FPS: " << avgFPS; // to change

        // Update game
        previous_time = current_time;
        current_time = timer.getTicks() / 1000.f;
        quit = quit ? quit : update(key_state, current_time - previous_time);

        // Display
        display(window, sprite, window_surface);

        // SDL_Delay(500); // If game is too slow -> go through walls...
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
        pacman_.getNeighborhood()[1][1]->deletePacMan(&pacman_);
        board_[(pacman_.getY() + CELL_SIZE / 2) / CELL_SIZE][(pacman_.getX() + CELL_SIZE / 2) / CELL_SIZE].addObject(&pacman_);
        pacman_.setNeighborhood(createNeighborhood((pacman_.getY() + CELL_SIZE / 2) / CELL_SIZE, (pacman_.getX() + CELL_SIZE / 2) / CELL_SIZE));
    }

    // Update board (only need to update the cell where PacMan is located...)
    // Cell *cell_to_update = pacman_.getCurrentCell();
    // std::vector<Object *> &objects_to_update = cell_to_update->getObjects();
    // // LOG(DEBUG) << "beforebefore: " << cell_to_update->getNbObjects();
    // for (int i = 0; i < objects_to_update.size(); ++i)
    // {
    //     Object *eatable = objects_to_update[i];
    //     ObjectType object_type = eatable->getType();
    //     LOG(DEBUG) << "type: " << object_type;
    //     if (object_type == GOMME) // switch
    //     {
    //         // LOG(DEBUG) << "EATING A GOMME!!";
    //         // LOG(DEBUG) << "before: " << cell_to_update->getNbObjects();
    //         objects_to_update.erase(objects_to_update.begin() + i);
    //         // LOG(DEBUG) << "after: " << cell_to_update->getNbObjects();
    //         removeObject(GOMME, eatable);
    //         // ((Gomme *)eatable)->~Gomme(); // Useless ?
    //     }
    // }

    Cell *cell_to_update = pacman_.getCurrentCell();
    Eatable *eatable = cell_to_update->eatable;
    if (eatable && eatable->getType() == GOMME)
    {
        removeObject(GOMME, eatable);
        cell_to_update->eatable = nullptr;
    }

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
    SDL_BlitScaled(sprite, &(bg_[state_]), window_surface, nullptr);

    // Eatable
    for (Gomme g : gommes_) // Gommes
    {
        g.display(sprite, window_surface);
        LOG(DEBUG) << "i, j, type :" << g.getY() / CELL_SIZE << "," << g.getX() / CELL_SIZE << "," << g.getType();
    }
    for (SuperGomme sg : super_gommes_) // Super-Gommes
    {
        sg.display(sprite, window_surface);
    }
    // for (auto f : fruits_) // Fruits
    // {
    //     f.display();
    // }

    // Ghosts

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
        board_[i][j] = Cell{i, j};                                                          // Create empty cell
        gommes_.emplace_back(j * CELL_SIZE + gomme_offset_, i * CELL_SIZE + gomme_offset_); // Create gomme
        board_[i][j].addObject(&(gommes_[gommes_.size() - 1]));                             // Add gomme in the cell
        board_[i][j].eatable = &(gommes_[gommes_.size() - 1]);
        break;
    case 2:
        board_[i][j] = Cell{i, j};                                                                            // Create empty cell
        super_gommes_.emplace_back(j * CELL_SIZE + super_gomme_offset_, i * CELL_SIZE + super_gomme_offset_); // Create gomme
        board_[i][j].addObject(&super_gommes_.back());                                                        // Add gomme in the cell
        break;
    case 3:
        board_[i][j] = Cell{i, j, WALL}; // Create wall
        break;
    case 4:
        board_[i][j] = Cell{i, j, GHOST_WALL}; // Create special wall
        break;
    case 5:
        board_[i][j] = Cell{i, j};                         // Create empty cell
        board_[i][j].addObject(&pacman_);                  // Add pacman in the cell
        pacman_.setNeighborhood(createNeighborhood(i, j)); // Tell pacman where he is
        break;
    default:
        LOG(ERROR) << "Incorrect maze";
        break;
    }
}

void Game::loadMaze()
{
    // Open file
    std::ifstream level{"../assets/level/test.lvl", std::ios::in};

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

    for (Gomme g : gommes_)
    {
        LOG(DEBUG) << "i, j, type :" << g.getY() / CELL_SIZE << "," << g.getX() / CELL_SIZE << "," << g.getType();
    }
}

CellNeighborhood Game::createNeighborhood(int i, int j)
{
    CellNeighborhood res;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            res[x][y] = &board_[(i + x - 1) % NB_ROWS][(j + y - 1) % NB_COLUMNS];
        }
    }
    return res;
}

void Game::removeObject(ObjectType object_type, Object *object)
{
    if (object_type == GOMME)
    {
        LOG(DEBUG) << "REMOVING A GOMME";
        // for (int i = 0; i < gommes_.size(); ++i)
        // {
        //     if (&(gommes_[i]) == object)
        //     {
        //         LOG(DEBUG) << "gommes_.size() = " << gommes_.size();
        //         gommes_.erase(gommes_.begin() + i);
        //         LOG(DEBUG) << "gommes_.size() = " << gommes_.size();
        //     }
        // }

        auto it = std::find(gommes_.begin(), gommes_.end(), *object);
        // LOG(DEBUG) << "i, j = " << object->getX() / CELL_SIZE << "," << object->getY() / CELL_SIZE;
        if (it != gommes_.end())
        {
            // LOG(DEBUG) << "before1: " << gommes_.size();
            gommes_.erase(it);
            // LOG(DEBUG) << "after1: " << gommes_.size();
        }
        else
        {
            LOG(ERROR) << "object not found";
        }
    }
}