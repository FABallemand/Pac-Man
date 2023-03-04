#include "cell.h"

bool Cell::containGomme()
{
    for (Object *object : objects_)
    {
        if (typeid(object) == typeid(Gomme *))
        {
            return true;
        }
    }
    return false;
}

bool Cell::containSuperGomme()
{
    for (Object *object : objects_)
    {
        if (typeid(object) == typeid(SuperGomme *))
        {
            return true;
        }
    }
    return false;
}

bool Cell::containFruit()
{
    for (Object *object : objects_)
    {
        if (typeid(object) == typeid(Fruit *))
        {
            return true;
        }
    }
    return false;
}

bool Cell::containGhost()
{
    for (Object *object : objects_)
    {
        if (typeid(object) == typeid(Ghost *))
        {
            return true;
        }
    }
    return false;
}

bool Cell::containPacMan()
{
    for (Object *object : objects_)
    {
        if (typeid(object) == typeid(PacMan *))
        {
            return true;
        }
    }
    return false;
}

void Cell::deleteEatable()
{
}

void Cell::deleteGhost()
{
}