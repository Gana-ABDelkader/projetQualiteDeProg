#ifndef READ_H
#define READ_H

#include <iostream>
#include <memory>
#include "position.h"
#include <vector>
#include "readVector.h"

class terrain;


namespace fichiers {

class read
{
public:
    read(std::istream& ist);
    virtual ~read() =default;
    virtual terrain readTerrain() =0;

protected:
    void traiterLigne(std::unique_ptr<readVector> ligne, int& i);
    bool estPasALaFinDuFichier() const;

    std::istream& d_ist;
    position d_entree;
    position d_sortie;
    std::vector<std::vector<bool>> d_labyrinthe;
};


class readSimpleAmeliore : public read
{
public:
    readSimpleAmeliore(std::istream& ist);
    terrain readTerrain() override;
};

class readAmeliore2 : public read
{
public:
    readAmeliore2(std::istream& ist);
    terrain readTerrain() override;
};



}

#endif // READ_H
