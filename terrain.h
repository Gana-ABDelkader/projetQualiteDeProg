#ifndef TERRAIN_H
#define TERRAIN_H

#include "position.h"
#include <vector>
#include<iostream>
#include"read.h"

class terrain
{
    public :
        terrain(const std::vector<std::vector<bool>>& terr,const position& entree,const position& sortie);
        terrain();

        position caseEntree() const;
        position caseSortie() const;
        std::vector<std::vector<bool>> labyrinthe() const;

        bool estUnMur(const position& p) const;
        int tailleTableau() const;
        void changeenMur(const position& p);

        terrain litUnTerrain(fichiers::read& r);

    private :
        std::vector<std::vector<bool>> d_labyrinthe; // les murs sont à true, les cases vides à false
        position d_entree;
        position d_sortie;
};

#endif // TERRAIN_H
