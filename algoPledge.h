#ifndef ALGOPLEDGE_H
#define ALGOPLEDGE_H

#include "algorithmeSortie.h"
class terrain;
class robot;

class pledge : public exitMaze{
public:
    void exit(std::unique_ptr<read> lire, std::unique_ptr<print> ecrire) const override;
    void instruction1(std::unique_ptr<read> lire) const;
    void instruction2(std::unique_ptr<read> lire) const;
};


#endif //ALGOPLEDGE_H
