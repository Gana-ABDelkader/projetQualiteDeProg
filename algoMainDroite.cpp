#include "algoMainDroite.h"
#include "read.h"
#include "save.h"

using fichiers::read;
using fichiers::print;



void mainDroite::reDirectionRobot(robot& r, const terrain& t) const{
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

void mainDroite::algoSortie(std::unique_ptr<print> ecrire, robot& r, const terrain& t) const{
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
                    }
                }
            }
            //Sinon je vais toujours le plus à droite pour attraper un mur à ma droite
            else{
                r.turnRight();
                r.setPosition(r.calculateNewPosition());
            }
        }
        else{
            //Si y'a un mur à droite frocément j'avance
            if(r.obstacleAdroite()){
                r.setPosition(posSuivante);
            }
            //Sinon je vais toujours le plus à droite pour attraper un mur à ma droite
            else{
                r.turnRight();
                r.setPosition(r.calculateNewPosition());
            }
        }
        ecrire->mettreRobotAJour(r);
        ecrire->printTerrain();
    }
}

void mainDroite::exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire) const{
    robot r = lire->readTerrain();
    terrain t = r.terrainDeLabyrinthe();

    reDirectionRobot(r,t);
    algoSortie(std::move(ecrire), r, t);
}
