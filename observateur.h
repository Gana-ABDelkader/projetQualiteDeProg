#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include<memory>
class robot;

class observateur
{
public:
    virtual ~observateur() = default ;
    observateur() ;
    virtual void observe(const robot& r) ;
    virtual std::unique_ptr<observateur> clone() const = 0;
private:
    position d_positionRobot;
    //robot::direction d_directionRobot;
};

class observateurCompteurDeplacement : public observateur
{public:
    observateurCompteurDeplacement();
    observateurCompteurDeplacement(int compteur) ;
    int CompteurDeplacement() const;
    void observe(const robot& r) override;
    void IncrementerCompteur();
    std::unique_ptr<observateur> clone() const override;
private:
    int d_compteurDeplacement;
};



#endif