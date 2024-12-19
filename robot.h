#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include "terrain.h"

const 

class robot
{public:

    enum direction {
        HAUT,
        GAUCHE,
        DROITE
    };

    robot();
    robot(const position& pos, direction d, const terrain& terrain) ;

    position positionSurTerrain() const;
    direction directionSurTerrain() const;
    terrain terrainDeLabyrinthe() const;

    robot&setPosition(const position& pos) ;
    robot& setDirection(direction d) ;
    robot& setTerrain(const terrain& terrain) ;
    
    bool detectObstacleFront() const;
    bool detectObstacleLeft() const;
    bool detectObstacleRight() const;
    robot& forward() ;
    robot& turnLeft() ;
    robot& turnRight() ;

    //ajoute des observateurs
    //notifie chaque observteurs (faut faire la manip d'etre notifier et tout)
private:
    position d_position;
    direction d_direction;
    terrain d_terrain;
    //le tableau des observateurs
    
};

#endif