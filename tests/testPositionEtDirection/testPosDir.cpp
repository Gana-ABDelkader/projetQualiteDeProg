#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "../../direction.h"
#include "../../position.h"

TEST_CASE("La classe direction est fonctionnelle") {

    int HAUT = direction::HAUT;
    int DROITE = direction::DROITE;
    int BAS = direction::BAS;
    int GAUCHE = direction::GAUCHE;

    SUBCASE("le constructeur par défaut initialise la direction à BAS") {
        direction d;
        CHECK(d.valeurDirection() == BAS);
    }

    SUBCASE("le constructeur avec paramètre initialise la direction à la valeur donnée") {
        direction d(direction::HAUT);
        CHECK(d.valeurDirection() == HAUT);
    }

    SUBCASE("setDirection modifie la direction") {
        direction d;
        d.setDirection(direction::GAUCHE);
        CHECK(d.valeurDirection() == GAUCHE);
    }

    SUBCASE("RotateLeft circule correctement à travers les directions") {
        direction d(direction::HAUT);

        d.RotateLeft();
        CHECK(d.valeurDirection() == GAUCHE);

        d.RotateLeft();
        CHECK(d.valeurDirection() == BAS);

        d.RotateLeft();
        CHECK(d.valeurDirection() == DROITE);

        d.RotateLeft();
        CHECK(d.valeurDirection() == HAUT);
    }

    SUBCASE("RotateRight circule correctement à travers les directions") {
        direction d(direction::HAUT);

        d.RotateRight();
        CHECK(d.valeurDirection() == DROITE);

        d.RotateRight();
        CHECK(d.valeurDirection() == BAS);

        d.RotateRight();
        CHECK(d.valeurDirection() == GAUCHE);

        d.RotateRight();
        CHECK(d.valeurDirection() == HAUT);
    }

    SUBCASE("Equality and inequality operators") {
        direction d1(direction::HAUT);
        direction d2(direction::HAUT);
        direction d3(direction::DROITE);

        CHECK(d1 == d2);
        CHECK(d1 != d3);
    }
}

TEST_CASE("La classe position est fonctionnelle") {

    SUBCASE("le constructeur par défaut initialise la position à (1,1)") {
        position p;
        REQUIRE_EQ(p.positionLigne(), 1);
        REQUIRE_EQ(p.positionColonne(), 1);
    }

    SUBCASE("le constructeur avec paramètres initialise correctement la position") {
        position p(3, 4);
        REQUIRE_EQ(p.positionLigne(), 3);
        REQUIRE_EQ(p.positionColonne(), 4);
    }

    SUBCASE("setLigne modifie la position de la ligne") {
        position p;
        p.setLigne(5);
        REQUIRE_EQ(p.positionLigne(), 5);
        REQUIRE_EQ(p.positionColonne(), 1); // Colonne reste inchangée
    }

    SUBCASE("setColonne modifie la position de la colonne") {
        position p;
        p.setColonne(6);
        REQUIRE_EQ(p.positionColonne(), 6);
        REQUIRE_EQ(p.positionLigne(), 1); // Ligne reste inchangée
    }
}

