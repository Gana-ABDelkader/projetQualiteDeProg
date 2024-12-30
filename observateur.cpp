#include "observateur.h"
#include "robot.h"

observateur::observateur() :
    d_positionRobot{}
{}

void observateur::observe(const robot& r)
{
    d_positionRobot = r.positionSurTerrain();
    //d_directionRobot = r.directionSurTerrain();
}

observateurCompteurDeplacement::observateurCompteurDeplacement() :
    d_compteurDeplacement{0}
{}

int observateurCompteurDeplacement::CompteurDeplacement() const
{
    return d_compteurDeplacement;
}

void observateurCompteurDeplacement::IncrementerCompteur()
{
    d_compteurDeplacement++;
}

void observateurCompteurDeplacement::observe(const robot& r)
{
    observateur::observe(r);
    IncrementerCompteur();
}

