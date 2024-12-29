#include "robot.h"

robot::robot() :
    d_position{}, d_direction{BAS}, d_observateurs{}
{}

robot::robot(const position& pos,direction d, const terrain& terrain) :
    d_position{pos}, d_direction{d}, d_terrain{terrain}, d_observateurs{}
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

position robot::calculateNewPosition() const
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
    return pos;
}

bool robot::detectObstacle() const
{
    return d_terrain.estUnMur(calculateNewPosition());
}

robot& robot::move()
{
    if(!detectObstacle()) {
        d_position = calculateNewPosition();
        notifieTousLesObservateurs();
    }
    return *this;

}

void robot::goUp() 
{
    setDirection(HAUT);
    notifieTousLesObservateurs();
}

void robot::goDown() 
{
    setDirection(BAS);
    notifieTousLesObservateurs();
}

void robot::turnLeft() 
{
    setDirection(GAUCHE);
    notifieTousLesObservateurs();
}

void robot::turnRight() 
{
    setDirection(DROITE);
    notifieTousLesObservateurs();
}

void robot::ajouterObservateur(std::unique_ptr<observateur> o)
{
    d_observateurs.push_back(std::move(o));
}

void robot::notifieTousLesObservateurs() const
{
    for(const auto& observateur : d_observateurs) {
        observateur->observe(*this);
    }
}