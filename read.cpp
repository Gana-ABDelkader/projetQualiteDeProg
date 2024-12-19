#include "read.h"

#include "terrain.h"

#include "position.h"

#include "readVector.h"
#include <vector>

namespace fichier
{

terrain readSimple::readTerrain(std::istream& ist) const
{
    std::vector<vector<bool>> labyrinthe;
    readVector ligne{};
    position entree;
    position sortie;
    int i=0;
    while(!ist.eof()) //tant que ist n'est pas a la fin du fichier
    {
        labyrinthe.push_back(ligne.readLigne(ist),entree,sortie,i);
        i++;
    }
    return terrain{labyrinthe,entree, sortie};    //il faut trouver comment on defini l'entree et la sortie
}
}