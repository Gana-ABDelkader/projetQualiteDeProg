#include "readVector.h"
#include <vector>
#include <string>
#include "position.h"
#include <windows.h>

namespace fichiers
{

readVector::readVector(std::istream& ist):
    d_ligne{}, d_entree{-1,-1} , d_sortie{-1,-1}
{
    std::getline(ist,d_ligne);
}

position readVector::entree() const
{
    return d_entree;
}

position readVector::sortie() const
{
    return d_sortie;
}

readVectorSimpleAmeliore::readVectorSimpleAmeliore(std::istream& ist):
    readVector{ist}
{}

bool readVectorSimpleAmeliore::traiteCaractere(char caractere, int& j, int indiceColonne)
{
    unsigned char caractereHexa = caractere; // Récupérer le caractère comme un unsigned char pour l'afficher en hexadécimal
    bool valeurCaractereBool;
       if(caractere=='.')
       {
            valeurCaractereBool = false;
       }
       else if(caractereHexa==premierOctetCaractereEntree)
       {
            d_entree.setColonne(indiceColonne);
            d_entree.setLigne(d_indiceLigne);
            valeurCaractereBool = false;
            j+=2;
       }
       else if(caractereHexa==premierOctetCaractereSortie)
       {
            d_sortie.setColonne(indiceColonne);
            d_sortie.setLigne(d_indiceLigne);
            valeurCaractereBool = false;
            j+=3;
       }
       else
       {
            valeurCaractereBool = true;
       }
       return valeurCaractereBool;
}

std::vector<bool> readVectorSimpleAmeliore::readLigne(int indiceLigne)
{
    std::vector<bool> tableauLigne;
    int indiceColonne=0;
    d_indiceLigne=indiceLigne;
    for(int j=0; j<d_ligne.size();j++)
    {
        tableauLigne.push_back(traiteCaractere(d_ligne[j],j, indiceColonne));
        indiceColonne++;
    }
    return tableauLigne;
}

readVectorAmeliore2::readVectorAmeliore2(std::istream& ist):
    readVector{ist}
{}

bool readVectorAmeliore2::traiteCaractere(char caractere, int& j, int indiceColonne)
{
    unsigned char caractereHexa = caractere; // Récupérer le caractère comme un unsigned char pour l'afficher en hexadécimal
    bool valeurCaractereBool;
       if(caractere=='.')
       {
        valeurCaractereBool = false;
       }
       else if(caractereHexa==premierOctetCaractereMurEtCaractereEntree)
       {
           j++;
           caractereHexa=d_ligne[j];
           if(caractereHexa==deuxiemeOctetCaractereEntree)
           {
                d_entree.setColonne(indiceColonne);
                d_entree.setLigne(d_indiceLigne);
                valeurCaractereBool = false;
           }
           else
           {
               valeurCaractereBool = true;
           }
           j++;
       }
       else
       {
        d_sortie.setColonne(indiceColonne);
        d_sortie.setLigne(d_indiceLigne);
        j+=3;
        valeurCaractereBool = false;
       }
       return valeurCaractereBool;
}

std::vector<bool> readVectorAmeliore2::readLigne(int indiceLigne)
{
    std::vector<bool> tableauLigne;
    int indiceColonne=0;
    d_indiceLigne=indiceLigne;
    for(int j=0; j<d_ligne.size();j++)
    {
        tableauLigne.push_back(traiteCaractere(d_ligne[j],j, indiceColonne));
        indiceColonne++;
    }
    return tableauLigne;
}



}
