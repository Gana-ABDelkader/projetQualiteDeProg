#ifndef ALGORITHMESORTIE_H
#define ALGORITHMESORTIE_H

class robot;
class terrain;

class exitMaze{
public:
    virtual ~exitMaze() = default;
    virtual void exit(robot& r, terrain& t) const = 0;
};






#endif //ALGORITHMESORTIE_H

