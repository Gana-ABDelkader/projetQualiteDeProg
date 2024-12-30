#include "direction.h"

direction::direction() :
    d_valeur{valeur::BAS}
{}

direction::direction(valeur v) :
    d_valeur{v}
{}

direction::valeur direction::valeurDirection() const
{
    return d_valeur;
}

int direction::valeurDirectionInt() const
{
    return static_cast<int>(d_valeur);
}

direction& direction::setDirection(valeur v)
{
    d_valeur = v;
    return *this;
}

direction& direction::RotateLeft()
{
    d_valeur = static_cast<valeur>((valeurDirectionInt()+3)%4);
    return *this;
}

direction& direction::RotateRight()
{
    d_valeur = static_cast<valeur>((valeurDirectionInt()+1)%4);
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