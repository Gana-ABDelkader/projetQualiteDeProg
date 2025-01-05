#ifndef LANCEMENTPROGRAMME_H
#define LANCEMENTPROGRAMME_H

#include <memory>
#include <fstream>

#include "read.h"
#include "save.h"
#include "observateur.h"
#include "algorithmeSortie.h"

using fichiers::read;
using fichiers::print;

class programme{
public:
    programme();
    void execute();
private:
    ///Les différents menu
    int menu();
    int menuAffichageTerrain();
    int menuChoixObservateur();
    int menuAlgoSortie();

    ///Les différents choix
    void choixAffichageTerrain();
    void choixObservateur();
    void choixAlgoSortie();

    ///Tous les choix des labyrinthes
    void labyrintheSimple();
    void labyrintheAmeliore1();
    void labyrintheAmeliore2();

    ///Tous les choix d'observateur
    ///??????

    ///Le traitement d'initialisation de lire et d'écrire avant d'exécuter les algos
    void traitement();

    ///Les deux algos possibles
    void algorithmeMainDroite();
    void algorithmePledge();

    std::unique_ptr<read> d_lire;
    int d_choixTerrain{0};
    std::unique_ptr<print> d_ecrire;
    std::unique_ptr<observateur> d_observateur;
    exitMaze d_algoSortie;
};


#endif //LANCEMENTPROGRAMME_H
