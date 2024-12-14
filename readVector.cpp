#include "readVector.h"
#include <vector>

#include "position.h"

std::vector<bool> readVectorSimple::readLigne(istream& ist/*,position& entree, position& sortie*/) const
{
    char caractere;
    std::vector<bool> ligne;
    do
    {
       ist>>caractere;
       if(caractere=='X')
       {
        ligne.push_back(true);
       }
       else
       {
        ligne.push_back(false);
       }
    } while (caractere != finDeLigne);
    return ligne;
}

std::vector<bool> readVectorAmeliore::readLigne(istream& ist/*,position& entree, position& sortie*/) const
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
