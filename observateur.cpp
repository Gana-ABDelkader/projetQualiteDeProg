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

observateurCompteurDeplacement::observateurCompteurDeplacement(int compteur) :
    d_compteurDeplacement{compteur}
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

std::unique_ptr<observateur> observateurCompteurDeplacement::clone() const
{
    return std::make_unique<observateurCompteurDeplacement>(d_compteurDeplacement);
}

