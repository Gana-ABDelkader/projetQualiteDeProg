#ifndef ALGORITHMESORTIE_H
#define ALGORITHMESORTIE_H

#include <memory>
#include "read.h"
#include "save.h"

using fichiers::read;
using fichiers::print;

class robot;
class terrain;

class exitMaze{
public:
    virtual ~exitMaze() = default;
    virtual void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire) const = 0;
};






#endif //ALGORITHMESORTIE_H

