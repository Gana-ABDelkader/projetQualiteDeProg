#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include"../../doctest.h"
#include"../../robot.h"
#include "../../position.h" 
#include "../../terrain.h" 

/*
ce qu'il faut tester
le set terrain a besoin d'un operator == pour le comparer
s'il detecte bien les obstacles mais il faut que j'ai un terrain avec des mur pour ca 
si le move dans des differnetes direction marche bien
le changement de direction
*/ 

TEST_CASE("Les consructeurs fonctionnent correctement") {
    SUBCASE("Le constructeur par defaut fonctionne"){
        robot r{};
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), 0);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), 0);
        REQUIRE_EQ(r.directionSurTerrain(), robot::HAUT);
    }
    SUBCASE("Le constructeur avec parametre fonctionne"){
        position p{1,1};
        terrain t{};
        robot r{p,robot::BAS,t};
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), 1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), 1);
        REQUIRE_EQ(r.directionSurTerrain(), robot::BAS);
    }
}

TEST_CASE("Les methodes Set fonctionnent correctement"){
    robot r{};
    SUBCASE("setPosition fonctionne"){
        position p{1,1};
        r.setPosition(p);
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), 1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), 1);
    }
    SUBCASE("setDirection fonctionne"){
        r.setDirection(robot::BAS);
        REQUIRE_EQ(r.directionSurTerrain(), robot::BAS);
    }
}

TEST_CASE("La methode detectObstacle fonctionne correctement"){
   
}

TEST_CASE("La methode move fonctionne correctement"){

}

TEST_CASE("Les methodes de changement de direction fonctionnent correctement"){
    robot r{};
    SUBCASE("goUp fonctionne"){
        r.goUp();
        REQUIRE_EQ(r.directionSurTerrain(), robot::HAUT);
    }
    SUBCASE("goDown fonctionne"){
        r.goDown();
        REQUIRE_EQ(r.directionSurTerrain(), robot::BAS);
    }
    SUBCASE("turnLeft fonctionne"){
        r.turnLeft();
        REQUIRE_EQ(r.directionSurTerrain(), robot::GAUCHE);
    }
    SUBCASE("turnRight fonctionne"){
        r.turnRight();
        REQUIRE_EQ(r.directionSurTerrain(), robot::DROITE);
    }
}