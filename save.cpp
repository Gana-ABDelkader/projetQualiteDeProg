#include "save.h"

#include "terrain.h"
#include <iostream>
#include "position.h"
#include <windows.h>
#include "operateursGlobaux.h"

namespace fichiers{

save::save(std::ostream& ost, const terrain& t):
    d_labyrinthe{t.labyrinthe()},
    d_entree{t.caseEntree()},
    d_sortie{t.caseSortie()},
    d_ost{ost}
{}

saveSimple::saveSimple(std::ostream& ost, const terrain& t):
    save{ost,t}
{}

std::string saveSimple::traiterCasesVecteur2D(int ligne, int colonne) const
{
    std::string resultat="";
    if (d_labyrinthe.estMur(ligne,colonne))
    {
        resultat = "X";
    }
    else
    {
        if (ligne == d_entree.positionLigne() && colonne == d_entree.positionColonne())
        {
            resultat = "⎆";
        }
        else if (ligne == d_sortie.positionLigne() && colonne == d_sortie.positionColonne())
        {
            resultat = "🔙";
        }
        else
        {
            resultat = ".";
        }
    }
    return resultat;
}

void saveSimple::enregistreLigne(int ligne)
{
    for (size_t j = 0; j < d_labyrinthe.nbColonne(); j++)
    {
        d_ost << traiterCasesVecteur2D(ligne,j);
    }
}

void saveSimple::saveTerrain()
{
    for (size_t i = 0; i < d_labyrinthe.nbLigne()-1; ++i)
    {
        enregistreLigne(i);
        d_ost << std::endl;
    }
    enregistreLigne(d_labyrinthe.nbLigne()-1);
}


/**-----------------------------------------------------------------------------------**/

saveAmeliore1::saveAmeliore1(std::ostream& ost, const terrain& t):
    save{ost,t}, d_labyr{d_labyrinthe.nbLigne(),d_labyrinthe.nbColonne()}
{}



std::string saveAmeliore1::traiterCasesVecteur2D(int ligne, int colonne) const
{
    std::string resultat;

    size_t hauteur = d_labyrinthe.nbLigne();
    size_t largeur = d_labyrinthe.nbColonne();

    if (d_labyrinthe.estMur(ligne,colonne))
            {
                if (ligne == 0 || ligne == hauteur - 1)
                {
                    if (colonne == 0 || colonne == largeur - 1)
                    {
                        resultat="+";
                    }
                    else
                    {
                        if(d_labyrinthe.estPlusAuBord(ligne,colonne))
                        {
                            resultat="+";
                        }
                        else
                            resultat="-";
                    }
                }
                else if (colonne == 0 || colonne == largeur - 1)
                {
                    resultat="|";
                }
                else
                {
                    if (d_labyrinthe.estPlusALInterieur(ligne,colonne))
                    {
                        resultat="+";
                    }
                    else if (d_labyrinthe.estMur(ligne,colonne - 1) || d_labyrinthe.estMur(ligne,colonne + 1))
                    {
                        resultat="-";
                    }
                    else
                    {
                        resultat="|";
                    }
                }
            }
            else
            {
                if (ligne == d_entree.positionLigne() && colonne == d_entree.positionColonne())
                {
                    resultat="entree";
                }
                else if (ligne == d_sortie.positionLigne() && colonne == d_sortie.positionColonne())
                {
                    resultat="sortie";
                }
                else
                {
                    resultat=".";
                }
            }
            return resultat;
}


void saveAmeliore1::enregistreLigne(int ligne)
{
    for (size_t j = 0; j < d_labyrinthe.nbColonne(); j++)
    {
        d_labyr(ligne,j)=traiterCasesVecteur2D(ligne,j);
    }
}


void saveAmeliore1::saveTerrain()
{

    for (size_t i = 0; i < d_labyrinthe.nbLigne(); ++i)
    {
        enregistreLigne(i);
    }
    d_labyr.corrigerCaracteresDepandantDesAutres();
    d_ost<<d_labyr;

}

/**-------------------------------------------------------------------------------------------**/

saveAmeliore2::saveAmeliore2(std::ostream& ost, const terrain& t):
    save{ost,t}, d_labyr{d_labyrinthe.nbLigne(),d_labyrinthe.nbColonne()}
{}

std::string saveAmeliore2::renvoieBonCararactereExterieur(int ligne, int colonne) const
{
    if(ligne==0)
    {
        if(d_labyrinthe.estIntersectionBasse(ligne,colonne))
        {
            return "┳";
        }
        else
        {
            return "━";
        }
    }
    else if(colonne==0)
    {
        if(d_labyrinthe.estIntersectionDroite(ligne, colonne))
        {
            return "┣";
        }
        else
        {
            return "┃";
        }
    }
    else if(ligne==d_labyrinthe.nbLigne()-1)
    {
        if(d_labyrinthe.estIntersectionHaute(ligne, colonne))
        {
            return "┻";
        }
        else
        {
            return "━";
        }
    }
    else
    {
        if(d_labyrinthe.estIntersectionGauche(ligne, colonne))
        {
            return "┫";
        }
        else
        {
            return "┃";
        }
    }
}

std::string saveAmeliore2::renvoieBonCararactereInterieur(int ligne, int colonne) const
{
    if(d_labyrinthe.estIntersection4Mur(ligne, colonne))
    {
        return "╋";
    }
    else if(d_labyrinthe.estIntersectionDroite(ligne, colonne))
    {
        return "┣";
    }
    else if(d_labyrinthe.estIntersectionHaute(ligne,colonne))
    {
        return "┻";
    }
    else if(d_labyrinthe.estIntersectionGauche(ligne, colonne))
    {
        return "┫";
    }
    else if(d_labyrinthe.estIntersectionBasse(ligne, colonne))
    {
        return "┳";
    }
    else if(d_labyrinthe.estAngleHautDroit(ligne, colonne))
    {
        return "┓";
    }
    else if(d_labyrinthe.estAngleBasDroit(ligne,colonne))
    {
        return "┛";
    }
    else if(d_labyrinthe.estAngleBasGauche(ligne, colonne))
    {
        return "┗";
    }
    else if(d_labyrinthe.estAngleHautGauche(ligne, colonne))
    {
        return "┏";
    }
    else if(d_labyrinthe.estMurHorizontal(ligne, colonne))
    {
        return "━";
    }
    else
    {
        return "┃";
    }

}

std::string saveAmeliore2::traiterCasesVecteur2D(int ligne, int colonne) const
{
    size_t hauteur = d_labyrinthe.nbLigne();
    size_t largeur = d_labyrinthe.nbColonne();

    std::string resultat;

    if (d_labyrinthe.estMur(ligne,colonne))
            {
                if (ligne == 0 && colonne==0)
                {
                    resultat="┏";
                }
                else if(ligne==0 && colonne==largeur-1)
                {
                    resultat="┓";
                }
                else if(ligne==hauteur-1 && colonne==0)
                {
                    resultat="┗";
                }
                else if(ligne==hauteur-1 && colonne==largeur-1)
                {
                    resultat="┛";
                }
                else
                {
                    if(ligne==0 || ligne== hauteur-1 || colonne==0 | colonne==largeur-1)
                    {
                        resultat=renvoieBonCararactereExterieur(ligne,colonne);
                    }
                    else
                    {
                        resultat=renvoieBonCararactereInterieur(ligne,colonne);
                    }
                }
            }
            else
            {
                if (ligne == d_entree.positionLigne() && colonne == d_entree.positionColonne())
                {
                    resultat="entree";
                }
                else if (ligne == d_sortie.positionLigne() && colonne == d_sortie.positionColonne())
                {
                    resultat="sortie";
                }
                else
                {
                    resultat=".";
            }
    }
    return resultat;
}

void saveAmeliore2::enregistreLigne(int ligne)
{
    for (size_t j = 0; j < d_labyrinthe.nbColonne(); j++)
    {
        d_labyr(ligne,j)=traiterCasesVecteur2D(ligne,j);
    }
}

void saveAmeliore2::saveTerrain()
{
    for (size_t i = 0; i < d_labyrinthe.nbLigne(); ++i)
    {
        enregistreLigne(i);
    }
    d_labyr.corrigerCaracteresDepandantDesAutres();
    d_ost<<d_labyr;
}



}





