#include "../../doctest.h"
#include "../../testCasesVector.h"



TEST_CASE("Tests ajust�s pour testCasesVector avec inversion des valeurs") {
    // Grille de test
    std::vector<std::vector<bool>> vecteur = {
        {true,  true,  true,  true,  true},
        {true,  false, true,  false ,true},
        {true,  true,  false, true , true},
        {true,  true,  true,  true , true},
        {true,  true,  true,  true,  true}
    };

    fichiers::testCasesVector testVector(vecteur);

    SUBCASE("Test du constructeur et dimensions") {
        REQUIRE_EQ(testVector.nbLigne(), 5);
        REQUIRE_EQ(testVector.nbColonne(), 5);
    }

    SUBCASE("Test estMur()") {
        REQUIRE_EQ(testVector.estMur(0, 0), true);
        REQUIRE_EQ(testVector.estMur(1, 1), false);
        REQUIRE_EQ(testVector.estMur(3, 3), true);
    }

    SUBCASE("Test estPlusAuBord()") {
        REQUIRE_EQ(testVector.estPlusAuBord(0, 0), true);
        REQUIRE_EQ(testVector.estPlusAuBord(0, 2), true);
        REQUIRE_EQ(testVector.estPlusAuBord(1, 4), false);
    }

    SUBCASE("Test estPlusALInterieur()") {
        REQUIRE_EQ(testVector.estPlusALInterieur(2, 1), true);
        REQUIRE_EQ(testVector.estPlusALInterieur(1, 2), false);
    }

    SUBCASE("Test estIntersectionBasse()") {
        REQUIRE_EQ(testVector.estIntersectionBasse(0, 2), true);
        REQUIRE_EQ(testVector.estIntersectionBasse(0, 3), false);
    }

    SUBCASE("Test estIntersectionDroite()") {
        REQUIRE_EQ(testVector.estIntersectionDroite(1, 2), false);
        REQUIRE_EQ(testVector.estIntersectionDroite(1, 1), true);
    }

    SUBCASE("Test estIntersectionGauche()") {
        REQUIRE_EQ(testVector.estIntersectionGauche(2, 1), false);
        REQUIRE_EQ(testVector.estIntersectionGauche(1, 1), true);
    }

    SUBCASE("Test estIntersectionHaute()") {
        REQUIRE_EQ(testVector.estIntersectionHaute(1, 2), false);
        REQUIRE_EQ(testVector.estIntersectionHaute(1, 1), true);
    }

    SUBCASE("Test estIntersection4Mur()") {
        REQUIRE_EQ(testVector.estIntersection4Mur(2, 1), false);
        REQUIRE_EQ(testVector.estIntersection4Mur(3, 1), true);
    }

    SUBCASE("Test estAngleHautDroit()") {
        REQUIRE_EQ(testVector.estAngleHautDroit(0, 3), false);
        REQUIRE_EQ(testVector.estAngleHautDroit(1, 1), true);
    }

    SUBCASE("Test estAngleHautGauche()") {
        REQUIRE_EQ(testVector.estAngleHautGauche(0, 0), true);
        REQUIRE_EQ(testVector.estAngleHautGauche(1, 2), false);
    }

    SUBCASE("Test estAngleBasDroit()") {
        REQUIRE_EQ(testVector.estAngleBasDroit(2, 3), false);
        REQUIRE_EQ(testVector.estAngleBasDroit(3, 1), true);
    }

    SUBCASE("Test estAngleBasGauche()") {
        REQUIRE_EQ(testVector.estAngleBasGauche(2, 1), false);
        REQUIRE_EQ(testVector.estAngleBasGauche(3, 1), true);
    }

    SUBCASE("Test estMurHorizontal()") {
        REQUIRE_EQ(testVector.estMurHorizontal(2, 1), false);
        REQUIRE_EQ(testVector.estMurHorizontal(1, 1), true);
    }
}




