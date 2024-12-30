#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

class robot;

class observateur
{
public:
    virtual ~observateur() = default ;
    observateur() ;
    virtual void observe(const robot& r) ;
private:
    position d_positionRobot;
    //robot::direction d_directionRobot;
};

class observateurCompteurDeplacement : public observateur
{public:
    observateurCompteurDeplacement();
    int CompteurDeplacement() const;
    void observe(const robot& r) override;
    void IncrementerCompteur();
private:
    int d_compteurDeplacement;
};



#endif