#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include<memory>
#include<iostream>
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
private:
    position d_positionRobot;
    direction d_directionRobot;
};

class observateurAffichage : public observateur
{public:
    observateurAffichage() = default;
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
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
    observateurCompteurAvancement() ;
    observateurCompteurAvancement(int compteur) ;
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
private:
    position d_positionPrecedente;
};

class observateurCompteurRotation : public observateurCompteur
{public:
    observateurCompteurRotation() ;
    observateurCompteurRotation(int compteur) ;
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
private:
    direction d_directionPrecedente;
};



#endif