#ifndef DIRECTION_H
#define DIRCTION_H

class direction
{public:
    enum class valeur {
    HAUT = 0,
    DROITE = 1,
    BAS = 2,
    GAUCHE = 3
    };
    direction();
    direction(valeur v);

    valeur valeurDirection() const;
    int valeurDirectionInt() const;

    direction& setDirection(valeur v);
    direction& RotateLeft();
    direction& RotateRight();

    bool operator==(const direction& d) const;
    bool operator!=(const direction& d) const;
    
private:
    valeur d_valeur;
};


#endif