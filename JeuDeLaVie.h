#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H


#include "AffichageConsole.h"
#include "AffichageGraphique.h"
#include "Affichage.h"
#include "Fichier.h"
#include "Grille.h"
#include <filesystem>

constexpr int cellSize = 50;

class JeuDeLaVie {
private:
    int mode;
    Grille grille;
    Affichage *affichage;
    RenderWindow fenetre;
    Fichier fichier;
    int delai = 100;
    int modifVisuel = 0;
    int generation = 0;
    int nbGenMax = 100;
    unordered_set<string> grillePrecedentes;


public:
    JeuDeLaVie() = default;

    void choisirFichier();

    void choisirDelai();

    void choisirNbGenerations();

    void choisirGrille();

    void choisirMode();

    void choisirTorique();

    void start();
};



#endif //JEUDELAVIE_H
