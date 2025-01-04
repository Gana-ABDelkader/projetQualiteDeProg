#include "doctest.h"
#include "save.h"

#include <iostream>
#include <sstream>
#include <string>
#include "read.h"
#include "terrain.h"
#include <fstream>
#include <windows.h>
#include "robot.h"

robot test_terrainSimpleAmeliore(const std::string& chaine)
{
    std::istringstream ist{chaine};
    fichiers::readSimpleAmeliore r{ist};
    return r.readTerrain();
}

robot test_terrainAmeliore2(const std::string& chaine)
{
    std::istringstream ist{chaine};
    fichiers::readAmeliore2 r{ist};
    return r.readTerrain();
}

void test_tailleFichier(const std::string& chaine, const std::string& chaineBase)
{
    REQUIRE_EQ(chaine.size(),chaineBase.size());
}

void test_caracteresFichier(const std::string& chaine, const std::string& chaineBase)
{
    REQUIRE(chaine==chaineBase);
}

TEST_CASE("La classe save marche correctement")
{
    SUBCASE("Si le labyrinthe est en caractère simple")
    {
        std::string lab{"XXXXXXXXXXXXXXXXXXXX\nX>.....XXXX........X\nX..................X\nX..X...............X\nX..X........X......X\nX..X........X......X\nX⎆.X........X....🔙.X\nXXXXXXXXXXXXXXXXXXXX"};
        robot rob{test_terrainSimpleAmeliore(lab)};
        std::ostringstream ost;
        fichiers::printSimple s{ost,rob};
        s.printTerrain();
        std::string resultatPrint{ost.str()};
        SUBCASE("La taille du fichier est correct")
        {
            test_tailleFichier(resultatPrint,lab);
        }
        SUBCASE("Le fichier possède les bon caractère")
        {
            test_caracteresFichier(resultatPrint,lab);
        }
    }
    SUBCASE("Si le labyrinthe est en caractère ameliore1")
    {
        std::string lab{"+------+##+--------+\n|>.....+--+........|\n|..................|\n|..|...............|\n|..|........|......|\n|..|........|......|\n|⎆.|........|....🔙.|\n+--+--------+------+"};
        robot rob{test_terrainSimpleAmeliore(lab)};
        std::ostringstream ost;
        fichiers::printAmeliore1 s{ost,rob};
        s.printTerrain();
        std::string resultatPrint{ost.str()};
        SUBCASE("La taille du fichier est correct")
        {
            test_tailleFichier(resultatPrint,lab);
        }
        SUBCASE("Le fichier possède les bon caractère")
        {
            test_caracteresFichier(resultatPrint,lab);
        }
    }
    SUBCASE("Si le labyrinthe est en caractere ameliore2")
    {
        std::string lab{"┏━━━━━━┓▄▄┏━━━━━━━━┓\n┃>.....┗━━┛........┃\n┃..................┃\n┃..┃...............┃\n┃..┃........┃......┃\n┃..┃........┃......┃\n┃⎆.┃........┃....🔙.┃\n┗━━┻━━━━━━━━┻━━━━━━┛"};
        robot rob{test_terrainAmeliore2(lab)};
        std::ostringstream ost;
        fichiers::printAmeliore2 s{ost,rob};
        s.printTerrain();
        std::string resultatPrint{ost.str()};
        SUBCASE("La taille du fichier est correct")
        {
            test_tailleFichier(resultatPrint,lab);
        }
        SUBCASE("Le fichier possède les bon caractère")
        {
            test_caracteresFichier(resultatPrint,lab);
        }
    }
}
