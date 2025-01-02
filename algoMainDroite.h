#ifndef ALGOMAINDROITE_H
#define ALGOMAINDROITE_H

#include "algorithmeSortie.h"
class robot;
class terrain;

class mainDroite : public exitMaze{
public:
    void exit(robot& r, terrain& t) const override;
    void reDirectionRobot(robot& r, terrain& t) const;
    void algoSortie(robot& r, terrain& t) const;
};


#endif //ALGOMAINDROITE_H
