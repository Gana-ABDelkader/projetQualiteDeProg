#ifndef DIRECTION_H
#define DIRECTION_H

class direction
{public:
    static const int HAUT = 0;
    static const int DROITE = 1;
    static const int BAS = 2;
    static const int GAUCHE = 3;

    direction();
    direction(int valeur);

    int valeurDirection() const;

    direction& setDirection(int valeur);
    direction& RotateLeft();
    direction& RotateRight();

private:
    int d_valeur;
};


#endif