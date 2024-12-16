#include "robot.h"

robot::robot(const position& pos, const terrain& terrain) :
    d_position{pos}, d_terrain{terrain}
{}

position robot::positionSurTerrain() const
{
    return d_position;
}

terrain robot::terrainDeLabyrinthe() const
{
    return d_terrain;
}

void robot::setPosition(const position& pos) 
{
    d_position = pos;
}

bool robot::detectObstacleFront() const
{
    position pos{d_position.positionLigne()-1,d_position.positionColonne()};
    return d_terrain.estUnMur(pos);

}

bool robot::detectObstacleLeft() const
{
    position pos{d_position.positionLigne(),d_position.positionColonne()-1};
    return d_terrain.estUnMur(pos);
}

bool robot::detectObstacleRight() const
{
    position pos{d_position.positionLigne(),d_position.positionColonne()+1};
    return d_terrain.estUnMur(pos);
}

void robot::forward()
{
    d_position.setLigne(d_position.positionLigne()-1);
}

void robot::turnLeft() 
{
    d_position.setColonne(d_position.positionColonne()-1);
}

void robot::turnRight() 
{
    d_position.setColonne(d_position.positionColonne()+1);
}
