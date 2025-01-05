#ifndef ALGORITHMESORTIE_H
#define ALGORITHMESORTIE_H

#include <memory>
#include "read.h"
#include "save.h"
#include "robot.h"

using fichiers::read;
using fichiers::print;

class exitMaze{
public:
    ///Appel de l'Algorithme Main Droite
    void algorithmeMainDroite(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur) const;

private:
    ///Redirection du robot au cas ou il est mal placé au lancement
    void reDirectionRobot(robot& r, const terrain& t) const;

    ///Algorithme Main Droite
    void algoSortieMainDroite(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const;

    void instruction1(std::unique_ptr<read> lire) const;
    void instruction2(std::unique_ptr<read> lire) const;
};


#endif //ALGORITHMESORTIE_H

