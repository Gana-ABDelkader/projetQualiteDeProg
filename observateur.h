#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include<memory>
#include "position.h"
#include "direction.h"

class robot;

class observateur
{
public:
    observateur() ;
    virtual ~observateur() = default ;
    virtual void observe(const robot& r) ;
    virtual std::unique_ptr<observateur> clone() const = 0;
    position positionRobot() const ;
    direction directionRobot() const ;
    int directionRobotInt() const ; //une valeur de 0 a 3 [0 = HAUT, 1 = DROITE, 2 = BAS, 3 = GAUCHE]
private:
    position d_positionRobot;
    direction d_directionRobot;
};

class observateurAffichage : public observateur
{public:
    observateurAffichage(std::istream& ist = std::cin, std::ostream& ost = std::cout);
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
private:    
    std::istream& d_ist;
    std::ostream& d_ost;
};

class observateurCompteur : public observateur
{public:
    observateurCompteur();
    observateurCompteur(int compteur) ;
    int compteur() const;
    bool estInitialise() const;
    void initialiser();
    void incrementerCompteur();
    void observe(const robot& r) override = 0;
private:
    int d_compteur;
    bool d_estInitialise ;
};

class observateurCompteurAvancement : public observateurCompteur
{public:
    observateurCompteurAvancement(int compteur) ;
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
private:
    position d_positionPrecedente;
};

class observateurCompteurRotation : public observateurCompteur
{public:
    observateurCompteurRotation(int compteur) ;
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
private:
    direction d_directionPrecedente;
};



#endif