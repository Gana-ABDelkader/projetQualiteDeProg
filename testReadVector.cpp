#include "ReadVector.h"
#include "doctest.h"
#include <sstream>
#include <string>
#include <vector>
#include "position.h"



void test_Entree(const position& entree1, int IdLigne)
{
    position entreeLigne{IdLigne,3};
    REQUIRE_EQ(entree1.positionLigne(),entreeLigne.positionLigne());
    REQUIRE_EQ(entree1.positionColonne(),entreeLigne.positionColonne());
}

void test_Sortie(const position& sortie1, int IdLigne)
{
    position sortieLigne{IdLigne,16};
    REQUIRE_EQ(sortie1.positionLigne(),sortieLigne.positionLigne());
    REQUIRE_EQ(sortie1.positionColonne(),sortieLigne.positionColonne());
}

void test_ValeursTableau(const std::vector<bool>& t)
{
    std::vector<bool> flot={true,false,false,false,false,false,false,true,true,true,
            true,false,false,false,false,false,false,false,false,true};
    for(int i=0; i<t.size();i++)
    {
        REQUIRE_EQ(t[i],flot[i]);
    }
}

void test_positionRobot(const position& pos, int IdLigne)
{
    int IdColonne{1};
    REQUIRE_EQ(pos.positionLigne(), IdLigne);
    REQUIRE_EQ(pos.positionColonne(), IdColonne);
}

void test_TailleTableau(const std::vector<bool>& t, int tailleLigne)
{
    REQUIRE_EQ(t.size(),tailleLigne);
}

TEST_CASE("Lire une ligne est correcte")
{
    position entree {-1,-1};
    position sortie {-1,-1};
    position posRobot{-1,-1};
    SUBCASE("Si la ligne simple ou ameliore1 est vide")
    {
        SUBCASE("Le tableau est vide")
        {
            std::string ligne="";
            std::istringstream ist {ligne};
            fichiers::readVectorSimpleAmeliore r{ist};
            std::vector<bool> t= r.readLigne(0);
            test_TailleTableau(t,0);
        }
    }
    SUBCASE("Si la ligne ameliore2 est vide")
    {
        SUBCASE("Le tableau est vide")
        {
            std::string ligne="";
            std::istringstream ist {ligne};
            fichiers::readVectorAmeliore2 r{ist};
            std::vector<bool> t= r.readLigne(0);
            test_TailleTableau(t,0);
        }
    }
    int tailleLigne=20;
    SUBCASE("Si la ligne est caractères simple")
    {
        int IdLigne=2;
        std::string ligne="X>.⎆...XXXX.....🔙..X";
        std::istringstream ist {ligne};
        fichiers::readVectorSimpleAmeliore r{ist};
        std::vector<bool> t= r.readLigne(IdLigne);
        SUBCASE("Le tableau a la bonne taille")
        {
            test_TailleTableau(t,tailleLigne);
        }
        SUBCASE("Le tableau possède les bonne valeurs")
        {
            test_ValeursTableau(t);
        }
        SUBCASE("Les positions sont correctes")
        {
            SUBCASE("La valeur de entrée est correcte")
            {
                test_Entree(r.entree(),IdLigne);
            }
            SUBCASE("La valeur de sortie est correcte")
            {
                test_Sortie(r.sortie(), IdLigne);
            }
            SUBCASE("La valeur de posRobot est correcte")
            {
                test_positionRobot(r.posRobot(), IdLigne);
            }
        }

    }
    SUBCASE("Si la ligne est caractères ameliore1")
    {
        std::string ligne="|>.⎆...+--+.....🔙..|";
        int IdLigne=2;
        std::istringstream ist {ligne};
        fichiers::readVectorSimpleAmeliore r{ist};
        std::vector<bool> t= r.readLigne(IdLigne);
        SUBCASE("Le tableau a la bonne taille")
        {
            test_TailleTableau(t,tailleLigne);
        }
        SUBCASE("Le tableau possède les bonne valeurs")
        {
            test_ValeursTableau(t);
        }
        SUBCASE("Les positions sont correctes")
        {
            SUBCASE("La valeur de entrée est correcte")
            {
                test_Entree(r.entree(),IdLigne);
            }
            SUBCASE("La valeur de sortie est correcte")
            {
                test_Sortie(r.sortie(),IdLigne);
            }
            SUBCASE("La valeur de posRobot est correcte")
            {
                test_positionRobot(r.posRobot(), IdLigne);
            }
        }
    }
    SUBCASE("Si la ligne est caractères ameliore2")
    {
        std::string ligne="┃>.⎆...┗━━┛.....🔙..┃";
        int IdLigne=2;
        std::istringstream ist {ligne};
        fichiers::readVectorAmeliore2 r{ist};
        std::vector<bool> t= r.readLigne(IdLigne);
        SUBCASE("Le tableau a la bonne taille")
        {
            test_TailleTableau(t,tailleLigne);
        }
        SUBCASE("Le tableau possède les bonne valeurs")
        {
            test_ValeursTableau(t);
        }
        SUBCASE("Les positions sont correctes")
        {
            SUBCASE("La valeur de entrée est correcte")
            {
                test_Entree(r.entree(),IdLigne);
            }
            SUBCASE("La valeur de sortie est correcte")
            {
                test_Sortie(r.sortie(),IdLigne);
            }
            SUBCASE("La valeur de posRobot est correcte")
            {
                test_positionRobot(r.posRobot(), IdLigne);
            }
        }
    }

}
