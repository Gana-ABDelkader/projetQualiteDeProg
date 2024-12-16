#ifndef READVECTOR_H
#define READVECTOR_H

#include <iostream>

class terrain;
class position;

namespace fichiers {

class readVector
{
    constexpr char finDeLigne{'\n'};
public:
    std::vector<bool> readLigne(std::istream& ist/*,position& entree, position& sortie*/) const;
};

}

#endif // READVECTOR_H