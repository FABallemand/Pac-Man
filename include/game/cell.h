#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>

#include "object.h"

/**
 * \brief Type of cell
 *
 */
enum CellType
{
    CLEAR,
    WALL,
    GHOST_WALL
};

class Cell
{
public:
    Cell() : type_{CLEAR}, objects_{}
    {
    }

    Cell(std::vector<Object *> objects) : type_{CLEAR}, objects_{objects}
    {
    }

    Cell(CellType type) : type_{type}, objects_{}
    {
    }

    // GETTER

    // SETTER moveables and fruits

    // CHECKER

    // DESTROYER eatable and ghosts

    /**
     * \brief Display each object in the cell
     *
     */
    inline void display() const;

private:
    CellType type_;                 //!< Type of the cell
    std::vector<Object *> objects_; //!< Objects currently in the cell
};

#endif