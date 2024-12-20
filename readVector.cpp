#include "readVector.h"
#include <vector>
#include <string>
#include "position.h"
#include <windows.h>

namespace fichiers
{

std::vector<bool> readVectorSimpleAmeliore::readLigne(std::istream& ist,position& entree, position& sortie, int i) const
{
    char caractere;
    std::vector<bool> ligne;
    std::string ISTligne;
    std::getline(ist,ISTligne);
    int indiceColonne=0;
    for(int j=0; j<ISTligne.size();j++)
    {

        unsigned char c = ISTligne[j]; // Récupérer le caractère comme un unsigned char pour l'afficher en hexadécimal

       if(ISTligne[j]=='.')
       {
        ligne.push_back(false);
       }
       else if(c==0xE2)
       {
        entree.setColonne(indiceColonne);
        entree.setLigne(i);
        ligne.push_back(false);
        j+=2;
       }
       else if(c==0xF0)
       {
        sortie.setColonne(indiceColonne);
        sortie.setLigne(i);
        ligne.push_back(false);
        j+=3;
       }
       else
       {
        ligne.push_back(true);
       }
       indiceColonne++;

    }
    return ligne;
}

std::vector<bool> readVectorAmeliore2::readLigne(std::istream& ist,position& entree, position& sortie, int i) const
{
    char caractere;
    std::vector<bool> ligne;
    std::string ISTligne;
    std::getline(ist,ISTligne);
    int indiceColonne=0;
    for(int j=0; j<ISTligne.size();j++)
    {

        unsigned char c = ISTligne[j]; // Récupérer le caractère comme un unsigned char pour l'afficher en hexadécimal

       if(ISTligne[j]=='.')
       {
        ligne.push_back(false);
       }
       else if(c==0xE2)
       {
           j++;
           c=ISTligne[j];
           if(c==0x8E)
           {
                entree.setColonne(indiceColonne);
                entree.setLigne(i);
                ligne.push_back(false);
           }
           else
           {
               ligne.push_back(true);
           }
           j++;
       }
       else
       {
        sortie.setColonne(indiceColonne);
        sortie.setLigne(i);
        ligne.push_back(false);
        j+=3;
       }
       indiceColonne++;

    }
    return ligne;
}



}
