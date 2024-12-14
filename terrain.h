#ifndef TERRAIN_H
#define TERRAIN_H

#include "position.h"
#include <vector>
#include<iostream>

class terrain
{
    public :
        terrain(const std::vector<std::vector<bool>>& terrain,const position& entree,const position& sortie);
        terrain();

        position caseEntree() const;
        position caseSortie() const;
        bool estUnMur(const position& p) const;
        void litUnTerrain(std::istream& ist);
        void ecritUnTerrain(std::ostream& ost) const;


    private : 
        std::vector<std::vector<bool>> d_terrain; // les murs sont à true, les cases vides à false
        position d_entree;
        position d_sortie;
};

#endif // TERRAIN_H