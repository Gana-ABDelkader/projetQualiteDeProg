#ifndef LANCEMENTPROGRAMME_H
#define LANCEMENTPROGRAMME_H

#include "save.h"
#include "algorithmeSortie.h"
#include "observateur.h"
#include <memory>

class programme{
public:
    void execute();
private:
    void menu();
    void choixAffichageTerrain();
    void choixAlgoSortie();
    void choixObservateur();

    std::unique_ptr<fichiers::save> d_save;
    std::unique_ptr<exitMaze> d_algoSortie;
    std::unique_ptr<observateur> d_observateur;

};


#endif //LANCEMENTPROGRAMME_H