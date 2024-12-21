#include "read.h"
#include "terrain.h"
#include "position.h"
#include <memory>
#include "readVector.h"
#include <vector>

namespace fichiers
{

read::read(std::istream& ist):
    d_ist{ist}, d_entree{-1,-1}, d_sortie{-1,-1}, d_labyrinthe{}
{}

void read::traiterLigne(std::unique_ptr<readVector> ligne, int& i)
{
    std::vector<bool> vecteurLigne{ligne->readLigne(i)};
    if(vecteurLigne.size()>0)
    {
        d_labyrinthe.push_back(vecteurLigne);
        if(ligne->entree().positionLigne()>=0 && ligne->entree().positionColonne()>=0)
        {
            d_entree=ligne->entree();
        }
        if(ligne->sortie().positionLigne()>=0 && ligne->sortie().positionColonne()>=0)
        {
            d_sortie=ligne->sortie();
        }
        i++;
    }
}

bool read::estPasALaFinDuFichier() const
{
    return !d_ist.eof();
}

readSimpleAmeliore::readSimpleAmeliore(std::istream& ist):
    read{ist}
{}

terrain readSimpleAmeliore::readTerrain()
{
    int i=0;
    while(estPasALaFinDuFichier())
    {
        readVectorSimpleAmeliore ligne{d_ist};
        traiterLigne(std::make_unique<readVectorSimpleAmeliore>(ligne),i);
    }
    return terrain{d_labyrinthe,d_entree, d_sortie};
}

readAmeliore2::readAmeliore2(std::istream& ist):
    read{ist}
{}

terrain readAmeliore2::readTerrain()
{
    int i=0;

    while(estPasALaFinDuFichier())
    {
        readVectorAmeliore2 ligne{d_ist};
        traiterLigne(std::make_unique<readVectorAmeliore2>(ligne),i);
    }
    return terrain{d_labyrinthe,d_entree, d_sortie};
}
}
