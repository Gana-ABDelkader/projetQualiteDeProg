#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
#include "terrain.h"
#include "observateur.h"
#include <vector>
#include <memory>

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

    robot& setPosition(const position& pos) ;
    robot& setDirection(direction d) ;
    robot& setTerrain(const terrain& terrain) ;
    

    // Il avance d'un pas de 1 dans sa direction 
    position calculateNewPosition() const;
    bool detectObstacle() const;
    robot& move() ;
    
    void goUp() ;
    void goDown() ;
    void turnLeft() ;
    void turnRight() ;

    void ajouterObservateur(std::unique_ptr<observateur> o);
    void notifieTousLesObservateurs() const ;
private:
    position d_position;
    direction d_direction;
    terrain d_terrain;
    std::vector<std::unique_ptr<observateur>> d_observateurs;
    
};

#endif