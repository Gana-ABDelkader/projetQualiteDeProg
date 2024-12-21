#include "position.h"

position::position() :
    d_posLigne{1}, d_posColonne{1}
{}

position::position(int posLigne, int posColonne) :
    d_posLigne{posLigne}, d_posColonne{posColonne}
{}

int position::positionLigne() const
{
    return d_posLigne;
}

int position::positionColonne() const
{
    return d_posColonne;
}

void position::setLigne(int ligne)
{
    d_posLigne = ligne;
}

void position::setColonne(int colonne)
{
    d_posColonne = colonne;
}