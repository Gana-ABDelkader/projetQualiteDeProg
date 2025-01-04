#include "algoPledge.h"
#include "terrain.h"
#include "robot.h"

/*
void pledge::instruction1(robot& r, terrain& t) const{
    position posSuivante = r.calculateNewPosition();
    //J'avance tant que je tombe par sur un mur ou sur la sortie
    while(!r.detectObstacle(posSuivante) && r.positionSurTerrain() != t.caseSortie()){
        r.setPosition(posSuivante);
    }
    //Si je suis pas dehors je passe à l'instruction 2
    if(r.positionSurTerrain() != t.caseSortie()){
        instruction2(r,t);
    }
}

void pledge::instruction2(robot& r, terrain& t) const{
    int compteurChangement{0};

}

void pledge::exit(robot& r, terrain& t) const{
    instruction1(r,t);
}
*/
