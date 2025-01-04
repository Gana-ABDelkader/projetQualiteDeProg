#include "read.h"
#include "terrain.h"
#include "position.h"
#include <memory>
#include "readVector.h"
#include <vector>
#include "robot.h"
#include "direction.h"

namespace fichiers
{

read::read(std::istream& ist):
    d_ist{ist}, d_entree{-1,-1}, d_sortie{-1,-1}, d_posRobot{-1,-1}, d_labyrinthe{}
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
        if(ligne->posRobot().positionLigne()>=0 && ligne->posRobot().positionColonne()>=0)
        {
            d_posRobot=ligne->posRobot();
        }
        i++;
    }
}

bool read::estPasALaFinDuFichier() const
{
    return !d_ist.eof();
}

bool read::robotALEntree() const
{
    return d_posRobot.positionLigne()==-1 && d_posRobot.positionColonne()==-1;
}

robot read::robotARenvoyer()
{
    if(robotALEntree())
    {
        d_posRobot.setLigne(d_entree.positionLigne());
        d_posRobot.setColonne(d_entree.positionColonne());
    }
    direction dir{};
    terrain t{d_labyrinthe,d_entree,d_sortie};
    return robot{d_posRobot,dir,t};
}

readSimpleAmeliore::readSimpleAmeliore(std::istream& ist):
    read{ist}
{}

robot readSimpleAmeliore::readTerrain()
{
    int i=0;
    while(estPasALaFinDuFichier())
    {
        readVectorSimpleAmeliore ligne{d_ist};
        traiterLigne(std::make_unique<readVectorSimpleAmeliore>(ligne),i);
    }
    return robotARenvoyer();
}

readAmeliore2::readAmeliore2(std::istream& ist):
    read{ist}
{}

robot readAmeliore2::readTerrain()
{
    int i=0;

    while(estPasALaFinDuFichier())
    {
        readVectorAmeliore2 ligne{d_ist};
        traiterLigne(std::make_unique<readVectorAmeliore2>(ligne),i);
    }
    return robotARenvoyer();
}
}
