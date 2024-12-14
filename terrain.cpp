#include "terrain.h"
#include"read.h"
#include"save.h"

terrain::terrain(const std::vector<std::vector<bool>>& terrain,const position& entree,const position& sortie)
 : d_terrain{terrain}, d_entree{entree}, d_sortie{sortie}
{}

terrain::terrain()
 : d_terrain{}, d_entree{-1,-1}, d_sortie{-1,-1}
 {}

position terrain::caseEntree() const{
    return d_entree;
}

position terrain::caseSortie() const{
    return d_sortie;
}

bool terrain::estUnMur(const position& p) const{
    return d_terrain[p.positionLigne()][p.positionColonne()];
}

/*
void terrain::litUnTerrain(std::istream& ist){
    fichiers::read d{};
    d_terrain = d.readTerrain(ist);
}

void terrain::ecritUnTerrain(std::ostream& ost) const{
    fichiers::save s{};
    s.saveTerrain(ost);
}
*/