#ifndef ALGOMAINDROITE_H
#define ALGOMAINDROITE_H

#include "algorithmeSortie.h"
#include "robot.h"
class terrain;

class mainDroite : public exitMaze{
public:
    void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire) const override;
private:
    void reDirectionRobot(robot& r, const terrain& t) const;
    void algoSortie(std::unique_ptr<print> ecrire, robot& r, const terrain& t) const;
};


#endif //ALGOMAINDROITE_H
