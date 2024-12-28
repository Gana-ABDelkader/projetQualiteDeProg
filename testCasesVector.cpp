#include "testCasesVector.h"


namespace fichiers
{

testCasesVector::testCasesVector(const std::vector<std::vector<bool>>& vecteur):
    d_vecteur{vecteur}
{}

bool testCasesVector::estMur(int ligne, int colonne) const
{
    return d_vecteur[ligne][colonne];
}

bool testCasesVector::estPlusDerniereLigne(int colonne) const
{
    int ligne=d_vecteur.size()-1;
    return (estMur(ligne,colonne+1) && estMur(ligne-1,colonne))
        || (estMur(ligne,colonne-1) && estMur(ligne-1,colonne));
}

bool testCasesVector::estPlusPremiereLigne(int colonne) const
{
    int ligne=0;
    return (estMur(ligne,colonne-1) && estMur(ligne+1,colonne))
        || (estMur(ligne,colonne+1) && estMur(ligne+1,colonne));
}

bool testCasesVector::estPlusBordDroiteEtGauche(int ligne, int colonne) const
{
    return (estMur(ligne,colonne-1) && estMur(ligne-1,colonne))
        || (estMur(ligne,colonne-1) && estMur(ligne+1,colonne))
        || (estMur(ligne,colonne+1) && estMur(ligne-1,colonne))
        || (estMur(ligne,colonne+1) && estMur(ligne+1,colonne));
}

bool testCasesVector::estPlusAuBord(int ligne, int colonne) const
{
    bool estPlus;
    if(ligne==0)
    {
        estPlus = estPlusPremiereLigne(colonne);
    }
    else if(ligne==d_vecteur.size()-1)
    {
        estPlus = estPlusDerniereLigne(colonne);
    }
    else
        estPlus = estPlusBordDroiteEtGauche(ligne,colonne);
    return estPlus;
}

int testCasesVector::nombreDeMurAutourDeCase(int ligne, int colonne) const
{
    int nbMur=0;
    if(estMur(ligne,colonne-1))
        nbMur++;

    if(estMur(ligne,colonne+1))
        nbMur++;

    if(estMur(ligne-1,colonne))
        nbMur++;

    if(estMur(ligne+1,colonne))
        nbMur++;

    return nbMur;
}

bool testCasesVector::aDeuxMurNonOppose(int ligne, int colonne) const
{
    return (estMur(ligne,colonne-1) && estMur(ligne-1,colonne))
                || (estMur(ligne,colonne-1) && estMur(ligne+1,colonne))
                || (estMur(ligne,colonne+1) && estMur(ligne-1,colonne))
                || (estMur(ligne,colonne+1) && estMur(ligne+1,colonne));
}

bool testCasesVector::estPlusALInterieur(int ligne, int colonne) const
{
    int nbMur = nombreDeMurAutourDeCase(ligne,colonne);
    return nbMur==4 || (nbMur==2 && aDeuxMurNonOppose(ligne,colonne));
}

int testCasesVector::nbLigne() const
{
    return d_vecteur.size();
}

int testCasesVector::nbColonne() const
{
    return d_vecteur[0].size();
}

bool testCasesVector::estIntersectionBasse(int ligne, int colonne) const
{
    return estMur(ligne,colonne-1) && estMur(ligne,colonne+1) && estMur(ligne+1,colonne);
}

bool testCasesVector::estIntersectionDroite(int ligne, int colonne) const
{
    return estMur(ligne-1,colonne) && estMur(ligne+1,colonne) && estMur(ligne,colonne+1);
}

bool testCasesVector::estIntersectionGauche(int ligne, int colonne) const
{
    return estMur(ligne-1,colonne) && estMur(ligne+1,colonne) && estMur(ligne,colonne-1);
}

bool testCasesVector::estIntersectionHaute(int ligne, int colonne) const
{
    return estMur(ligne,colonne-1) && estMur(ligne,colonne+1) && estMur(ligne-1,colonne);
}

bool testCasesVector::estIntersection4Mur(int ligne, int colonne) const
{
    return estMur(ligne+1,colonne) && estMur(ligne-1,colonne) && estMur(ligne,colonne+1) && estMur(ligne,colonne-1);
}

bool testCasesVector::estAngleHautDroit(int ligne, int colonne) const
{
    return estMur(ligne,colonne-1) && estMur(ligne+1,colonne);
}

bool testCasesVector::estAngleHautGauche(int ligne, int colonne) const
{
    return estMur(ligne,colonne+1) && estMur(ligne+1,colonne);
}

bool testCasesVector::estAngleBasDroit(int ligne, int colonne)const
{
    return estMur(ligne,colonne-1) && estMur(ligne-1,colonne);
}

bool testCasesVector::estAngleBasGauche(int ligne, int colonne) const
{
    return estMur(ligne,colonne+1) && estMur(ligne-1,colonne);
}

bool testCasesVector::estMurHorizontal(int ligne, int colonne) const
{
    return estMur(ligne,colonne+1) && estMur(ligne+1,colonne);
}


}
