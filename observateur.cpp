#include "observateur.h"
#include "robot.h"

observateur::observateur() :
    d_positionRobot{}, d_directionRobot{}
{}

void observateur::observe(const robot& r)
{
    d_positionRobot = r.positionSurTerrain();
    d_directionRobot = r.directionSurTerrain();
}

observateurCompteurDeplacement::observateurCompteurDeplacement() :
    observateur{}, d_compteurDeplacement{0}
{}

observateurCompteurDeplacement::observateurCompteurDeplacement(int compteur) :
    observateur{}, d_compteurDeplacement{compteur}
{}

int observateurCompteurDeplacement::compteurDeplacement() const
{
    return d_compteurDeplacement;
}

void observateurCompteurDeplacement::incrementerCompteur()
{
    d_compteurDeplacement++;
}

void observateurCompteurDeplacement::observe(const robot& r)
{
    observateur::observe(r);
    incrementerCompteur();
}

std::unique_ptr<observateur> observateurCompteurDeplacement::clone() const
{
    return std::make_unique<observateurCompteurDeplacement>(d_compteurDeplacement);
}

