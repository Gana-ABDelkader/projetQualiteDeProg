#include "save.h"

#include "terrain.h"
#include <iostream>
#include "position.h"
#include <windows.h>
#include "operateursGlobaux.h"
#include "robot.h"

namespace fichiers{

print::print(std::ostream& ost, const robot& r):
    d_labyrinthe{r.terrainDeLabyrinthe().labyrinthe()},
    d_entree{r.terrainDeLabyrinthe().caseEntree()},
    d_sortie{r.terrainDeLabyrinthe().caseSortie()},
    d_posRobot{r.positionSurTerrain()},
    d_ost{ost}
{}

printSimple::printSimple(std::ostream& ost, const robot& r):
    print{ost,r}
{}

std::string printSimple::traiterCasesVecteur2D(int ligne, int colonne) const
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
        else if(ligne==d_posRobot.positionLigne() && colonne==d_posRobot.positionColonne())
        {
            resultat = ">";
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

void printSimple::enregistreLigne(int ligne)
{
    for (int j = 0; j < d_labyrinthe.nbColonne(); j++)
    {
        d_ost << traiterCasesVecteur2D(ligne,j);
    }
}

void printSimple::printTerrain()
{
    for (int i = 0; i < d_labyrinthe.nbLigne()-1; ++i)
    {
        enregistreLigne(i);
        d_ost << std::endl;
    }
    enregistreLigne(d_labyrinthe.nbLigne()-1);
}


/**-----------------------------------------------------------------------------------**/

printAmeliore1::printAmeliore1(std::ostream& ost, const robot& r):
    print{ost,r}, d_labyr{d_labyrinthe.nbLigne(),d_labyrinthe.nbColonne()}
{}



std::string printAmeliore1::traiterCasesVecteur2D(int ligne, int colonne) const
{
    std::string resultat;

    int hauteur = d_labyrinthe.nbLigne();
    int largeur = d_labyrinthe.nbColonne();

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
                else if(ligne==d_posRobot.positionLigne() && colonne==d_posRobot.positionColonne())
                {
                    resultat = ">";
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


void printAmeliore1::enregistreLigne(int ligne)
{
    for (int j = 0; j < d_labyrinthe.nbColonne(); j++)
    {
        d_labyr(ligne,j)=traiterCasesVecteur2D(ligne,j);
    }
}


void printAmeliore1::printTerrain()
{

    for (int i = 0; i < d_labyrinthe.nbLigne(); ++i)
    {
        enregistreLigne(i);
    }
    d_labyr.corrigerCaracteresDepandantDesAutres();
    d_ost<<d_labyr;

}

/**-------------------------------------------------------------------------------------------**/

printAmeliore2::printAmeliore2(std::ostream& ost, const robot& r):
    print{ost,r}, d_labyr{d_labyrinthe.nbLigne(),d_labyrinthe.nbColonne()}
{}

std::string printAmeliore2::renvoieBonCararactereExterieur(int ligne, int colonne) const
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

std::string printAmeliore2::renvoieBonCararactereInterieur(int ligne, int colonne) const
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

std::string printAmeliore2::traiterCasesVecteur2D(int ligne, int colonne) const
{
    int hauteur = d_labyrinthe.nbLigne();
    int largeur = d_labyrinthe.nbColonne();

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
                    if(ligne==0 || ligne== hauteur-1 || colonne==0 || colonne==largeur-1)
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
                else if(ligne==d_posRobot.positionLigne() && colonne==d_posRobot.positionColonne())
                {
                    resultat = ">";
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

void printAmeliore2::enregistreLigne(int ligne)
{
    for (int j = 0; j < d_labyrinthe.nbColonne(); j++)
    {
        d_labyr(ligne,j)=traiterCasesVecteur2D(ligne,j);
    }
}

void printAmeliore2::printTerrain()
{
    for (int i = 0; i < d_labyrinthe.nbLigne(); ++i)
    {
        enregistreLigne(i);
    }
    d_labyr.corrigerCaracteresDepandantDesAutres();
    d_ost<<d_labyr;
}



}





