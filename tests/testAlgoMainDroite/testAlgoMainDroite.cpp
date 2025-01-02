#include "../../doctest.h"
#include "../../algoMainDroite.h"
#include "../../terrain.h"
#include "../../robot.h"
#include "../../position.h"
#include "../../direction.h"


TEST_CASE("Le robot parvient à sortir du labyrinthe"){
    SUBCASE("Cas simple labyrinthe de 3x3"){
        std::vector<std::vector<bool>> labyrinthe{{true,true,true},{true,false,true},{true,true,true}};
        position entree{1,0};
        position sortie{1,2};
        terrain t{labyrinthe,entree,sortie};
        robot r{entree,direction::DROITE,t};

        SUBCASE("Test Complémentaire"){
            SUBCASE("Je rentre bien dans la boucle"){
                REQUIRE_NE(r.positionSurTerrain(),t.caseSortie());
            }
            SUBCASE("Le robot avance sur le terrain"){
                position posSuivante = r.calculateNewPosition();
                r.setPosition(posSuivante);
                REQUIRE_EQ(r.positionSurTerrain(),posSuivante);
            }
            SUBCASE("Le robot arrive à sortir"){
                position posSuivante = r.calculateNewPosition();
                r.setPosition(posSuivante);
                posSuivante = r.calculateNewPosition();
                r.setPosition(posSuivante);
                REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
            }
        }

        SUBCASE("Sortie en face de l'entrée de la droite vers la gauche"){
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }

        SUBCASE("Sortie en face de l'entrée de la gauche vers la droite"){
            position entree{1,2};
            position sortie{1,0};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::GAUCHE,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }

        SUBCASE("Sortie en face de l'entrée du haut vers le bas"){
            position entree{2,1};
            position sortie{0,1};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::HAUT,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }

        SUBCASE("Sortie en face de l'entrée du haut vers le bas"){
            position entree{0,1};
            position sortie{2,1};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::BAS,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }

    }
    SUBCASE("L'algo fonctionne sur des cas un peu plus réels"){
        SUBCASE("L'abyrinthe de 3x3 avec la sortie en bas"){
            std::vector<std::vector<bool>> labyrinthe{{true,true,true},{true,false,true},{true,true,true}};
            position entree{1,0};
            position sortie{2,1};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::DROITE,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }
        SUBCASE("L'abyrinthe de 3x3 avec la sortie en haut"){
            std::vector<std::vector<bool>> labyrinthe{{true,true,true},{true,false,true},{true,true,true}};
            position entree{1,0};
            position sortie{0,1};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::DROITE,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }
    }
    SUBCASE("L'algo fonctionne"){
        SUBCASE("L'abyrinthe a deux angles"){
            std::vector<std::vector<bool>> labyrinthe{{true,true,true,true,true},
                                                      {true,false,false,false,true},
                                                      {true,false,true,false,true},
                                                      {true,true,true,true,true}};
            position entree{3,1};
            position sortie{3,3};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::HAUT,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }
        SUBCASE("Mauvaise direction de départ du robot"){
            std::vector<std::vector<bool>> labyrinthe{{true,true,true,true,true},
                                                      {true,false,false,false,true},
                                                      {true,false,true,false,true},
                                                      {true,true,true,true,true}};
            position entree{3,1};
            position sortie{3,3};
            terrain t{labyrinthe,entree,sortie};
            //REQUIRE_EQ(t.sortDuTableau(1,4),true);
            robot r{entree,direction::GAUCHE,t};
            mainDroite mD;
            mD.reDirectionRobot(r,t);
            REQUIRE_EQ(r.directionSurTerrain().valeurDirection(),0);

        }
        SUBCASE("L'abyrinthe a deux angles mais une mauvaise direction de départ"){
            std::vector<std::vector<bool>> labyrinthe{{true,true,true,true,true},
                                                      {true,false,false,false,true},
                                                      {true,false,true,false,true},
                                                      {true,true,true,true,true}};
            position entree{3,1};
            position sortie{3,3};
            terrain t{labyrinthe,entree,sortie};
            robot r{entree,direction::GAUCHE,t};
            mainDroite mD;
            mD.exit(r,t);
            REQUIRE_EQ(r.positionSurTerrain(),t.caseSortie());
        }
    }
}

