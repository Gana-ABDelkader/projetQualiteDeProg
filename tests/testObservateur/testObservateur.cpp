#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "../../observateur.h"
#include "../../robot.h"

TEST_CASE("Les méthodes de observateurAffichage fonctionnent correctement") {
    position pos{5, 5};
    terrain t{};
    robot r{pos, direction::HAUT, t};
    observateurAffichage oa;

    SUBCASE("La méthode observe affiche les informations du robot") {
        oa.observe(r);
    }

    SUBCASE("La méthode clone retourne un clone valide") {
        auto clone = oa.clone();
        REQUIRE_NE(clone, nullptr);
        REQUIRE(dynamic_cast<observateurAffichage*>(clone.get()) != nullptr);
    }
}

TEST_CASE("Les méthodes de observateurCompteurAvancement fonctionnent correctement") {
    position pos{3, 3};
    terrain t{};
    robot r{pos, direction::HAUT, t};
    observateurCompteurAvancement oca;

    SUBCASE("Initialisation et avancement comptés correctement") {
        oca.observe(r);
        REQUIRE_EQ(oca.compteur(), 0);

        r.move();
        oca.observe(r);
        REQUIRE_EQ(oca.compteur(), 1);

        r.move();
        oca.observe(r);
        REQUIRE_EQ(oca.compteur(), 2);
    }

    //verifie que l'observateur retouner par le clone est bien un observateurAffichage
    SUBCASE("La méthode clone retourne un clone valide") {
        auto clone = oca.clone();
        REQUIRE_NE(clone, nullptr);
        REQUIRE(dynamic_cast<observateurCompteurAvancement*>(clone.get()) != nullptr);
    }
}

TEST_CASE("Les méthodes de observateurCompteurRotation fonctionnent correctement") {
    position pos{4, 4};
    terrain t{};
    robot r{pos, direction::GAUCHE, t};
    observateurCompteurRotation ocr;

    SUBCASE("Initialisation et rotations comptées correctement") {
        ocr.observe(r);
        REQUIRE_EQ(ocr.compteur(), 0);

        r.turnLeft();
        ocr.observe(r);
        REQUIRE_EQ(ocr.compteur(), 1);

        r.turnRight();
        ocr.observe(r);
        REQUIRE_EQ(ocr.compteur(), 2);
    }

    SUBCASE("La méthode clone retourne un clone valide") {
        auto clone = ocr.clone();
        REQUIRE_NE(clone, nullptr);
        REQUIRE(dynamic_cast<observateurCompteurRotation*>(clone.get()) != nullptr);
    }
}

