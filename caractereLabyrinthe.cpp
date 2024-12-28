#include "caractereLabyrinthe.h"
#include <vector>
#include <string>

namespace fichiers
{

caractereLabyrinthe::caractereLabyrinthe(int nbLigne, int nbColonne):
    d_labyr(nbLigne,std::vector<std::string>(nbColonne))
{}

void caractereLabyrinthe::corrigerCaracteresDepandantDesAutres()
{
    placerLesMursPleinsDansLeBordDuTableau();
    placerCorrigerLesCaractereQuiDependaientDesAutresDansToutLeTableau();
}

int caractereLabyrinthe::nbLigne() const
{
    return d_labyr.size();
}

int caractereLabyrinthe::nbColonne() const
{
    return d_labyr[0].size();
}


std::string& caractereLabyrinthe::operator()(int ligne, int colonne)
{
    return d_labyr[ligne][colonne];
}

const std::string& caractereLabyrinthe::operator()(int ligne, int colonne) const
{
    return d_labyr[ligne][colonne];
}

caractereLabyrintheAmeliore1::caractereLabyrintheAmeliore1(int nbLigne, int nbColonne):
    caractereLabyrinthe{nbLigne,nbColonne}
{}

bool caractereLabyrintheAmeliore1::estUnHashtagHautOuBasDuTableau(int ligne, int colonne) const
{
    bool resultat=false;

    if(d_labyr[ligne][colonne-1]=="+" && d_labyr[ligne][colonne+1]=="+")
    {
        resultat=true;
    }
    else if(d_labyr[ligne][colonne-1]=="#" && d_labyr[ligne][colonne+1]=="+")
    {
        resultat=true;
    }
    else if(d_labyr[ligne][colonne-1]=="+" && d_labyr[ligne][colonne+1]=="+")
    {
        resultat=true;
    }
    else if(d_labyr[ligne][colonne-1]=="#" && d_labyr[ligne][colonne+1]=="+")
    {
        resultat=true;
    }
    return resultat;
}

bool caractereLabyrintheAmeliore1::estUnHashtagDroiteOuGaucheDuTableau(int ligne, int colonne) const
{
    bool resultat=false;

    if(d_labyr[ligne-1][colonne]=="+" && d_labyr[ligne+1][colonne]=="+")
    {
        resultat=true;
    }
    else if(d_labyr[ligne-1][colonne]=="#" && d_labyr[ligne+1][colonne]=="+")
    {
        resultat=true;
    }
    else if(d_labyr[ligne-1][colonne]=="+" && d_labyr[ligne+1][colonne]=="+")
    {
        resultat=true;
    }
    else if(d_labyr[ligne-1][colonne]=="#" && d_labyr[ligne+1][colonne]=="+" )
    {
        resultat=true;
    }
    return resultat;
}

void caractereLabyrintheAmeliore1::placerMurPleinExterieurs(int ligne, int colonne)
{
    if(ligne!=0 && colonne!=0 && ligne!=nbLigne()-1 && colonne!=nbColonne()-1)
    {
        if(estUnHashtagHautOuBasDuTableau(ligne,colonne) || estUnHashtagDroiteOuGaucheDuTableau(ligne,colonne))
        {
            d_labyr[ligne][colonne]="#";
        }
    }
}

void caractereLabyrintheAmeliore1::placerMurPleinInterieur(int ligne, int colonne)
{
    if(colonne!=0)
    {
        if(estUnHashtagHautOuBasDuTableau(ligne,colonne))
        {
            d_labyr[ligne][colonne]="#";
        }
    }
    else if(ligne!=0)
    {
        if(estUnHashtagDroiteOuGaucheDuTableau(ligne,colonne))
        {
            d_labyr[ligne][colonne]="#";
        }
    }
}

void caractereLabyrintheAmeliore1::placerCorrigerLesCaractereQuiDependaientDesAutresDansToutLeTableau()
{
    for(int i=0; i<d_labyr.size()-1;++i)
    {
        for(int j=0;j<d_labyr[i].size();j++)
        {
            if(d_labyr[i][j]=="+")
            {
                placerMurPleinInterieur(i,j);
            }
        }
    }
}

void caractereLabyrintheAmeliore1::placerLesMursPleinsDansLeBordDuTableau()
{
    for(int i=0; i<d_labyr.size()-1;++i)
    {
        for(int j=0;j<d_labyr[i].size();j++)
        {
            if(d_labyr[i][j]=="+")
            {
                placerMurPleinExterieurs(i,j);
            }
        }
    }
}

/**------------------------------------------------------------------------------------**/
caractereLabyrintheAmeliore2::caractereLabyrintheAmeliore2(int nbLigne, int nbColonne):
    caractereLabyrinthe{nbLigne,nbColonne}
{}

bool caractereLabyrintheAmeliore2::estMurPleinHautEtBas(int ligne, int colonne) const
{
    std::string caseDroite = d_labyr[ligne][colonne+1];
    std::string caseGauche = d_labyr[ligne][colonne-1];
    bool reponse=false;

    if(static_cast<unsigned char>(caseGauche[2])==troisiemeOctetCaractereCroisementMurBas &&
       static_cast<unsigned char>(caseDroite[2])==troisiemeOctetCaractereCroisementMurBas)
    {
        reponse=true;
    }
    else if(static_cast<unsigned char>(caseGauche[1])==deuxiemeeOctetCaractereMurPlein &&
            static_cast<unsigned char>(caseDroite[2])==troisiemeOctetCaractereCroisementMurBas)
    {
        reponse=true;
    }
    else if(static_cast<unsigned char>(caseGauche[2])==troisiemeOctetCaractereCroisementMurHaut &&
            static_cast<unsigned char>(caseDroite[2])==troisiemeOctetCaractereCroisementMurHaut)
    {
        reponse=true;
    }
    else if(static_cast<unsigned char>(caseGauche[1])==deuxiemeeOctetCaractereMurPlein &&
            static_cast<unsigned char>(caseDroite[2])==troisiemeOctetCaractereCroisementMurHaut)
    {
        reponse=true;
    }
    return reponse;
}

bool caractereLabyrintheAmeliore2::estMurPleinDroiteEtGauche(int ligne, int colonne) const
{
    std::string caseHaut = d_labyr[ligne-1][colonne];
    std::string caseBas = d_labyr[ligne+1][colonne];
    bool reponse=false;

    if(static_cast<unsigned char>(caseHaut[2])==troisiemeOctetCaractereCroisementMurDroite &&
       static_cast<unsigned char>(caseBas[2])==troisiemeOctetCaractereCroisementMurDroite)
    {
        reponse=true;
    }
    else if(static_cast<unsigned char>(caseHaut[1])==deuxiemeeOctetCaractereMurPlein &&
            static_cast<unsigned char>(caseBas[2])==troisiemeOctetCaractereCroisementMurDroite)
    {
        reponse=true;
    }
    else if(static_cast<unsigned char>(caseHaut[2])==troisiemeOctetCaractereCroisementMurGauche &&
            static_cast<unsigned char>(caseBas[2])==troisiemeOctetCaractereCroisementMurGauche)
    {
        reponse=true;
    }
    else if(static_cast<unsigned char>(caseHaut[1])==deuxiemeeOctetCaractereMurPlein &&
            static_cast<unsigned char>(caseBas[2])==troisiemeOctetCaractereCroisementMurGauche)
    {
        reponse=true;
    }
    return reponse;
}

void caractereLabyrintheAmeliore2::placeEncadrementDesMursPleins(int ligne, int colonne)
{

    if(ligne==0 && colonne!=0 && colonne!=nbColonne()-1)
    {
        if(static_cast<unsigned char>(d_labyr[ligne][colonne+1][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┓";
        }
        else if(static_cast<unsigned char>(d_labyr[ligne][colonne-1][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┏";
        }
    }
    else if(colonne==0 && ligne!=0 && ligne!=nbLigne()-1)
    {
        if(static_cast<unsigned char>(d_labyr[ligne+1][colonne][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┗";
        }
        else if(static_cast<unsigned char>(d_labyr[ligne-1][colonne][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┏";
        }
    }
    else if(ligne==nbLigne()-1 && colonne!=0 && colonne!=nbColonne()-1)
    {
        if(static_cast<unsigned char>(d_labyr[ligne][colonne+1][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┛";
        }
        else if(static_cast<unsigned char>(d_labyr[ligne][colonne-1][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┗";
        }
    }
    else if(colonne==nbColonne()-1 && ligne!=0 && ligne!=nbLigne()-1)
    {
        if(static_cast<unsigned char>(d_labyr[ligne+1][colonne][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┛";
        }
        else if(static_cast<unsigned char>(d_labyr[ligne-1][colonne][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="┓";
        }
    }
}

void caractereLabyrintheAmeliore2::placerMurPleinEtMurDroitInterieur(int ligne, int colonne)
{
    if(ligne!=0 && colonne!=0 && ligne!=nbLigne()-1 && colonne!=nbColonne()-1)
    {
        if(static_cast<unsigned char>(d_labyr[ligne-1][colonne][1])==deuxiemeeOctetCaractereMurPlein ||
           static_cast<unsigned char>(d_labyr[ligne+1][colonne][1])==deuxiemeeOctetCaractereMurPlein)
        {
            d_labyr[ligne][colonne]="━";
        }
        else if(static_cast<unsigned char>(d_labyr[ligne][colonne-1][1])==deuxiemeeOctetCaractereMurPlein ||
                static_cast<unsigned char>(d_labyr[ligne][colonne+1][1])==deuxiemeeOctetCaractereMurPlein)
        {
           d_labyr[ligne][colonne]="┃";
        }
        else if(estMurPleinHautEtBas(ligne,colonne) || estMurPleinDroiteEtGauche(ligne,colonne))
        {
            d_labyr[ligne][colonne]="▄";
        }
    }
}

void caractereLabyrintheAmeliore2::placerMurPleinExterieurs(int ligne, int colonne)
{
    if(colonne!=0 && colonne!=nbColonne()-1)
    {
        if(estMurPleinHautEtBas(ligne,colonne))
        {
            d_labyr[ligne][colonne]="▄";
        }
    }
    else if(ligne!=0 && ligne!=nbLigne()-1)
    {
        if(estMurPleinDroiteEtGauche(ligne,colonne))
        {
            d_labyr[ligne][colonne]="▄";
        }
    }
}

void caractereLabyrintheAmeliore2::placerCorrigerLesCaractereQuiDependaientDesAutresDansToutLeTableau()
{
    for(int i=0; i<nbLigne()-1;++i)
    {
        for(int j=0;j<nbColonne();j++)
        {
            if(static_cast<unsigned char>(d_labyr[i][j][0])==premierOctetCaractereCroisementMur &&
               static_cast<unsigned char>(d_labyr[i][j][1])==deuxiemeOctetCaractereCroisementMur)
            {
                placerMurPleinEtMurDroitInterieur(i,j);
                placeEncadrementDesMursPleins(i,j);
            }
        }
    }
}

void caractereLabyrintheAmeliore2::placerLesMursPleinsDansLeBordDuTableau()
{
    for(int i=0; i<nbLigne()-1;i++)
    {
        for(int j=0;j<nbColonne();j++)
        {
            if(static_cast<unsigned char>(d_labyr[i][j][0])==premierOctetCaractereCroisementMur &&
               static_cast<unsigned char>(d_labyr[i][j][1])==deuxiemeOctetCaractereCroisementMur)
            {
                placerMurPleinExterieurs(i,j);
            }
        }
    }
}

}


