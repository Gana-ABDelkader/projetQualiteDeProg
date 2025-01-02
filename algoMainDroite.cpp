#include "algoMainDroite.h"
#include "robot.h"
#include "terrain.h"
#include "direction.h"

#include <iostream>
using namespace std;

void mainDroite::reDirectionRobot(robot& r, terrain& t) const{
    position posSuivante = r.calculateNewPosition();
    bool condition = true;
    if(r.positionSurTerrain() != t.caseSortie()){
        while(condition){
            if(!t.sortDuTableau(posSuivante))
            {
                if(!r.detectObstacle(posSuivante) || posSuivante == t.caseSortie()){
                    condition = false;
                }
                else{
                    r.turnLeft();
                    posSuivante = r.calculateNewPosition();
                }
            }
            else{
                r.turnLeft();
                posSuivante = r.calculateNewPosition();
            }
        }
    }
}

void mainDroite::algoSortie(robot& r, terrain& t) const{
    //Tant que je suis pas dehors
    while(r.positionSurTerrain() != t.caseSortie()){
        position posSuivante = r.calculateNewPosition();
        //Est ce que je peux aller tout droit
        if(r.detectObstacle(posSuivante)){
            //Si y'a un mur à droite alors je vais à gauche
            if(r.obstacleAdroite()){
                //La sortie est un obstacle
                if(posSuivante == t.caseSortie()){
                    r.setPosition(posSuivante);
                }
                else{
                    //Si la sortie est à droite on y a va sinon on tourne à gauche
                    if(r.positionADroite() == t.caseSortie()){
                        r.turnRight();
                        r.setPosition(r.calculateNewPosition());
                    }
                    else{
                        r.turnLeft();
                        ///INCREMENTER LES OBSERVATEURS
                    }
                }
            }
            //Sinon je vais toujours le plus à droite pour attraper un mur à ma droite
            else{
                r.turnRight();
                ///INCREMENTER LES OBSERVATEURS
                r.setPosition(r.calculateNewPosition());
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
                r.setPosition(r.calculateNewPosition());
                ///INCREMENTER LES OBSERVATEURS
            }

        }
    }
}

void mainDroite::exit(robot& r, terrain& t) const {
    reDirectionRobot(r,t);
    algoSortie(r,t);
}
