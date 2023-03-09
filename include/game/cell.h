#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>
#include <typeinfo> // Maybe useless
#include <algorithm>

#include "const.h"
#include "display_utils.h"
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
    GOMME,
    SUPER_GOMME,
    WALL,
    GHOST_WALL,
    PAC_MAN
};

class Cell : public Object
{
public:
    Cell(){};

    Cell(int i, int j) : Object{j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, type_{EMPTY}, objects_{}
    {
    }

    Cell(int i, int j, std::vector<Object *> objects) : Object{j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, type_{EMPTY}, objects_{objects}
    {
    }

    Cell(int i, int j, CellType type) : Object{j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, type_{type}, objects_{}
    {
    }

    CellType getCelltype() const
    {
        return type_;
    }

    std::vector<Object *> &getObjects()
    {
        return objects_;
    }

    /**
     * \brief Add a new object in the cell
     *
     * \param object Pointer to the object entering th cell
     */
    void addObject(Object *object)
    {
        objects_.push_back(object);
    }

    // TO BE TESTED...
    template <typename T>
    bool containObject()
    {
        for (Object *object : objects_)
        {
            if (typeid(object) == typeid(T))
            {
                return true;
            }
        }
        return false;
    }

    bool containGomme();

    bool containSuperGomme();

    bool containFruit();

    bool containGhost();

    bool containPacMan();

    /**
     * \brief
     *
     */
    void deleteEatable();

    /**
     * \brief
     *
     */
    void deleteGhost();

    /**
     * \brief
     *
     */
    void deletePacMan(PacMan * toDelete);

    inline bool isWalled()
    {
        return (type_ == WALL) || (type_ == GHOST_WALL);
    }

private:
    CellType type_;                 //!< Type of the cell
    std::vector<Object *> objects_; //!< Objects currently in the cell
};

#endif