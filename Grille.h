#ifndef GRID_H
#define GRID_H

#include "Cellule.h"
#include <vector>
#include <string>

using namespace std;

class Grille {
private:
    int largeur, hauteur;
    vector<Cellule> cellules;
    bool torique;

public:
    Grille() = default;  // Constructeur par défaut
    Grille(int largeur, int hauteur);  // Constructeur
    void genererAleatoire();  // Génère une grille aléatoire
    void actualiser();  // Actualise la grille
    string grilleEnTexte();  // Retourne la grille en texte
    Cellule& obtenirCellule(int x, int y);  // Retourne une cellule modifiable
    const Cellule& obtenirCellule(int x, int y) const;  // Retourne une cellule constante (non-modifiable)
    int obtenirLargeur() const { return largeur; }  // Retourne la largeur
    int obtenirHauteur() const { return hauteur; }  // Retourne la hauteur
    bool estTorique() const { return torique; }  // Retourne si la grille est torique
    void definirTorique(const bool toric) { this->torique = toric; }  // Définit si la grille est torique
};

#endif // GRID_H
