#include "robot.h"
#include "observateur.h"

robot::robot() :
    d_position{}, d_direction{}, d_terrain{}, d_observateurs{}
{}

robot::robot(const position& pos,const direction& d, const terrain& terrain) :
    d_position{pos}, d_direction{d}, d_terrain{terrain}, d_observateurs{}
{}

robot::robot(const robot& r) :
    d_position{r.d_position}, d_direction{r.d_direction}, d_terrain{r.d_terrain}, d_observateurs{}
{
    for(const auto& observateur : r.d_observateurs) {
        ajouterObservateur(observateur->clone());
    }
}

position robot::positionSurTerrain() const
{
    return d_position;
}

direction robot::directionSurTerrain() const
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

robot& robot::setDirection(const direction& d) 
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
    switch(d_direction.valeurDirection()) {
        case direction::valeur::HAUT:
        pos = {d_position.positionLigne()-1,d_position.positionColonne()};
        break;
        case direction::valeur::BAS:
        pos = {d_position.positionLigne()+1,d_position.positionColonne()};
        break;
        case direction::valeur::DROITE:
        pos = {d_position.positionLigne(),d_position.positionColonne()+1};
        break;
        case direction::valeur::GAUCHE:
        pos = {d_position.positionLigne(),d_position.positionColonne()-1};
        break;
  
    }
    return pos;
}

bool robot::detectObstacle(const position& pos) const
{
    return d_terrain.estUnMur(pos);
}

robot& robot::move()
{
    position pos = calculateNewPosition();
    if(!detectObstacle(pos)) {
        d_position = pos;
        notifieTousLesObservateurs();
    }
    return *this;

}

robot& robot::turnLeft() 
{
    d_direction.RotateLeft();
    notifieTousLesObservateurs();
    return *this;
}

robot& robot::turnRight()
{
    d_direction.RotateRight();
    notifieTousLesObservateurs();
    return *this;
}

bool robot::obstacleAdroite() const
{
    robot robotTemp = *this;
    robotTemp.turnRight();
    return robotTemp.detectObstacle(robotTemp.calculateNewPosition());
}

void robot::ajouterObservateur(std::unique_ptr<observateur> o)
{
    d_observateurs.push_back(std::move(o));
    //o->observe(*this);
}

void robot::notifieTousLesObservateurs() const
{
    for(const auto& observateur : d_observateurs) {
        observateur->observe(*this);
    }
}