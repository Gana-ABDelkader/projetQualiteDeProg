#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <vector>
#include "position.h"
#include <string>
#include "testCasesVector.h"
#include "caractereLabyrinthe.h"

class terrain;
class robot;

namespace fichiers{

class print
{
public:
    print(std::ostream& ost,const robot& r);
    virtual ~print() =default;
    virtual void printTerrain() =0;
protected:
    testCasesVector d_labyrinthe;
    position d_entree;
    position d_sortie;
    position d_posRobot;
    std::ostream& d_ost;
private:
    virtual std::string traiterCasesVecteur2D(int ligne, int colonne) const =0;
    virtual void enregistreLigne(int ligne) =0;
};



class printSimple : public print
{
public:
    printSimple(std::ostream& ost,const robot& r);
    void printTerrain() override;
private:
    std::string traiterCasesVecteur2D(int ligne, int colonne) const override;
    void enregistreLigne(int ligne) override;
};



class printAmeliore1 : public print
{
public:
    printAmeliore1(std::ostream& ost,const robot& r);
    void printTerrain() override;
private:
    caractereLabyrintheAmeliore1 d_labyr;

    std::string traiterCasesVecteur2D(int ligne, int colonne) const override;
    void enregistreLigne(int ligne) override;
};



class printAmeliore2 : public print
{
public:
    printAmeliore2(std::ostream& ost,const robot& r);
    void printTerrain() override;
private:
    caractereLabyrintheAmeliore2 d_labyr;

    std::string traiterCasesVecteur2D(int ligne, int colonne) const override;
    void enregistreLigne(int ligne) override;
    std::string renvoieBonCararactereInterieur(int i, int j) const;
    std::string renvoieBonCararactereExterieur(int ligne, int colonne) const;

};

}

#endif // SAVE_H
