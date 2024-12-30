#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include"../../doctest.h"
#include"../../robot.h"

TEST_CASE("Les consructeurs fonctionnent correctement") {
    SUBCASE("Le constructeur par defaut fonctionne"){
        robot r{};
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), 1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), 1);
        REQUIRE_EQ(r.directionSurTerrain(), direction::valeur::BAS);
    }
    SUBCASE("Le constructeur avec parametre fonctionne"){
        position p{2,5};
        terrain t{};
        robot r{p,direction::valeur::DROITE,t};
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne());
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
        REQUIRE_EQ(r.directionSurTerrain(), direction::valeur::DROITE);
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
        r.setDirection(direction::valeur::DROITE);
        REQUIRE_EQ(r.directionSurTerrain(), direction::valeur::DROITE);
    }
}

TEST_CASE("La methode calculatePosition fonctionne correctement"){
    position p{2,1};
    robot r{p,direction::valeur::BAS,terrain{}};
    position pos{};
    SUBCASE("Le robot est en bas"){
        pos = r.calculateNewPosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne()+1);
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne());
    }
    SUBCASE("Le robot est en haut"){
        r.setDirection(direction::valeur::HAUT);
        pos = r.calculateNewPosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne()-1);
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne());
    }
    SUBCASE("Le robot est a droite"){
        r.setDirection(direction::valeur::DROITE);
        pos = r.calculateNewPosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne());
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne()+1);
    }
    SUBCASE("Le robot est a gauche"){
        r.setDirection(direction::valeur::GAUCHE);
        pos = r.calculateNewPosition();
        REQUIRE_EQ(pos.positionLigne(), p.positionLigne());
        REQUIRE_EQ(pos.positionColonne(), p.positionColonne()-1);
    }
}

/*un terrain par defaut il n'est intialise? Pour l'instant j'arrive pas a tester sur des cases d'un terrain par defaut
il faut que j'attend que les methodes de terrain soient tester*/
TEST_CASE("La methode detectObstacle fonctionne correctement"){ 
    SUBCASE("Il y a un obstacle"){
        terrain t{};
        robot r{{1,1},direction::valeur::HAUT,t};
        r.move();
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), 1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), 1);
    }
}

TEST_CASE("La methode move fonctionne correctement"){
    SUBCASE("Il y a un mur donc pas de changement"){
        terrain t{};
        position p{1,2};
        robot r{p,direction::valeur::HAUT,t};
        //le labyrinthe est entouré de murs, j'utilise cet methode pour le tester
        t.changeenMur({0,2});
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne());
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
    }
    SUBCASE("Il n'y a pas de mur donc le robot avance"){
        terrain t{};
        position p{2,2};
        robot r{p,direction::valeur::HAUT,t};
        r.move();
        REQUIRE_EQ(r.positionSurTerrain().positionLigne(), p.positionLigne()-1);
        REQUIRE_EQ(r.positionSurTerrain().positionColonne(), p.positionColonne());
    }
}

TEST_CASE("Les methodes de changement de direction fonctionnent correctement"){
    robot r{};
    SUBCASE("turnLeft fonctionne"){
        direction d = static_cast<direction::valeur>(static_cast<direction::valeur>((r.directionSurTerrain().valeurDirectionInt()+3)%4));
        r.turnLeft();
        REQUIRE_EQ(r.directionSurTerrain(), d);
    }
    SUBCASE("turnRight fonctionne"){
        direction d = static_cast<direction::valeur>(static_cast<direction::valeur>((r.directionSurTerrain().valeurDirectionInt()+1)%4));
        r.turnRight();
        REQUIRE_EQ(r.directionSurTerrain(), d);
    }
}

