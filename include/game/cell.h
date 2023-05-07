#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>

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

    Cell(int i, int j) : Object{CELL, j * gconst::game::object::cell::size, i * gconst::game::object::cell::size, gconst::game::object::cell::size, gconst::game::object::cell::size}
    {
    }

    Cell(int i, int j, Eatable<int> *eatable) : Object{CELL, j * gconst::game::object::cell::size, i * gconst::game::object::cell::size, gconst::game::object::cell::size, gconst::game::object::cell::size}, eatable_{eatable}
    {
    }

    Cell(int i, int j, CellType type) : Object{CELL, j * gconst::game::object::cell::size, i * gconst::game::object::cell::size, gconst::game::object::cell::size, gconst::game::object::cell::size}, cell_type_{type}
    {
    }

    CellType getCelltype() const
    {
        return cell_type_;
    }

    Eatable<int> *getEatable()
    {
        return eatable_;
    }

    bool isWall()
    {
        return (cell_type_ == WALL) || (cell_type_ == GHOST_WALL);
    }

    void setEatable(Eatable<int> *eatable)
    {
        eatable_ = eatable;
    }

private:
    CellType cell_type_ = EMPTY;      //!< Type of the cell
    Eatable<int> *eatable_ = nullptr; //!< Pointer to the eatable object currently in the cell
};

#endif