#include "observateur.h"

observateur::observateur() :
    d_positionRobot{}, d_directionRobot{robot::direction::BAS}
{}

void observateur::observe(const robot& r)
{
    d_positionRobot = r.positionSurTerrain();
    d_directionRobot = r.directionSurTerrain();
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

