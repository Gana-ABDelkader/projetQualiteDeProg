#ifndef TERRAIN_H
#define TERRAIN_H

#include "position.h"
#include <vector>
#include<iostream>

class terrain
{
    public :
        terrain(const std::vector<std::vector<bool>>& terr,const position& entree,const position& sortie); 
        terrain();
        //terrain(std::istream& ist);

        position caseEntree() const;
        position caseSortie() const;
        std::vector<std::vector<bool>> labyrinthe() const;

        bool estUnMur(const position& p) const;
        //void litUnTerrain(std::istream& ist);
        //void ecritUnTerrain(std::ostream& ost) const;
        int tailleTableau() const;

        void changeenMur(const position& p);

    private :
        std::vector<std::vector<bool>> d_terrain; // les murs sont à true, les cases vides à false
        position d_entree;
        position d_sortie;
};

#endif // TERRAIN_H
