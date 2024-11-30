#include "position.h"

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