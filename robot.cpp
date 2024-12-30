#include "robot.h"
#include "observateur.h"

robot::robot() :
    d_position{}, d_direction{direction::BAS}, d_observateurs{}
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
        case direction::HAUT:
        pos = {d_position.positionLigne()-1,d_position.positionColonne()};
        break;
        case direction::BAS:
        pos = {d_position.positionLigne()+1,d_position.positionColonne()};
        break;
        case direction::DROITE:
        pos = {d_position.positionLigne(),d_position.positionColonne()+1};
        break;
        case direction::GAUCHE:
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
    d_direction = static_cast<direction>((static_cast<int>(d_direction)+3)%4);
    notifieTousLesObservateurs();
    return *this;
}

robot& robot::turnRight()
{
    d_direction = static_cast<direction>((static_cast<int>(d_direction)+1)%4);
    notifieTousLesObservateurs();
    return *this;
}

/*bool robot::obstacleAdroite() const
{
    robot robotTemp = *this;
    robotTemp.turnRight();
    return robotTemp.detectObstacle(robotTemp.calculateNewPosition());
}*/

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