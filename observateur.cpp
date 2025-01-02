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

int observateur::directionRobotInt() const
{
    return d_directionRobot.valeurDirectionInt();
}

direction observateur::directionRobot() const
{
    return d_directionRobot;
}

position observateur::positionRobot() const
{
    return d_positionRobot;
}
observateurAffichage::observateurAffichage(std::istream& ist = std::cin, std::ostream& ost = std::cout) :
    observateur{}, d_ist{ist}, d_ost{ost}
{}

void observateurAffichage::observe(const robot& r) 
{
    observateur::observe(r);
    d_ost << "Position du robot : x -> " << positionRobot().positionLigne() << " y -> " << positionRobot().positionColonne() << std::endl;
    d_ost << "Direction du robot : " << directionRobotInt() << std::endl;
}

std::unique_ptr<observateur> observateurAffichage::clone() const 
{
    return std::make_unique<observateurAffichage>(d_ist, d_ost);
}

observateurCompteur::observateurCompteur() :
    observateur{}, d_compteur{0}, d_estInitialise{false}
{}

observateurCompteur::observateurCompteur(int compteur) :
    observateur{}, d_compteur{compteur}, d_estInitialise{true}
{}

int observateurCompteur::compteur() const
{
    return d_compteur;
}

bool observateurCompteur::estInitialise() const
{
    return d_estInitialise;
}

void observateurCompteur::initialiser()
{
    d_estInitialise = true;
}

void observateurCompteur::incrementerCompteur()
{
    d_compteur++;
}

observateurCompteurAvancement::observateurCompteurAvancement(int compteur) :
    observateurCompteur{compteur}
{}

void observateurCompteurAvancement::observe(const robot& r)
{
    observateur::observe(r);
    if(! estInitialise()) {
        initialiser();
        d_positionPrecedente = positionRobot();
    }
   else
   {
        if(positionRobot() != d_positionPrecedente)
        {
            incrementerCompteur();
            d_positionPrecedente = positionRobot();
        }
   }
}

std::unique_ptr<observateur> observateurCompteurAvancement::clone() const
{
    return std::make_unique<observateurCompteurAvancement>(compteur());
}

observateurCompteurRotation::observateurCompteurRotation(int compteur) :
    observateurCompteur{compteur}
{}

void observateurCompteurRotation::observe(const robot& r)
{
    observateur::observe(r);
    if(! estInitialise()) {
        initialiser();
        //d_directionPrecedente.setDirection(directionRobot());
    }
   else
   {
        if(directionRobotInt() != d_directionPrecedente.valeurDirectionInt())
        {
            incrementerCompteur();
            d_directionPrecedente = directionRobot();
        }
   }
}




