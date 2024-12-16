#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include "terrain.h"


class robot
{public:
    robot(const position& pos, const terrain& terrain) ;

    position positionSurTerrain() const;
    terrain terrainDeLabyrinthe() const;

    void setPosition(const position& pos) ;
    
    bool detectObstacleFront() const;
    bool detectObstacleLeft() const;
    bool detectObstacleRight() const;
    void forward() ;
    void turnLeft() ;
    void turnRight() ;

    //ajoute des observateurs
    //notifie chaque observteurs (faut faire la manip d'etre notifier et tout)
private:
    position d_position;
    terrain d_terrain;
    //le tableau des observateurs
    
};

#endif