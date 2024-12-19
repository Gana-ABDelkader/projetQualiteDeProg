#include "ReadVector.h"
#include "doctest.h"
#include <sstream>
#include <string>
#include <vector>
#include "position.h"


void test_Entree(const position& entree1)
{
    position entreeLigne{3,2};
    REQUIRE_EQ(entree1.positionLigne,entreeLigne.positionLigne);
    REQUIRE_EQ(entree1.positionColonne,entreeLigne.positionColonne);
}

void test_Sortie(const position& sortie1)
{
    position sortieLigne{16,2};
    REQUIRE_EQ(sortie1.positionLigne,sortieLigne.positionLigne);
    REQUIRE_EQ(sortie1.positionColonne,sortieLigne.positionColonne);
}

void test_ValeursTableau(const std::vector<bool>& t)
{
    std::vector<bool> flot=[true,false,false,false,false,false,false,true,true,true,
            true,false,false,false,false,false,false,false,false,true];
    for(int i=0; i<t.size();i++)
    {
        REQUIRE_EQ(t[i]==flot[i]);
    }
}

void test_TailleTableau(const std::vector<bool>& t)
{
    int tailleLigne=20;
    REQUIRE_EQ(t.size(),tailleLigne);
}

TEST_CASE("Lire une ligne est correcte")
{
    position entree;
    position sortie;
    SUBCASE("Si la ligne est vide")
    {
        SUBCASE("Le tableau est vide")
        {
            std::string ligne="";
            std::istringstream ist {ligne};
            fichier::readVector r;
            std::vector<bool> t= r.readLigne(ist,entree,sortie,0);
            REQUIRE_EQ(t.size(),0);
        }
    }
    SUBCASE("Si la ligne est caractères simple")
    {
        std::string ligne="X..⎆...XXXX.....🔙..X";
        int ligne=2;
        std::istringstream ist {ligne};
        std::vector<bool> t= r.readLigne(ist,entree,sortie,ligne);
        SUBCASE("Le tableau a la bonne taille")
        {
            test_TailleTableau(t);
        }
        SUBCASE("Le tableau possède les bonne valeurs")
        {
            test_ValeursTableau(t);
        }
        SUBCASE("Les positions sont correctes")
        {
            SUBCASE("La valeur de entrée est correcte")
            {
                test_Entree(entree);
            }
            SUBCASE("La valeur de sortie est correcte")
            {
                test_Sortie(sortie);
            }
        }
        
    }
    SUBCASE("Si la ligne est caractères ameliore1")
    {
        std::string ligne="|..⎆...+--+.....🔙..|";
        int ligne=2;
        std::istringstream ist {ligne};
        std::vector<bool> t= r.readLigne(ist,entree,sortie,ligne);
        SUBCASE("Le tableau a la bonne taille")
        {
            test_TailleTableau(t);
        }
        SUBCASE("Le tableau possède les bonne valeurs")
        {
            test_ValeursTableau(t);
        }
        SUBCASE("Les positions sont correctes")
        {
            SUBCASE("La valeur de entrée est correcte")
            {
                test_Entree(entree);
            }
            SUBCASE("La valeur de sortie est correcte")
            {
                test_Sortie(sortie);
            }
        }
    }
    SUBCASE("Si la ligne est caractères ameliore2")
    {
        std::string ligne="┃..⎆...┗━━┛.....🔙..┃";
        int ligne=2;
        std::istringstream ist {ligne};
        std::vector<bool> t= r.readLigne(ist,entree,sortie,ligne);
        SUBCASE("Le tableau a la bonne taille")
        {
            test_TailleTableau(t);
        }
        SUBCASE("Le tableau possède les bonne valeurs")
        {
            test_ValeursTableau(t);
        }
        SUBCASE("Les positions sont correctes")
        {
            SUBCASE("La valeur de entrée est correcte")
            {
                test_Entree(entree);
            }
            SUBCASE("La valeur de sortie est correcte")
            {
                test_Sortie(sortie);
            }
        }
    }
    
}
