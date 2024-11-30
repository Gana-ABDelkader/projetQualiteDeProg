#ifndef READ_H
#define READ_H

#include <iostream>
#include <vector>

namespace fichiers {

class read
{
public:
    virtual ~read() =default;
    virtual std::vector<std::vector<bool>> readTerrain(const std::istream& ist) const =0;
};



class readSimple : public read
{
public:
    std::vector<std::vector<bool>> readTerrain(const std::istream& ist) const override;
};



class readAmeliore1 : public read
{
public:
    std::vector<std::vector<bool>> readTerrain(const std::istream& ist) const override;
};



class readAmeliore2 : public read
{
public:
    std::vector<std::vector<bool>> readTerrain(const std::istream& ist) const override;
};

}

#endif // READ_H