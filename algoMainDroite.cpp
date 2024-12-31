#include "algoMainDroite.h"
#include "robot.h"
#include "terrain.h"
#include "direction.h"

void mainDroite::exit(robot& r, terrain& t) const {
    //Tant que je suis pas dehors
    while(r.positionSurTerrain().positionColonne() != t.caseSortie().positionColonne() && r.positionSurTerrain().positionLigne() != t.caseSortie().positionLigne()){
        position posSuivante = r.calculateNewPosition();
        //Est ce que je peux aller tout droit
        if(r.detectObstacle(posSuivante)){
            //Si y'a un mur à droite alors je vais à gauche
            if(r.obstacleAdroite()){
                r.turnLeft();
                ///INCREMENTER LES OBSERVATEURS
            }
            //Sinon je vais à droite et j'avance
            else{
                r.turnRight();
                ///INCREMENTER LES OBSERVATEURS
                r.setPosition(posSuivante);
                ///INCREMENTER LES OBSERVATEURS
            }
        }
        else{
            //Si y'a un mur à droite frocément j'avance
            if(r.obstacleAdroite()){
                r.setPosition(posSuivante);
                ///INCREMENTER LES OBSERVATEURS
            }
            //Sinon je vais toujours le plus à droite pour attraper un mur à ma droite
            else{
                r.turnRight();
                ///INCREMENTER LES OBSERVATEURS
                r.setPosition(posSuivante);
                ///INCREMENTER LES OBSERVATEURS
            }

        }
    }
}