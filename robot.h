#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include "terrain.h"

class robot
{public:

    enum direction {
        HAUT,
        BAS,
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
    
    bool detectObstacle() const;
    
    robot& move() ;
    
    robot& goUp() ;
    robot& goDown() ;
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