#ifndef READVECTOR_H
#define READVECTOR_H

#include <iostream>
#include <vector>
#include "position.h"

class terrain;


namespace fichiers {

class readVector
{
public:
    readVector(std::istream& ist);
    virtual ~readVector()=default;
    virtual std::vector<bool> readLigne(int indiceLigne) =0;
    position entree() const;
    position sortie() const;

private:
    virtual bool traiteCaractere(char caractere, int& j, int indiceColonne) =0;

protected:
    position d_entree;
    position d_sortie;
    int d_indiceLigne;
    std::string d_ligne;
};

class readVectorSimpleAmeliore : public readVector
{
public:
    readVectorSimpleAmeliore(std::istream& ist);
    std::vector<bool> readLigne(int indiceLigne) override;

private:
    bool traiteCaractere(char caractere, int& j, int indiceColonne) override;
    static constexpr unsigned char premierOctetCaractereEntree{0xE2};
    static constexpr unsigned char premierOctetCaractereSortie{0xF0};
};

class readVectorAmeliore2 : public readVector
{
public:
    readVectorAmeliore2(std::istream& ist);
    std::vector<bool> readLigne(int indiceLigne) override;

private:
    bool traiteCaractere(char caractere, int& j, int indiceColonne) override;
    static constexpr unsigned char premierOctetCaractereMurEtCaractereEntree{0xE2};
    static constexpr unsigned char deuxiemeOctetCaractereEntree{0x8E};
};

}

#endif // READVECTOR_H
