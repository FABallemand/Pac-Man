#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>
#include <memory> // Maybe useless

#include "const.h"
#include "logger.h"
#include "object.h"

// Moveable
#include "pac_man.h"
#include "ghost.h"

// Eatable
#include "gomme.h"
#include "super_gomme.h"
#include "fruit.h"

/**
 * \brief Type of cell
 *
 */
enum CellType
{
    EMPTY,
    WALL,
    GHOST_WALL
};

class Cell : public Object
{
public:
    Cell() {} // Used by Board type

    Cell(int i, int j) : Object{CELL, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}
    {
    }

    Cell(int i, int j, Eatable *eatable) : Object{CELL, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, eatable_{eatable}
    {
    }

    Cell(int i, int j, CellType type) : Object{CELL, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, cell_type_{type}
    {
    }

    CellType getCelltype() const
    {
        return cell_type_;
    }

    Eatable *getEatable()
    {
        return eatable_;
    }

    bool isWall()
    {
        return (cell_type_ == WALL) || (cell_type_ == GHOST_WALL);
    }

    void setEatable(Eatable *eatable)
    {
        eatable_ = eatable;
    }

private:
    CellType cell_type_ = EMPTY; //!< Type of the cell
    Eatable *eatable_ = nullptr; //!< Pointer to the eatable object currently in the cell
};

#endif