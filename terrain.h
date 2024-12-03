#ifndef TERRAIN_H
#define TERRAIN_H

#include "position.h"
#include <vector>

class terrain
{
    public :
        terrain(const std::vector<bool>& terrain,const position& entree,const position& sortie);
        terrain();

        position caseEntree() const;
        position caseSortie() const;
        bool estUnMur(const position& p) const;
        void litUnTerrain();
        void ecritUnTerrain() const;


    private : 
        std::vector<bool> d_terrain;
        position d_entree;
        position d_sortie;
};

#endif // TERRAIN_H