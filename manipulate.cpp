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
   r.turnLeft();
}

void robotRight::move(robot& r){
    /* Changer la direction du robot : 
    
    si droite : bas
    si bas : gauche
    si gauche : haut
    si haut : droite

    */
   r.turnRight();
}