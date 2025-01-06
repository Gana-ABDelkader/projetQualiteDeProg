#include "algorithmeSortie.h"

void exitMaze::avance(robot& r){
    d_manip = std::make_unique<robotForward>();
    d_manip->move(r);
}

void exitMaze::tourneADroite(robot& r){
    d_manip = std::make_unique<robotRight>();
    d_manip->move(r);
}

void exitMaze::tourneAGauche(robot& r){
    d_manip = std::make_unique<robotLeft>();
    d_manip->move(r);
}

void exitMaze::reDirectionRobot(robot& r, const terrain& t){

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
                    tourneAGauche(r);
                    posSuivante = r.calculateNewPosition();
                }
            }
            else{
                tourneAGauche(r);
                posSuivante = r.calculateNewPosition();
            }
        }
    }
}

void mainDroite::algoSortieMainDroite(std::unique_ptr<print> ecrire, robot& r, const terrain& t) {
    ecrire->printTerrain();
    while(r.positionSurTerrain() != t.caseSortie()){
        position posSuivante = r.calculateNewPosition();
        if(r.detectObstacle(posSuivante)){
            if(r.obstacleAdroite()){
                if(posSuivante == t.caseSortie()){
                    avance(r);
                }
                else{
                    if(r.positionADroite() == t.caseSortie()){
                        tourneADroite(r);
                        avance(r);
                    }
                    else{
                        tourneAGauche(r);
                    }
                }
            }
            else{
                tourneADroite(r);
                avance(r);
            }
        }
        else{
            if(r.obstacleAdroite()){
                avance(r);
            }
            else{
                tourneADroite(r);
                avance(r);
            }
        }
        ecrire->mettreRobotAJour(r);
        ecrire->printTerrain();
        Sleep(500);
    }
    std::cout<<std::endl;
}

void mainDroite::exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::vector<std::unique_ptr<observateur>> observateurs) {
    robot r = lire->readTerrain();
    r.ajouterObservateurs(std::move(observateurs));
    terrain t = r.terrainDeLabyrinthe();

    reDirectionRobot(r,t);
    algoSortieMainDroite(std::move(ecrire), r, t);
}


void pledge::instruction1(std::unique_ptr<print> ecrire, robot& r, const terrain& t){
    ecrire->printTerrain();
    if(r.positionSurTerrain() != t.caseSortie()){
         position posSuivante = r.calculateNewPosition();
        while(!r.detectObstacle(posSuivante)){
            avance(r);
            posSuivante = r.calculateNewPosition();
            ecrire->mettreRobotAJour(r);
            ecrire->printTerrain();
            Sleep(500);
        }
    }
    if(r.positionSurTerrain() != t.caseSortie()){
        instruction2(std::move(ecrire), r, t);
    }
}

void pledge::instruction2(std::unique_ptr<print> ecrire, robot& r, const terrain& t){
    int compteurChangement{0};

    algoPledge(r,t,compteurChangement);
    ecrire->mettreRobotAJour(r);
    ecrire->printTerrain();
    while(compteurChangement != 0 && r.positionSurTerrain() != t.caseSortie()){
        algoPledge(r,t,compteurChangement);
        ecrire->mettreRobotAJour(r);
        ecrire->printTerrain();
        Sleep(500);
    }
    if(r.positionSurTerrain() != t.caseSortie()){
        instruction1(std::move(ecrire), r, t);
    }
}

void pledge::algoPledge(robot& r, const terrain& t, int& compteurChangement){
    position posSuivante = r.calculateNewPosition();
    if(r.detectObstacle(posSuivante)){
        if(r.obstacleAdroite()){
            if(posSuivante == t.caseSortie()){
                avance(r);
            }
            else{
                if(r.positionADroite() == t.caseSortie()){
                    tourneADroite(r);
                    avance(r);
                    compteurChangement--;
                }
                else{
                    tourneAGauche(r);
                    compteurChangement++;
                }
            }
        }
        else{
            if(r.obstacleAgauche()){
                tourneADroite(r);
                avance(r);
            compteurChangement--;
            }
            else{
                tourneAGauche(r);
                compteurChangement++;
            }
        }
    }
    else{
        if(r.obstacleAdroite()){
            avance(r);
        }
        else{
            tourneADroite(r);
            avance(r);
            compteurChangement--;
        }
    }
}

void pledge::exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::vector<std::unique_ptr<observateur>> observateurs){
    robot r = lire->readTerrain();
    terrain t = r.terrainDeLabyrinthe();
    r.ajouterObservateurs(std::move(observateurs));

    reDirectionRobot(r,t);
    instruction1(std::move(ecrire), r, t);
}

