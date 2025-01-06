#ifndef MANIPULATE_H
#define MANIPULATE_H

#include"robot.h"

class manipulate
{
    public :

    virtual ~manipulate()=default;

    virtual void move(robot& r) const =0 ;
};

class robotForward : public manipulate{
    public :
    void move(robot& r) const override;
};

class robotLeft : public manipulate{
    public :
    void move(robot& r) const override;
};

class robotRight : public manipulate{
    public :
    void move(robot& r) const override;
};

#endif //MANIPULATE_H
