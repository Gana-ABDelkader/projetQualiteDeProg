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

direction observateur::directionRobot() const
{
    return d_directionRobot;
}

position observateur::positionRobot() const
{
    return d_positionRobot;
}

void observateurAffichage::observe(const robot& r) 
{
    observateur::observe(r);
    std::cout << "Position du robot : x -> " << positionRobot().positionLigne() << " y -> " << positionRobot().positionColonne() << std::endl;
    std::cout << "Direction du robot : " << directionRobot().valeurDirection() << std::endl;
}

std::unique_ptr<observateur> observateurAffichage::clone() const 
{
    return std::make_unique<observateurAffichage>();
}

observateurCompteur::observateurCompteur() :
    observateur{}, d_compteur{0}, d_estInitialise{false}
{}

observateurCompteur::observateurCompteur(int compteur) :
    observateur{}, d_compteur{compteur}, d_estInitialise{false}
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
    d_compteur = d_compteur + 1;
}

observateurCompteurAvancement::observateurCompteurAvancement() :
    observateurCompteur{}
{}

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
   std::cout << "Nombre d'avancement : " << compteur() << std::endl;
}

std::unique_ptr<observateur> observateurCompteurAvancement::clone() const
{
    return std::make_unique<observateurCompteurAvancement>(compteur());
}

observateurCompteurRotation::observateurCompteurRotation() :
    observateurCompteur{}
{}

observateurCompteurRotation::observateurCompteurRotation(int compteur) :
    observateurCompteur{compteur}
{}

void observateurCompteurRotation::observe(const robot& r)
{
    observateur::observe(r);
    if(! estInitialise()) {
        initialiser();
        d_directionPrecedente = directionRobot();
    }
   else
   {
        if(directionRobot() != d_directionPrecedente)
        {
            incrementerCompteur();
            d_directionPrecedente = directionRobot();
        }
   }
    std::cout << "Nombre de rotation : " << compteur() << std::endl;
}

std::unique_ptr<observateur> observateurCompteurRotation::clone() const
{
    return std::make_unique<observateurCompteurRotation>(compteur());
}




