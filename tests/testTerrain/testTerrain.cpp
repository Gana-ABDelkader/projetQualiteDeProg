#include"../../doctest.h"
#include "../../terrain.h"
#include <sstream>
#include<string>

TEST_CASE("Les constructeurs marchent bien"){
    SUBCASE("Le constructeur par défaut marche bien"){
        terrain t{};

        REQUIRE_EQ(t.caseEntree(),position{-1,-1});
        REQUIRE_EQ(t.caseSortie(),position{-1,-1});
        REQUIRE_EQ(t.labyrinthe(),std::vector<std::vector<bool>>{});
    }
    SUBCASE("Le constructeur avec en paramètre un terrain, une entrée et une sortie marche bien"){
        std::vector<std::vector<bool>> labyrinthe{{true,true,true,true,true},{true,false,false,false,true},{true,false,false,false,true},{true,false,false,false,true},{true,true,true,true,true}};
        position entree{1,3},sortie{2,3};
        terrain t{labyrinthe,entree,sortie};
        REQUIRE_EQ(t.labyrinthe(),labyrinthe);
        REQUIRE_EQ(t.caseEntree(),entree);
        REQUIRE_EQ(t.caseSortie(),sortie);
    }
}

TEST_CASE("Les méthodes du terrain marchent bien"){
    terrain t{};
    std::string laby{"xxxxx\nx⎆..x\nx🔙..x\nx...x\nxxxxx"};
    std::istringstream ist{laby};
    fichiers::readSimpleAmeliore r(ist);
    t=t.litUnTerrain(r);

    SUBCASE("La méthode qui lit un terrain fonctionne"){
        std::vector<std::vector<bool>> labyrinthe{{true,true,true,true,true},{true,false,false,false,true},{true,false,false,false,true},{true,false,false,false,true},{true,true,true,true,true}};
        REQUIRE_EQ(t.caseEntree(),position{1,1});
        REQUIRE_EQ(t.caseSortie(),position{2,1});
        REQUIRE_EQ(t.labyrinthe(),labyrinthe);
    }

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