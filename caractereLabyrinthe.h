#ifndef CARACTERELABYRINTHE_H
#define CARACTERELABYRINTHE_H

#include <vector>
#include <string>
#include <iostream>


namespace fichiers
{

class caractereLabyrinthe
{
    public:
        caractereLabyrinthe(int nbLigne, int nbColonne);
        virtual ~caractereLabyrinthe() =default;
        void corrigerCaracteresDepandantDesAutres();
        std::string& operator()(int ligne, int colonne);
        const std::string& operator()(int ligne, int colonne) const;
        int nbLigne() const;
        int nbColonne() const;

    protected:
        std::vector<std::vector<std::string>> d_labyr;
    private:
        virtual void placerLesMursPleinsDansLeBordDuTableau() =0;
        virtual void placerCorrigerLesCaractereQuiDependaientDesAutresDansToutLeTableau() =0;
        virtual void placerMurPleinExterieurs(int ligne, int colonne) =0;

};

class caractereLabyrintheAmeliore1 : public caractereLabyrinthe
{
public:
    caractereLabyrintheAmeliore1(int nbLigne, int nbColonne);
private:
    void placerLesMursPleinsDansLeBordDuTableau() override;
    void placerCorrigerLesCaractereQuiDependaientDesAutresDansToutLeTableau() override;
    bool estUnHashtagHautOuBasDuTableau(int ligne, int colonne) const;
    bool estUnHashtagDroiteOuGaucheDuTableau(int ligne, int colonne) const;
    void placerMurPleinInterieur(int ligne, int colonne);
    void placerMurPleinExterieurs(int ligne, int colonne) override;

};

class caractereLabyrintheAmeliore2 : public caractereLabyrinthe
{
public:
    caractereLabyrintheAmeliore2(int nbLigne, int nbColonne);
private:
    void placerLesMursPleinsDansLeBordDuTableau() override;
    void placerCorrigerLesCaractereQuiDependaientDesAutresDansToutLeTableau() override;
    bool estMurPleinHautEtBas(int ligne, int colonne) const;
    bool estMurPleinDroiteEtGauche(int ligne, int colonne) const;
    void placeEncadrementDesMursPleins(int ligne, int colonne);
    void placerMurPleinEtMurDroitInterieur(int ligne, int colonne);
    void placerMurPleinExterieurs(int ligne, int colonne) override;

    static constexpr unsigned char premierOctetCaractereCroisementMur{0xE2};
    static constexpr unsigned char deuxiemeOctetCaractereCroisementMur{0x94};
    static constexpr unsigned char deuxiemeeOctetCaractereMurPlein{0x96};
    static constexpr unsigned char troisiemeOctetCaractereCroisementMurBas{0xB3};
    static constexpr unsigned char troisiemeOctetCaractereCroisementMurHaut{0xBB};
    static constexpr unsigned char troisiemeOctetCaractereCroisementMurDroite{0xA3};
    static constexpr unsigned char troisiemeOctetCaractereCroisementMurGauche{0xAB};


};

}

#endif // CARACTERELABYRINTHE_H
