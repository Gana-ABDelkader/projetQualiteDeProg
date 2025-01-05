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
    virtual ~exitMaze() = default;
    ///Appel de l'Algorithme Main Droite
    virtual void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur) const = 0;

protected:
    ///Redirection du robot au cas ou il est mal placé au lancement
    void reDirectionRobot(robot& r, const terrain& t) const;
};

class mainDroite : public exitMaze{
public:
    void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur) const override;
private:
    ///Algorithme Main Droite
    void algoSortieMainDroite(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const;
};

class pledge : public exitMaze{
public:
    void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur) const override;
private:
    ///Instruction pour résoudre l'algo
    void instruction1(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const;
    void instruction2(std::unique_ptr<print> ecrire, std::unique_ptr<observateur> observateur, robot& r, const terrain& t) const;

    ///Composante principale de l'algo pledge
    void algoPledge(robot& r, const terrain& t, int& compteurChangement) const;
};


#endif //ALGORITHMESORTIE_H

