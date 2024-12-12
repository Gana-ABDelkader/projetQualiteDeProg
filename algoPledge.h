#ifndef ALGOPLEDGE_H
#define ALGOPLEDGE_H

#include "algorithmeSortie.h"
class terrain;
class robot;

class pledge : public exitMaze{
public:
    void exit(robot& r, terrain& t) const override;
};


#endif //ALGOPLEDGE_H