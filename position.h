#ifndef POSITION_H
#define POSITION_H


class position
{public:
    position(int posLigne, int posColonne) ;
    int positionLigne() const;
    int positionColonne() const;
    void setLigne(int ligne) ;
    void setColonne(int colonne) ;
    
private:
    int d_posLigne, d_posColonne;
};

#endif