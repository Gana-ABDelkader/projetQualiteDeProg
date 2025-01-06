#include <fstream>
#include <windows.h>

#include "../../doctest.h"
#include "../../algorithmeSortie.h"
#include "../../robot.h"
#include "../../readVector.h"
#include "../../read.h"
#include "../../save.h"
#include "../../observateur.h"

TEST_CASE("Test des algos de sortie"){
    SetConsoleOutputCP(65001);

    SUBCASE("Test Complémentaire"){
        std::ifstream fIN("testSimple1.txt");
        auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
        robot r = lire->readTerrain();
        r.setDirection(direction::DROITE);
        auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
        terrain t = r.terrainDeLabyrinthe();
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
            REQUIRE_EQ(r.positionSurTerrain().positionLigne(),t.caseSortie().positionLigne());
            REQUIRE_EQ(r.positionSurTerrain().positionColonne(),t.caseSortie().positionColonne());
        }
    }


    SUBCASE("Le robot parvient à sortir du labyrinthe avec l'algorithme mainDroite"){

        SUBCASE("Cas simple labyrinthe de 3x3"){

            SUBCASE("Sortie en face de l'entrée de la droite vers la gauche"){
                std::ifstream fIN("testSimple1.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::DROITE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("Sortie en face de l'entrée de la gauche vers la droite"){
                std::ifstream fIN("testSimple2.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::GAUCHE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("Sortie en face de l'entrée du haut vers le bas"){
                std::ifstream fIN("testSimple3.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::BAS);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("Sortie en face de l'entrée du bas vers le haut"){
                std::ifstream fIN("testSimple4.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::HAUT);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

        }

        SUBCASE("L'algo fonctionne sur des cas un peu plus réels"){

            SUBCASE("L'abyrinthe de 3x3 avec la sortie en bas"){
                std::ifstream fIN("testIntermediaire1.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::DROITE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("L'abyrinthe de 3x3 avec la sortie en haut"){
                std::ifstream fIN("testIntermediaire2.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::DROITE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

        }

        SUBCASE("L'algo fonctionne"){

            SUBCASE("L'abyrinthe a deux angles"){
                std::ifstream fIN("testDifficile.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::HAUT);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("L'abyrinthe a deux angles mais une mauvaise direction de départ"){
                std::ifstream fIN("testDifficile.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::GAUCHE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                mainDroite mD;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                mD.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

        }
    }

    SUBCASE("Le robot parvient à sortir du labyrinthe avec l'algorithme pledge"){

        SUBCASE("L'algo fonctionne sur des cas un peu plus réels"){

            SUBCASE("L'abyrinthe de 3x3 avec la sortie en bas"){
                std::ifstream fIN("testIntermediaire1.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::DROITE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                pledge pLd;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                pLd.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("L'abyrinthe de 3x3 avec la sortie en haut"){
                std::ifstream fIN("testIntermediaire2.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::DROITE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                pledge pLd;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                pLd.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

        }
        SUBCASE("L'algo fonctionne"){

            SUBCASE("L'abyrinthe a deux angles"){
                std::ifstream fIN("testDifficile.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::HAUT);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                pledge pLd;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                pLd.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

            SUBCASE("L'abyrinthe a deux angles mais une mauvaise direction de départ"){
                std::ifstream fIN("testDifficile.txt");
                auto lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
                robot r = lire->readTerrain();
                r.setDirection(direction::GAUCHE);
                auto ecrire{std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r})};
                pledge pLd;
                std::vector<std::unique_ptr<observateur>> obs;
                obs.push_back(std::make_unique<observateurAffichage>());
                pLd.exit(std::move(lire),std::move(ecrire),std::move(obs));
            }

        }


    }
}
