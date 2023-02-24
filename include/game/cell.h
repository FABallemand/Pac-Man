#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>
#include <typeinfo> // Maybe useless

#include "object.h"
#include "gomme.h"

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
    void addObject(Object *object);

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
     * \brief Display each object in the cell
     *
     */
    void display() const;

private:
    CellType type_;                 //!< Type of the cell
    std::vector<Object *> objects_; //!< Objects currently in the cell
};

#endif