#include "robot.h"

robot::robot() :
    d_position{}, d_direction{HAUT}
{}

robot::robot(const position& pos,direction d, const terrain& terrain) :
    d_position{pos}, d_direction{d}, d_terrain{terrain}
{}

position robot::positionSurTerrain() const
{
    return d_position;
}

robot::direction robot::directionSurTerrain() const
{
    return d_direction;
}

terrain robot::terrainDeLabyrinthe() const
{
    return d_terrain;
}

robot& robot::setPosition(const position& pos) 
{
    d_position = pos;
    return *this;
}

robot& robot::setDirection(direction d) 
{
    d_direction = d;
    return *this;
}

robot& robot::setTerrain(const terrain& terrain) 
{
    d_terrain = terrain;
    return *this;
}

bool robot::detectObstacle() const
{
    position pos;
    switch(d_direction) {
        case HAUT:
        pos = {d_position.positionLigne()-1,d_position.positionColonne()};
        break;
        case BAS:
        pos = {d_position.positionLigne()+1,d_position.positionColonne()};
        break;
        case DROITE:
        pos = {d_position.positionLigne(),d_position.positionColonne()+1};
        break;
        case GAUCHE:
        pos = {d_position.positionLigne(),d_position.positionColonne()-1};
        break;
  
    }
    return d_terrain.estUnMur(pos);

}

robot& robot::move()
{
    position pos;
    switch(d_direction) {
        case HAUT:
        d_position.setLigne(d_position.positionLigne()-1);
        break;
        case BAS:
        d_position.setLigne(d_position.positionLigne()+1);
        break;
        case DROITE:
        d_position.setColonne(d_position.positionColonne()+1);
        break;
        case GAUCHE:
        d_position.setColonne(d_position.positionColonne()-1);
        break;
  
    }
    return *this;
}

robot& robot::goUp() 
{
    setDirection(HAUT);
    return *this;
}

robot& robot::goDown() 
{
    setDirection(BAS);
    return *this;
}

robot& robot::turnLeft() 
{
    setDirection(GAUCHE);
    return *this;
}

robot& robot::turnRight() 
{
    setDirection(DROITE);
    return *this;
}
