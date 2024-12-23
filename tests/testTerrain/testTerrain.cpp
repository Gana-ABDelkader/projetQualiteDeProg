#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include"../../doctest.h"
#include "../../terrain.h"

TEST_CASE("Les constructeurs marchent bien"){
    SUBCASE("Le constructeur par défaut marche bien"){
        terrain t{};
        REQUIRE_EQ(t.caseEntree(),{1,1});
        REQUIRE_EQ(t.caseSortie(),{1,1});
        REQUIRE_EQ(t.labyrinthe(),{{true,true,true,true,true},{true,false,false,false,true},{true,false,false,false,true},{true,false,false,false,true},{true,true,true,true,true}});
    }

    SUBCASE("Le constructeur avec en paramètre un terrain, une entrée et une sortie marche bien"){
        std::vector<std::vector<bool>> labyrinthe{{true,true,true,true,true},{true,false,false,false,true},{true,false,false,false,true},{true,false,false,false,true},{true,true,true,true,true}};
        position entree{1,3},sortie{2,3};
        terrain t{labyrinthe,entree,sortie};
        REQUIRE_EQ(t.labyrinthe(),labyrinthe);
        REQUIRE_EQ(t.caseEntree(),entree);
        REQUIRE_EQ(t.caseSortie(),sortie);
    }
/*
    SUBCASE("Le constructeur avec ifstream marche bien"){

    }
*/
}

TEST_CASE("Les méthodes du terrain marchent bien"){
    terrain t{};
    SUBCASE("La méthode qui renvoie si c'est un mur marche bien"){
        position pmur{0,0},pvide{1,1};
        REQUIRE(t.estUnMur(pmur));
        REQUIRE_FALSE(t.estUnMur(pvide));
    }

    SUBCASE("La méthode qui change en Mur fonctionne"){
        position pvide{1,1};
        t.changeenMur(pvide);
        REQUIRE(t.estUnMur(pvide));
    }

    SUBCASE("La méthode qui renvoie la taille du labyrinthe marchent"){
        REQUIRE_EQ(t.tailleTableau(),5);
    }
}