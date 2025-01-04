#include "read.h"
#include "doctest.h"
#include <sstream>
#include <string>
#include <vector>
#include "position.h"
#include "terrain.h"
#include "robot.h"

void test_TailleTerrain(const terrain& t, int nbLigne)
{
    REQUIRE_EQ(t.tailleTableau(),nbLigne);
}

void test_positionEntree(const terrain& t)
{
    position entree{0,5};
    REQUIRE_EQ(t.caseEntree().positionLigne(), entree.positionLigne());
    REQUIRE_EQ(t.caseEntree().positionColonne(),entree.positionColonne());
}

void test_positionSortie(const terrain& t)
{
    position sortie{2,14};
    REQUIRE_EQ(t.caseSortie().positionLigne(), sortie.positionLigne());
    REQUIRE_EQ(t.caseSortie().positionColonne(),sortie.positionColonne());
}

void test_positionRobot(const robot& r)
{
    position posRobot{1,1};
    REQUIRE_EQ(r.positionSurTerrain().positionLigne(), posRobot.positionLigne());
    REQUIRE_EQ(r.positionSurTerrain().positionColonne(), posRobot.positionColonne());
}

void test_positionRobotEntree(const robot& r)
{
    position posRobot{0,5};
    REQUIRE_EQ(r.positionSurTerrain().positionLigne(), posRobot.positionLigne());
    REQUIRE_EQ(r.positionSurTerrain().positionColonne(), posRobot.positionColonne());
}

TEST_CASE("La lecture est correcte")
{
    SUBCASE("Si le fichier est vide, le tableau est vide")
    {
        int nbLigne{0};
        std::string ligne;
        std::istringstream ist {ligne};
        SUBCASE("Le fichier est en caractere simple ou ameliore1")
        {
            fichiers::readSimpleAmeliore r{ist};
            terrain t = r.readTerrain().terrainDeLabyrinthe();
            test_TailleTerrain(t,nbLigne);

        }
        SUBCASE("Le fichier est en caractere ameliore2")
        {
            fichiers::readAmeliore2 r{ist};
            terrain t = r.readTerrain().terrainDeLabyrinthe();
            test_TailleTerrain(t,nbLigne);
        }

    }
    int nbLigne{3};
    SUBCASE("Si fichier est en caractere simple")
    {
        std::string ligne="XXXXX⎆XXXXXXXXXXXXXX\nX>.....XXXX........X\nX.............🔙....X";
        std::istringstream ist {ligne};
        fichiers::readSimpleAmeliore r{ist};
        robot rob=r.readTerrain();
        terrain t= rob.terrainDeLabyrinthe();
        SUBCASE("Le terrain a le bon nombre de ligne")
        {
           test_TailleTerrain(t,nbLigne);
        }
        SUBCASE("Le terrain a la bonne case entree")
        {
            test_positionEntree(t);
        }
        SUBCASE("Le terrain a la bonne case sortie")
        {
            test_positionSortie(t);
        }
        SUBCASE("Le robot a la bonne position")
        {
            SUBCASE("Si le robot est dans le labyrinthe")
            {
                test_positionRobot(rob);
            }
            SUBCASE("Si le robot est sur entree")
            {
                std::string ligne2="XXXXX⎆XXXXXXXXXXXXXX\nX......XXXX........X\nX.............🔙....X";
                std::istringstream ist2 {ligne2};
                fichiers::readSimpleAmeliore r2{ist2};
                robot rob2=r2.readTerrain();
                terrain t2= rob2.terrainDeLabyrinthe();
                test_positionRobotEntree(rob2);
            }
        }
    }
    SUBCASE("Si le fichier est en caractere ameliore1")
    {
        std::string ligne="+----⎆-+##+--------+\n|>.....+--+........|\n|.............🔙....|";
        std::istringstream ist {ligne};
        fichiers::readSimpleAmeliore r{ist};
        robot rob=r.readTerrain();
        terrain t= rob.terrainDeLabyrinthe();
        SUBCASE("Le terrain a le bon nombre de ligne")
        {
            test_TailleTerrain(t,nbLigne);
        }
        SUBCASE("Le terrain a la bonne case entree")
        {
            test_positionEntree(t);
        }
        SUBCASE("Le terrain a la bonne case sortie")
        {
            test_positionSortie(t);
        }
        SUBCASE("Le robot a la bonne position")
        {
            SUBCASE("Si le robot est dans le labyrinthe")
            {
                test_positionRobot(rob);
            }
            SUBCASE("Si le robot est sur entree")
            {
                std::string ligne2="+----⎆-+##+--------+\n|......+--+........|\n|.............🔙....|";
                std::istringstream ist2 {ligne2};
                fichiers::readSimpleAmeliore r2{ist2};
                robot rob2=r2.readTerrain();
                terrain t2= rob2.terrainDeLabyrinthe();
                test_positionRobotEntree(rob2);
            }
        }
    }
    SUBCASE("Si le fichier est en caractere ameliore2")
    {
        std::string ligne="┏━━━━⎆━┓▄▄┏━━━━━━━━┓\n┃>.....┗━━┛........┃\n┃.............🔙....┃";
        std::istringstream ist {ligne};
        fichiers::readAmeliore2 r{ist};
        robot rob=r.readTerrain();
        terrain t= rob.terrainDeLabyrinthe();
        SUBCASE("Le terrain a le bon nombre de ligne")
        {
            test_TailleTerrain(t,nbLigne);
        }
        SUBCASE("Le terrain a la bonne case entree")
        {
            test_positionEntree(t);
        }
        SUBCASE("Le terrain a la bonne case sortie")
        {
            test_positionSortie(t);
        }
        SUBCASE("Le robot a la bonne position")
        {
            SUBCASE("Si le robot est dans le labyrinthe")
            {
                test_positionRobot(rob);
            }
            SUBCASE("Si le robot est sur entree")
            {
                std::string ligne2="┏━━━━⎆━┓▄▄┏━━━━━━━━┓\n┃......┗━━┛........┃\n┃.............🔙....┃";
                std::istringstream ist2 {ligne2};
                fichiers::readAmeliore2 r2{ist2};
                robot rob2=r2.readTerrain();
                terrain t2= rob2.terrainDeLabyrinthe();
                test_positionRobotEntree(rob2);
            }
        }
    }
}
