#ifndef READVECTOR_H
#define READVECTOR_H

#include <iostream>
#include <vector>

class terrain;
class position;

namespace fichiers {

class readVector
{
public:
    virtual ~readVector()=default;
    virtual std::vector<bool> readLigne(std::istream& ist,position& entree, position& sortie,int i) const=0;
};

class readVectorSimpleAmeliore : public readVector
{
public:
    std::vector<bool> readLigne(std::istream& ist,position& entree, position& sortie,int i) const override;
};

class readVectorAmeliore2 : public readVector
{
public:
    std::vector<bool> readLigne(std::istream& ist,position& entree, position& sortie,int i) const override;
};

}

#endif // READVECTOR_H
