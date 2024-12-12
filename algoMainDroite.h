#ifndef ALGOMAINDROITE_H
#define ALGOMAINDROITE_H

#include "algorithmeSortie.h"
class robot;
class terrain;

class mainDroite : public exitMaze{
public:
    void exit(robot& r, terrain& t) const override;
};


#endif //ALGOMAINDROITE_H