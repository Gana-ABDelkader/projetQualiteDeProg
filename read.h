#ifndef READ_H
#define READ_H

#include <iostream>
#include <vector>

class terrain;

namespace fichiers {

class read
{
public:
    virtual ~read() =default;
    virtual terrain readTerrain(const std::istream& ist) const =0;
};



class readSimple : public read
{
public:
    terrain readTerrain(const std::istream& ist) const override;
};



class readAmeliore1 : public read
{
public:
    terrain readTerrain(const std::istream& ist) const override;
};



class readAmeliore2 : public read
{
public:
    terrain readTerrain(const std::istream& ist) const override;
};

}

#endif // READ_H