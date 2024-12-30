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
private:
    position d_positionRobot;
    direction d_directionRobot;
};

class observateurCompteurDeplacement : public observateur
{public:
    observateurCompteurDeplacement();
    observateurCompteurDeplacement(int compteur) ;
    int compteurDeplacement() const;
    void incrementerCompteur();
    void observe(const robot& r) override;
    std::unique_ptr<observateur> clone() const override;
private:
    int d_compteurDeplacement;
};



#endif