#include "readVector.h"
#include <vector>
#include <string>
#include "position.h"

namespace fichiers
{
    
std::vector<bool> readVector::readLigne(std::istream& ist,position& entree, position& sortie, int i) const
{
    char caractere;
    std::vector<bool> ligne;
    std::string ISTligne;
    std::getline(ist,ISTligne);
    for(int j=0; j<ISTligne.size();j++)
    {
       if(ISTligne[j]=='.')
       {
        ligne.push_back(false);
       }
       else if(ISTligne[j]=='⎆')
       {
        entree.setColonne(j);
        entree.setLigne(i);
        ligne.push_back(false);
       }
       else if(ISTligne[j]=='🔙')
       {
        sortie.setColonne(j);
        entree.setLigne(i);
        ligne.push_back(false);
       }
       else
       {
        ligne.push_back(true);
       }
    }
    return ligne;
}

}