#include "readVector.h"
#include <vector>

#include "position.h"

namespace fichiers
{
    
std::vector<bool> readVector::readLigne(std::istream& ist,position& entree, position& sortie, int i) const
{
    char caractere;
    std::vector<bool> ligne;
    int j=0;
    do
    {
       ist>>caractere;
       if(caractere=='.')
       {
        ligne.push_back(false);
       }
       else if(caractere=='⎆')
       {
        entree.setColonne(j);
        entree.setLigne(i);
        ligne.push_back(false);
       }
       else if(caractere=='🔙')
       {
        sortie.setColonne(j);
        entree.setLigne(i);
        ligne.push_back(false);
       }
       else
       {
        ligne.push_back(true);
       }
       j++;
    } while (caractere != finDeLigne);
    return ligne;
}

}