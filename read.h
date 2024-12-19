#ifndef READ_H
#define READ_H

#include <iostream>

class terrain;

namespace fichiers {

class read
{
public:
    terrain readTerrain(std::istream& ist) const ;
};


}

#endif // READ_H