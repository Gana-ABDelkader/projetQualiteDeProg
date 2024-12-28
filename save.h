#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <vector>
#include "position.h"
#include <string>
#include "testCasesVector.h"
#include "caractereLabyrinthe.h"

class terrain;

namespace fichiers{

class save
{
public:
    save(std::ostream& ost,const terrain& t);
    virtual ~save() =default;
    virtual void saveTerrain() =0;
protected:
    testCasesVector d_labyrinthe;
    position d_entree;
    position d_sortie;
    std::ostream& d_ost;
private:
    virtual std::string traiterCasesVecteur2D(int ligne, int colonne) const =0;
    virtual void enregistreLigne(int ligne) =0;
};



class saveSimple : public save
{
public:
    saveSimple(std::ostream& ost,const terrain& t);
    void saveTerrain() override;
private:
    std::string traiterCasesVecteur2D(int ligne, int colonne) const override;
    void enregistreLigne(int ligne) override;
};



class saveAmeliore1 : public save
{
public:
    saveAmeliore1(std::ostream& ost,const terrain& t);
    void saveTerrain() override;
private:
    caractereLabyrintheAmeliore1 d_labyr;

    std::string traiterCasesVecteur2D(int ligne, int colonne) const override;
    void enregistreLigne(int ligne) override;
};



class saveAmeliore2 : public save
{
public:
    saveAmeliore2(std::ostream& ost,const terrain& t);
    void saveTerrain() override;
private:
    caractereLabyrintheAmeliore2 d_labyr;

    std::string traiterCasesVecteur2D(int ligne, int colonne) const override;
    void enregistreLigne(int ligne) override;
    std::string renvoieBonCararactereInterieur(int i, int j) const;
    std::string renvoieBonCararactereExterieur(int ligne, int colonne) const;

};

}

#endif // SAVE_H
