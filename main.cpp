#include <iostream>

using namespace std;

#include"position.h"
#include"robot.h"
int main() {
    position p{2,5};
    robot r{};
    r.setPosition(p);
    cout << p.positionLigne() << " " << p.positionColonne() << endl;
    cout << r.positionSurTerrain().positionLigne() << " " << r.positionSurTerrain().positionColonne() << endl;
    return 0;
} 

