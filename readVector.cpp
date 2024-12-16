#include "readVector.h"
#include <vector>

#include "position.h"

namespace fichier
{
    
std::vector<bool> readVector::readLigne(istream& ist/*,position& entree, position& sortie*/) const
{
    char caractere;
    std::vector<bool> ligne;
    do
    {
       ist>>caractere;
       if(caractere=='.')
       {
        ligne.push_back(false);
       }
       else
       {
        ligne.push_back(true);
       }
    } while (caractere != finDeLigne);
    return ligne;
}

}