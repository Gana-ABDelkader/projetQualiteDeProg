#include "algorithmeSortie.h"
#include <windows.h>

void exitMaze::reDirectionRobot(robot& r, const terrain& t) const{
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

void mainDroite::algoSortieMainDroite(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const{
    ecrire->printTerrain();
    observateur->observe(r);
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
        observateur->observe(r);
    }
    std::cout<<std::endl;
}

void mainDroite::exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur) const{
    robot r = lire->readTerrain();
    terrain t = r.terrainDeLabyrinthe();

    reDirectionRobot(r,t);
    algoSortieMainDroite(std::move(ecrire), std::move(observateur), r, t);
}


void pledge::instruction1(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const{
    ecrire->printTerrain();
    observateur->observe(r);
    if(r.positionSurTerrain() != t.caseSortie()){
         position posSuivante = r.calculateNewPosition();
    //J'avance tant que je tombe par sur un mur ou sur la sortie
        while(!r.detectObstacle(posSuivante)){
            r.setPosition(posSuivante);
            posSuivante = r.calculateNewPosition();
            ecrire->mettreRobotAJour(r);
            ecrire->printTerrain();
            observateur->observe(r);
        }
    }
    //Si je suis pas dehors je passe à l'instruction 2
    if(r.positionSurTerrain() != t.caseSortie()){
        instruction2(std::move(ecrire), std::move(observateur), r, t);
    }
}

void pledge::instruction2(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const{
    int compteurChangement{0};

    algoPledge(r,t,compteurChangement);
    ecrire->mettreRobotAJour(r);
    ecrire->printTerrain();
    observateur->observe(r);
    while(compteurChangement != 0 && r.positionSurTerrain() != t.caseSortie()){
        algoPledge(r,t,compteurChangement);
        ecrire->mettreRobotAJour(r);
        ecrire->printTerrain();
        observateur->observe(r);
    }
    if(r.positionSurTerrain() != t.caseSortie()){
        instruction1(std::move(ecrire), std::move(observateur), r, t);
    }
}

void pledge::algoPledge(robot& r, const terrain& t, int& compteurChangement) const{
    position posSuivante = r.calculateNewPosition();
    if(r.detectObstacle(posSuivante)){
        if(r.obstacleAdroite()){
            if(posSuivante == t.caseSortie()){
                r.setPosition(posSuivante);
            }
            else{
                if(r.positionADroite() == t.caseSortie()){
                    r.turnRight();
                    r.setPosition(r.calculateNewPosition());
                    compteurChangement--;
                }
                else{
                    r.turnLeft();
                    compteurChangement++;
                }
            }
        }
        else{
            if(r.obstacleAgauche()){
                r.turnRight();
            r.setPosition(r.calculateNewPosition());
            compteurChangement--;
            }
            else{
                r.turnLeft();
                compteurChangement++;
            }
        }
    }
    else{
        if(r.obstacleAdroite()){

            r.setPosition(posSuivante);
        }
        else{
            r.turnRight();
            r.setPosition(r.calculateNewPosition());
            compteurChangement--;
        }
    }
}

void pledge::exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur) const{
    robot r = lire->readTerrain();
    terrain t = r.terrainDeLabyrinthe();

    reDirectionRobot(r,t);
    instruction1(std::move(ecrire), std::move(observateur), r, t);
}

