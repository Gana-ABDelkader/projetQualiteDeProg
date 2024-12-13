#ifndef MANIPULATE_H
#define MANIPULATE_H

class robot;

enum direction {droite,haut,gauche,bas};

class manipulate
{
    public :

    virtual ~manipulate()=default;

    virtual void move(robot& r)=0 ;
};

class robotForward : public manipulate{
    public : 
    void move(robot& r) override;
};

class robotLeft : public manipulate{
    public : 
    void move(robot& r) override;
};

class robotRight : public manipulate{
    public : 
    void move(robot& r) override;
};

#endif //MANIPULATE_H