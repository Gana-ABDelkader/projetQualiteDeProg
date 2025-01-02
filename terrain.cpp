#include "terrain.h"
#include"read.h"

terrain::terrain(const std::vector<std::vector<bool>>& terr,const position& entree,const position& sortie)
 : d_labyrinthe{terr} , d_entree{entree}, d_sortie{sortie}
{}

terrain::terrain()
 : d_labyrinthe{} , d_entree{-1,-1}, d_sortie{-1,-1}
{
    std::vector<bool> bord{true,true,true,true,true};
    std::vector<bool> milieu{true,false,false,false,true};
    d_labyrinthe = {bord,milieu,milieu,milieu,bord};
}

position terrain::caseEntree() const{
    return d_entree;
}

position terrain::caseSortie() const{
    return d_sortie;
}

std::vector<std::vector<bool>> terrain::labyrinthe() const{
    return d_labyrinthe;
}

bool terrain::estUnMur(const position& p) const{
    return d_labyrinthe[p.positionLigne()][p.positionColonne()];
}

void terrain::changeenMur(const position& p){
    d_labyrinthe[p.positionLigne()][p.positionColonne()] = true ;
}

int terrain::tailleTableau() const
{
    return d_labyrinthe.size();
}

bool terrain::sortDuTableau(const position& p) const
{
    int i = p.positionLigne();
    int j = p.positionColonne();
    return i<0 || i>d_labyrinthe.size()-1 || j<0 || j>d_labyrinthe[0].size()-1;
}

terrain terrain::litUnTerrain(fichiers::read& r)
{
    return r.readTerrain();
}

