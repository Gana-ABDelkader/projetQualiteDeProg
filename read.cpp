#include "read.h"

#include "terrain.h"

#include "position.h"

#include "readVector.h"
#include <vector>

terrain readSimple::readTerrain(std::istream& ist) const
{
    std::vector<vector<bool>> labyrinthe;
    readVectorSimple ligneSimple{};
    while(!ist.eof()) //tant que ist n'est pas a la fin du fichier
    {
        labyrinthe.push_back(ligneSimple.readLigne(ist));
    }
    return terrain{labyrinthe,position{0,0}, position{0,0}};    //il faut trouver comment on defini l'entree et la sortie
}

terrain readAmeliore::readTerrain(std::istream& ist) const
{
    std::vector<vector<bool>> labyrinthe;
    readVectorAmeliore ligneSimple{};
    while(!ist.eof()) //tant que on est pas a la fin du fichier
    {
        labyrinthe.push_back(ligneSimple.readLigne(ist));
    }
    return terrain{labyrinthe,position{0,0}, position{0,0}};    //il faut trouver comment on defini l'entree et la sortie
}