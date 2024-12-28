#include "operateursGlobaux.h"
#include "caractereLabyrinthe.h"

namespace fichiers
{

std::ostream& operator<<(std::ostream& ost, const caractereLabyrintheAmeliore1& labyr)
{
    for(int i=0; i<labyr.nbLigne()-1;i++)
    {
        for(int j=0;j<labyr.nbColonne();j++)
        {
            if(labyr(i,j)=="entree")
            {
                ost<<"⎆";
            }
            else if(labyr(i,j)=="sortie")
            {
                ost<<"🔙";
            }
            else
                ost<<labyr(i,j);
        }
        ost<<'\n';
    }
    int i=labyr.nbLigne()-1;
    for(int j=0;j<labyr.nbColonne();j++)
        {
            if(labyr(i,j)=="e")
            {
                ost<<"⎆";
            }
            else if(labyr(i,j)=="s")
            {
                ost<<"🔙";
            }
            else
                ost<<labyr(i,j);
        }
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const caractereLabyrintheAmeliore2& labyr)
{
    for(int i=0; i<labyr.nbLigne()-1;i++)
    {
        for(int j=0;j<labyr.nbColonne();j++)
        {
            if(labyr(i,j)=="entree")
            {
                ost<<"⎆";
            }
            else if(labyr(i,j)=="sortie")
            {
                ost<<"🔙";
            }
            else
                ost<<labyr(i,j);
        }
        ost<<'\n';
    }
    int i=labyr.nbLigne()-1;
    for(int j=0;j<labyr.nbColonne();j++)
        {
            if(labyr(i,j)=="e")
            {
                ost<<"⎆";
            }
            else if(labyr(i,j)=="s")
            {
                ost<<"🔙";
            }
            else
                ost<<labyr(i,j);
        }
    return ost;
}

}
