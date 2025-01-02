#ifndef DIRECTION_H
#define DIRECTION_H

class direction
{public:
    static constexpr int HAUT = 0;
    static constexpr int DROITE = 1;
    static constexpr int BAS = 2 ;
    static constexpr int GAUCHE = 3;	

    direction();
    direction(int valeur);

    int valeurDirection() const;

    direction& setDirection(int valeur);
    direction& RotateLeft();
    direction& RotateRight();

    bool operator==(const direction& d) const;
    bool operator!=(const direction& d) const;

private:
    int d_valeur;
};


#endif