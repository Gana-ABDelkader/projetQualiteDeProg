#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include"../../doctest.h"
#include"../../robot.h"

TEST_CASE("Les consructeurs fonctionnent correctement") {
    SUBCASE("Le constructeur par defaut fonctionne"){
        robot r{};
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), 1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), 1);
        REQUIRE_EQ(r.directionSurTerrain(), robot::BAS);
    }
    SUBCASE("Le constructeur avec parametre fonctionne"){
        position p{2,5};
        terrain t{};
        robot r{p,robot::DROITE,t};
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne());
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
        REQUIRE_EQ(r.directionSurTerrain(), robot::DROITE);
    }
}

TEST_CASE("Les methodes Set fonctionnent correctement"){
    robot r{};
    SUBCASE("setPosition fonctionne"){
        position p{7,3};
        r.setPosition(p);
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne());
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
    }
    SUBCASE("setDirection fonctionne"){
        r.setDirection(robot::DROITE);
        REQUIRE_EQ(r.directionSurTerrain(), robot::DROITE);
    }
}

TEST_CASE("La methode calculatePosition fonctionne correctement"){
    position p{2,1};
    robot r{p,robot::BAS,terrain{}};
    position pos{};
    SUBCASE("Le robot est en bas"){
        pos = r.calculatePosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne()+1);
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne());
    }
    SUBCASE("Le robot est en haut"){
        r.setDirection(robot::HAUT);
        pos = r.calculatePosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne()-1);
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne());
    }
    SUBCASE("Le robot est a droite"){
        r.setDirection(robot::DROITE);
        pos = r.calculatePosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne());
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne()+1);
    }
    SUBCASE("Le robot est a gauche"){
        r.setDirection(robot::GAUCHE);
        pos = r.calculatePosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne());
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne()-1);
    }
}

/*un terrain par defaut il n'est intialise? Pour l'instant j'arrive pas a tester sur des cases d'un terrain par defaut
il faut que j'attend que les methodes de terrain soient tester*/
TEST_CASE("La methode detectObstacle fonctionne correctement"){
    SUBCASE("Il n'y a pas d'obstacle"){
        terrain t{};
        robot r{{1,1},robot::BAS,t};
        REQUIRE_UNARY_FALSE(r.detectObstacle());
    }
    SUBCASE("Il y a un obstacle"){
        terrain t{};
        robot r{{1,1},robot::HAUT,t};
        REQUIRE_UNARY(r.detectObstacle());
    }
}

TEST_CASE("La methode move fonctionne correctement"){
    SUBCASE("Il y a un mur donc pas de changement"){
        terrain t{};
        position p{1,2};
        robot r{p,robot::HAUT,t};
        //le labyrinthe est entouré de murs, j'utilise cet methode pour le tester
        t.changeenMur({0,2});
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne());
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
    }
    SUBCASE("Il n'y a pas de mur donc le robot avance"){
        terrain t{};
        position p{2,2};
        robot r{p,robot::HAUT,t};
        r.move();
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne()-1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
    }
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

