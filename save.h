#ifndef SAVE_H
#define SAVE_H

#include <iostream>

class terrain;

namespace fichiers{

class save
{   
public:
    virtual ~save() =default;
    virtual void saveTerrain(std::ostream& ost) const =0;
};



class saveSimple : public save
{
public:
    void saveTerrain(std::ostream& ost) const override;
};



class saveAmeliore1 : public save
{
public:
    void saveTerrain(std::ostream& ost) const override;
};



class saveAmeliore2 : public save
{
public:
    void saveTerrain(std::ostream& ost) const override;
};

}

#endif // SAVE_H