#ifndef ROBOT_H
#define ROBOT_H


class robot
{public:
    //constructeur avec position ligne et colonne dans un terrain
    //renvoie sa position
    //void setPosition(...) ;
    bool detectObstacleFront() const;
    bool detectObstacleLeft() const;
    bool detectObstacleRight() const;
    void forward() ;
    void turnLeft() ;
    void turnRight() ;

    //ajoute des observateurs
    //notifie chaque observteurs (faut faire la manip d'etre notifier et tout)
private:
    //position
    //terrain
    //le tableau des observateurs
};

#endif