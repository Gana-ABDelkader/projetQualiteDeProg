#include "direction.h"

direction::direction() :
    d_valeur{BAS}
{}

direction::direction(int valeur) :
    d_valeur{valeur}
{}

int direction::valeurDirection() const
{
    return d_valeur;
}

direction& direction::setDirection(int valeur)
{
    d_valeur = valeur;
    return *this;
}

direction& direction::RotateLeft()
{
    d_valeur = (valeurDirection()+3)%4;
    return *this;
}

direction& direction::RotateRight()
{
    d_valeur = (valeurDirection()+1)%4;
    return *this;
}

bool direction::operator==(const direction& d) const
{
    return d_valeur == d.valeurDirection();
}

bool direction::operator!=(const direction& d) const
{
    return d_valeur != d.valeurDirection();
}