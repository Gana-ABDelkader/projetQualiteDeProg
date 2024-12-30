#include"manipulate.h"

void robotForward::move(robot& r){
    r.move();
}

void robotLeft::move(robot& r){
    /* Changer la direction du robot : 
    
    si droite : haut
    si haut : gauche
    si gauche : bas
    si bas : droite

    */
   switch(r.directionSurTerrain()){
    case robot::direction::DROITE : r.goUp(); break;
    case robot::direction::BAS : r.turnRight(); break;
    case robot::direction::GAUCHE : r.goDown(); break;
    case robot::direction::HAUT : r.turnLeft(); break;
   }
}

void robotRight::move(robot& r){
    /* Changer la direction du robot : 
    
    si droite : bas
    si bas : gauche
    si gauche : haut
    si haut : droite

    */
   switch(r.directionSurTerrain()){
    case robot::direction::DROITE : r.goDown(); break;
    case robot::direction::BAS : r.turnLeft(); break;
    case robot::direction::GAUCHE : r.goUp(); break;
    case robot::direction::HAUT : r.turnRight(); break;
   }
}