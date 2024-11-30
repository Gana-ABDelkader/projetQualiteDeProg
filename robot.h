#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"


class robot
{public:
    robot(const position& pos) ;
    position positionSurTerrain() const;
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
    //terrain
    //le tableau des observateurs
};

#endif