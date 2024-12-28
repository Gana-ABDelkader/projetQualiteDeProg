#include "../../doctest.h"
#include "../../caractereLabyrinthe.h"


TEST_CASE("Tests des classes de labyrinthe") {
    SUBCASE("Test de caractereLabyrintheAmeliore1") {
        fichiers::caractereLabyrintheAmeliore1 lab(4, 4);

        SUBCASE("Test constructeur") {
            REQUIRE_EQ(lab.nbLigne(), 4);
            REQUIRE_EQ(lab.nbColonne(), 4);
        }

        SUBCASE("Test de l'opérateur ()") {
            lab(0, 0) = "+";
            lab(1, 1) = "-";
            REQUIRE_EQ(lab(0, 0), "+");
            REQUIRE_EQ(lab(1, 1), "-");
        }

        SUBCASE("Test corrigerCaracteresDepandantDesAutres") {
            lab(0, 0) = "+";
            lab(0, 1) = "+";
            lab(0, 2) = "+";
            lab.corrigerCaracteresDepandantDesAutres();
            REQUIRE_EQ(lab(0, 0), "+");
            REQUIRE_EQ(lab(0, 1), "#");
            REQUIRE_EQ(lab(0, 2), "+");
        }
    }

    SUBCASE("Test de caractereLabyrintheAmeliore2") {
        fichiers::caractereLabyrintheAmeliore2 lab(7, 7);

        SUBCASE("Test constructeur") {
            REQUIRE_EQ(lab.nbLigne(), 7);
            REQUIRE_EQ(lab.nbColonne(), 7);
        }

        SUBCASE("Test de l'opérateur ()") {
            lab(0, 0) = "━";
            lab(4, 4) = "┃";
            REQUIRE_EQ(lab(0, 0), "━");
            REQUIRE_EQ(lab(4, 4), "┃");
        }

        SUBCASE("Test corrigerCaracteresDepandantDesAutres") {
            lab(0,1) = "━";
            lab(0,2) ="┳";
            lab(0,3) ="┳";
            lab(0,4) ="┳";
            lab(0,5) ="┳";
            lab(0,6) ="━";
            lab.corrigerCaracteresDepandantDesAutres();
            REQUIRE_EQ(lab(0,1) , "━");
            REQUIRE_EQ(lab(0,2) , "┓");
            REQUIRE_EQ(lab(0,3) , "▄");
            REQUIRE_EQ(lab(0,4) , "▄");
            REQUIRE_EQ(lab(0,5) , "┏");
            REQUIRE_EQ(lab(0,6) , "━");
        }
    }
}

