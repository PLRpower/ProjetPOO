#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "AffichageGraphique.h"
#include "Affichage.h"
#include "Fichier.h"
#include "Grille.h"
#include <unordered_set>

class JeuDeLaVie {
private:
    int methodeGeneration; // Méthode de génération
    int modeAffichage;  // Mode de jeu
    Grille grille;  // Grille de jeu
    Affichage *affichage;  // Affichage
    Fichier fichier;  // Fichier
    int delai;  // Délai entre chaque génération
    int generation;  // Génération actuelle
    int nbGenMax;  // Nombre de générations maximum
    unordered_set<string> grillePrecedentes;  // Grilles précédentes
    bool verifierFermetureFenetre() const;  // Vérifie la fermeture de la fenêtre


public:
    JeuDeLaVie();  // Constructeur par défaut
    ~JeuDeLaVie();  // Destructeur
    void chosisirMethodeGeneration();  // Choix de la méthode de génération
    void choisirFichier();  // Choix du fichier
    void choisirDelai();  // Choix du délai
    void choisirNbGenerations();  // Choix du nombre de générations
    void choisirModeAffichage();  // Choix du mode de jeu
    void choisirTorique();  // Choix de la grille torique
    void start();  // Démarre le jeu
    bool testUnitaire();  // Test unitaire
};



#endif //JEUDELAVIE_H
