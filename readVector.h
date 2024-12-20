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
    std::vector<bool> readLigne(std::istream& ist,position& entree, position& sortie,int i) const;
};

}

#endif // READVECTOR_H