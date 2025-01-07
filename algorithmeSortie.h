#ifndef ALGORITHMESORTIE_H
#define ALGORITHMESORTIE_H

#include <windows.h>
#include <memory>
#include "read.h"
#include "save.h"
#include "robot.h"
#include "manipulate.h"

using fichiers::read;
using fichiers::print;

class exitMaze{
public:
    virtual ~exitMaze() = default;
    ///Appel de l'Algorithme Main Droite
    virtual void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::vector<std::unique_ptr<observateur>> observateurs) = 0;
protected:
    ///Avance
    void avance(robot& r);
    ///Tourne a droite
    void tourneADroite(robot& r);
    ///Tourne a gauche
    void tourneAGauche(robot &r);
    ///Redirection du robot au cas ou il est mal placé au lancement
    void reDirectionRobot(robot& r, const terrain& t);
    ///Gestion des manipulations
    std::unique_ptr<manipulate> d_manip;
};

class mainDroite : public exitMaze{
public:
    void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::vector<std::unique_ptr<observateur>> observateurs) override;
private:
    ///Algorithme Main Droite
    void algoSortieMainDroite(std::unique_ptr<print> ecrire, robot& r, const terrain& t);
};

class pledge : public exitMaze{
public:
    void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::vector<std::unique_ptr<observateur>> observateurs) override;
private:
    ///Instruction 1 de l'algorithe de sortie pledge
    void instruction1(std::unique_ptr<print> ecrire, robot& r, const terrain& t);
    ///Instruction 2 de l'algorithe de sortie pledge
    void instruction2(std::unique_ptr<print> ecrire, robot& r, const terrain& t);
    ///Algorithme principal derrière l'utilisation de pledge
    void algoPledge(robot& r, const terrain& t, int& compteurChangement);
};


#endif //ALGORITHMESORTIE_H

