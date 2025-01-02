#include"../../doctest.h"
#include"../../manipulate.h"
#include"../../robot.h"
#include <sstream>
#include<string>


TEST_CASE("Les classes filles de manipulate fonctionnent"){
    terrain t{};
    std::string laby{"xxxxx\nx⎆..x\nx🔙..x\nx...x\nxxxxx"};
    std::istringstream ist{laby};
    fichiers::readSimpleAmeliore rea(ist);
    t=t.litUnTerrain(rea);
    direction d;

    robot r{t.caseEntree(),d,t};

    SUBCASE("Le move forward fonctionne"){
        robotForward mf{};

        SUBCASE("Le robot a la direction HAUT"){
            r.setDirection(direction::HAUT);
            mf.move(r);
            REQUIRE_EQ(r.positionSurTerrain(),position{1,1});
        }

        SUBCASE("Le robot a la direction DROITE"){
            r.setDirection(direction::DROITE);
            mf.move(r);
            REQUIRE_EQ(r.positionSurTerrain(),position{1,2});
        }

        SUBCASE("Le robot a la direction BAS"){
            r.setDirection(direction::BAS);
            mf.move(r);
            REQUIRE_EQ(r.positionSurTerrain(),position{2,1});
        }

        SUBCASE("Le robot a la direction GAUCHE"){
            r.setDirection(direction::GAUCHE);
            mf.move(r);
            REQUIRE_EQ(r.positionSurTerrain(),position{1,1});
        }

    }

    SUBCASE("Le turn Left fonctionne"){
        robotLeft ml{};

        SUBCASE("Le robot a la direction HAUT"){
            r.setDirection(direction::HAUT);
            ml.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::GAUCHE};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }

        SUBCASE("Le robot a la direction DROITE"){
            r.setDirection(direction::DROITE);
            ml.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::HAUT};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }

        SUBCASE("Le robot a la direction BAS"){
            r.setDirection(direction::BAS);
            ml.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::DROITE};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }

        SUBCASE("Le robot a la direction GAUCHE"){
            r.setDirection(direction::GAUCHE);
            ml.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::BAS};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }
    }

    SUBCASE("Le turn Right fonctionne"){
        robotRight rb{};

        SUBCASE("Le robot a la direction HAUT"){
            r.setDirection(direction::HAUT);
            rb.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::DROITE};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }

        SUBCASE("Le robot a la direction DROITE"){
            r.setDirection(direction::DROITE);
            rb.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::BAS};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }

        SUBCASE("Le robot a la direction BAS"){
            r.setDirection(direction::BAS);
            rb.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::GAUCHE};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }

        SUBCASE("Le robot a la direction GAUCHE"){
            r.setDirection(direction::GAUCHE);
            rb.move(r);
            direction d=r.directionSurTerrain();
            direction dg{direction::HAUT};
            REQUIRE_EQ(d.valeurDirection(),dg.valeurDirection());
        }
    }
}
