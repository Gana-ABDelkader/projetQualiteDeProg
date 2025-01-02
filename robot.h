#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include "terrain.h"
#include "direction.h"
#include "observateur.h"
#include <vector>
#include <memory>

class robot
{public:
    robot();
    robot(const position& pos, const direction& d, const terrain& terrain) ;
    robot(const robot& r) ;

    position positionSurTerrain() const;
    direction directionSurTerrain() const;
    terrain terrainDeLabyrinthe() const;

    robot& setPosition(const position& pos) ;
    robot& setDirection(const direction& d) ;
    robot& setTerrain(const terrain& terrain) ;


    // Il avance d'un pas de 1 dans sa direction
    position calculateNewPosition() const;
    bool detectObstacle(const position& pos) const;
    robot& move() ;

    //il fait des rotations de 90 degres
    robot& turnLeft()  ;
    robot& turnRight() ;

    bool obstacleAdroite() const;
    position positionADroite() const;

    void ajouterObservateur(std::unique_ptr<observateur> o);
    void notifieTousLesObservateurs() const ;
private:
    position d_position;
    direction d_direction;
    terrain d_terrain;
    std::vector<std::unique_ptr<observateur>> d_observateurs;

};

#endif
