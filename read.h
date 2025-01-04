#ifndef READ_H
#define READ_H

#include <iostream>
#include <memory>
#include "position.h"
#include <vector>
#include "readVector.h"

class robot;

namespace fichiers {

class read
{
public:
    read(std::istream& ist);
    virtual ~read() =default;
    virtual robot readTerrain() =0;

protected:
    void traiterLigne(std::unique_ptr<readVector> ligne, int& i);
    bool estPasALaFinDuFichier() const;
    bool robotALEntree() const;
    robot robotARenvoyer();

    std::istream& d_ist;
    position d_entree;
    position d_sortie;
    position d_posRobot;
    std::vector<std::vector<bool>> d_labyrinthe;
};


class readSimpleAmeliore : public read
{
public:
    readSimpleAmeliore(std::istream& ist);
    robot readTerrain() override;
};

class readAmeliore2 : public read
{
public:
    readAmeliore2(std::istream& ist);
    robot readTerrain() override;
};



}

#endif // READ_H
