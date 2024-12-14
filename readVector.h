#ifndef READVECTOR_H
#define READVECTOR_H

#include <iostream>

class terrain;
class position;

namespace fichiers {

class readVector
{
public:
    virtual ~read() =default;
    virtual std::vector<bool> readLigne(std::istream& ist/*,position& entree, position& sortie*/) const =0;
    constexpr char finDeLigne{'\n'};
};



class readVectorSimple : public readVector
{
public:
    std::vector<bool> readLigne(std::istream& ist/*,position& entree, position& sortie*/) const override;
};



class readVectorAmeliore : public readVector
{
public:
    std::vector<bool> readLigne(std::istream& ist/*,position& entree, position& sortie*/
    ) const override;
};


}

#endif // READVECTOR_H