#include "../../doctest.h"
#include "../../caractereLabyrinthe.h"
#include "../../operateursGlobaux.h"
#include <sstream>


TEST_CASE("Test des opérateurs de surcharge operator<< pour caractereLabyrintheAmeliore1 et caractereLabyrintheAmeliore2") {

    SUBCASE("Test pour caractereLabyrintheAmeliore1") {
        fichiers::caractereLabyrintheAmeliore1 l{4,4};
        l(0,0)="+"; l(0,1)="entree";  l(0,2)="-";      l(0,3)="+";
        l(1,0)="|"; l(1,1)=".";       l(1,2)=".";      l(1,3)="|";
        l(2,0)="|"; l(2,1)=".";       l(2,2)="sortie"; l(2,3)="|";
        l(3,0)="+"; l(3,1)="-";       l(3,2)="-";      l(3,3)="+";


        std::ostringstream oss;
        oss << l;

        std::string sortieAttendue ="+⎆-+\n|..|\n|.🔙|\n+--+";

        REQUIRE_EQ(oss.str(), sortieAttendue);
    }

    SUBCASE("Test pour caractereLabyrintheAmeliore2") {
        fichiers::caractereLabyrintheAmeliore2 l{4,4};
        l(0,0)="┏"; l(0,1)="entree";  l(0,2)="━";      l(0,3)="┓";
        l(1,0)="┃"; l(1,1)=".";       l(1,2)=".";      l(1,3)="┃";
        l(2,0)="┃"; l(2,1)=".";       l(2,2)="sortie"; l(2,3)="┃";
        l(3,0)="┗"; l(3,1)="━";       l(3,2)="━";      l(3,3)="┛";

        std::ostringstream oss;
        oss << l;

        // Test du format de sortie avec le caractère de l'entrée et sortie
        std::string sortieAttendue ="┏⎆━┓\n┃..┃\n┃.🔙┃\n┗━━┛";

        REQUIRE_EQ(oss.str(), sortieAttendue);
    }
}
