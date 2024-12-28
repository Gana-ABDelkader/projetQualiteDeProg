#ifndef TESTCASESVECTOR_H
#define TESTCASESVECTOR_H

#include <vector>

namespace fichiers
{

class testCasesVector
{
    public:
        testCasesVector(const std::vector<std::vector<bool>>& vecteur);
        bool estMur(int ligne, int colonne) const;
        bool estPlusAuBord(int ligne, int colonne) const;
        bool estPlusALInterieur(int ligne, int colonne) const;
        int nbLigne() const;
        int nbColonne() const;
        bool estIntersectionBasse(int ligne, int colonne) const;
        bool estIntersectionDroite(int ligne, int colonne)const;
        bool estIntersectionGauche(int ligne, int colonne) const;
        bool estIntersectionHaute(int ligne, int colonne) const;
        bool estIntersection4Mur(int ligne, int colonne) const;

        bool estAngleHautDroit(int ligne, int colonne) const;
        bool estAngleHautGauche(int ligne, int colonne) const;
        bool estAngleBasDroit(int ligne, int colonne) const;
        bool estAngleBasGauche(int ligne, int colonne) const;
        bool estMurHorizontal(int ligne, int colonne) const;

    private:
        std::vector<std::vector<bool>> d_vecteur;

        bool estPlusDerniereLigne(int colonne) const;
        bool estPlusPremiereLigne(int colonne) const;
        bool estPlusBordDroiteEtGauche(int ligne, int colonne) const;
        int nombreDeMurAutourDeCase(int ligne, int colonne) const;
        bool aDeuxMurNonOppose(int ligne, int colonne) const;
};

}

#endif // TESTCASESVECTOR_H
