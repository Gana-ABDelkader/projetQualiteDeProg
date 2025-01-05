#include <fstream>
#include <memory>

#include "lancementProgramme.h"
#include "robot.h"


using std::cout;
using std::endl;
using std::cin;

programme::programme():
    d_lire{nullptr}, d_ecrire{nullptr}, d_observateur{nullptr}
{}

void programme::execute(){
    bool goOn = true;
    while (goOn)
    {
        int choice {menu()};
        switch(choice)
        {
          case 1 : choixAffichageTerrain(); break;
          case 2 : choixObservateur(); break;
          case 3 : choixAlgoSortie(); break;
          default: goOn = false;
        }
    }
}

int programme::menu()
{
    int choice;
    do
    {
        cout<<"Deplacement d'un robot dans un labyrinthe"<<'\n'<<'\n';
        cout<<"(1) Choix de l'affichage du terrain"<<'\n';
        cout<<"(2) Choix de l'observateur"<<'\n';
        cout<<"(3) Choix de l'algorithme de sortie"<<'\n';
        cout<<"(4) quitter le menu"<<endl;
        cout<<endl<<"votre choix : ";
        cin>>choice;
        cout<<endl;
    }
    while (choice<1 || choice>4);
    return choice;
}

int programme::menuAffichageTerrain(){
    int choice;
    do
    {
        cout<<"Choix de l'affichage du terrain"<<'\n'<<'\n';
        cout<<"(1) Afffichage Simple"<<'\n';
        cout<<"(2) Affichage Amélioré 1"<<'\n';
        cout<<"(3) Affichage Amélioré 2"<<'\n';
        cout<<"(4) quitter le menu"<<endl;
        cout<<endl<<"votre choix : ";
        cin>>choice;
        cout<<endl;
    }
    while (choice<1 || choice>4);
    return choice;
}

void programme::choixAffichageTerrain(){
    d_choixTerrain=0;
    bool goOn = true;
    while (goOn)
    {
        int choice {menuAffichageTerrain()};
        switch(choice)
        {
            case 1 : d_choixTerrain=1; break;
            case 2 : d_choixTerrain=2; break;
            case 3 : d_choixTerrain=3; break;
            default: goOn = false;
        }
    }
}

void programme::labyrintheSimple(){
    std::ifstream fIN("TerrainSimple.txt");
    d_lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
    robot r = d_lire->readTerrain();
    d_ecrire = std::make_unique<fichiers::printSimple>(fichiers::printSimple{std::cout,r});
}


void programme::labyrintheAmeliore1(){
    std::ifstream fIN("TerrainAmeliore1.txt");
    d_lire = std::make_unique<fichiers::readSimpleAmeliore>(fichiers::readSimpleAmeliore{fIN});
    robot r = d_lire->readTerrain();
    d_ecrire = std::make_unique<fichiers::printAmeliore1>(fichiers::printAmeliore1{std::cout,r});
}

void programme::labyrintheAmeliore2(){
    std::ifstream fIN("TerrainAmeliore2.txt");
    d_lire = std::make_unique<fichiers::readAmeliore2>(fichiers::readAmeliore2{fIN});
    robot r = d_lire->readTerrain();
    d_ecrire = std::make_unique<fichiers::printAmeliore2>(fichiers::printAmeliore2{std::cout,r});

}

int programme::menuChoixObservateur(){
    int choice;
    do
    {
        cout<<"Choix de l'observateur"<<'\n'<<'\n';
        cout<<"(1) Observateur Affichage"<<'\n';
        cout<<"(2) Observateur Compteur d'Avancement"<<'\n';
        cout<<"(3) Observateur Compteur de Rotation"<<'\n';
        cout<<"(4) quitter le menu"<<endl;
        cout<<endl<<"votre choix : ";
        cin>>choice;
        cout<<endl;
    }
    while (choice<1 || choice>4);
    return choice;
}

/*void observateurAffichage()
{
    d_robot.ajouterObservateur(std::make_unique<observateurAffichage>());
}
void observateurCompteurAvancement()
{
    d_robot.ajouterObservateur(std::make_unique<observateurCompteurAvancement>());
}
void observateurCompteurRotation()
{
    d_robot.ajouterObservateur(std::make_unique<observateurCompteurRotation>());
}*/

void programme::choixObservateur()
{
    bool goOn = true;
    while (goOn)
    {
        int choice {menuChoixObservateur()};
        switch(choice)
        {
            case 1 : observateurAffichage(); break;
            case 2 : observateurCompteurAvancement(); break;
            case 3 : observateurCompteurRotation(); break;
            default: goOn = false;
        }
    }
}

int programme::menuAlgoSortie(){
    int choice;
    do
    {
        cout<<"Choix de l'algorithme de sortie"<<'\n'<<'\n';
        cout<<"(1) Algorithme Main Droite"<<'\n';
        cout<<"(2) Algorithme de Pledge"<<'\n';
        cout<<"(3) quitter le menu"<<endl;
        cout<<endl<<"votre choix : ";
        cin>>choice;
        cout<<endl;
    }
    while (choice<1 || choice>3);
    return choice;
}


void programme::choixAlgoSortie(){
    bool goOn = true;
    while (goOn)
    {
        int choice {menuAlgoSortie()};
        switch(choice)
        {
            case 1 : algorithmeMainDroite(); break;
            case 2 : algorithmePledge(); break;
            default: goOn = false;
        }
    }
}

void programme::traitement(){
    //Apres plusieurs tests je suis oblige de faire un switch
    //On dirait que le traitement des variables et l'algo
    //doivent se faire à la suite.
    //Je voulais d'abord mettre les switch case du traitement dans le switch case
    //de choixAffichageTerrain mais cela ne marche ensuite pas pour l'exit...
    switch(d_choixTerrain)
    {
        case 0 : d_lire=nullptr; d_ecrire= nullptr; break;
        case 1 : labyrintheSimple(); break;
        case 2 : labyrintheAmeliore1(); break;
        case 3 : labyrintheAmeliore2(); break;
    }
}

void programme::algorithmeMainDroite(){
    traitement();
    if(d_lire == nullptr || d_ecrire == nullptr){// && d_observateur == nullptr){
        cout<<"Veuillez choisir le terrain et l'observateur avant l'algorithme"<<endl;
    }
    else{
        d_algoSortie.algorithmeMainDroite(std::move(d_lire),std::move(d_ecrire));
    }
}

//A FAIRE
void programme::algorithmePledge(){

}
