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
    Grille() = default;
    Grille(int largeur, int hauteur);
    void definirTaille(int largeur, int hauteur);
    void actualiser();
    string grilleEnTexte();
    Cellule& obtenirCellule(int x, int y);
    const Cellule& obtenirCellule(int x, int y) const;
    int obtenirLargeur() const { return largeur; }
    int obtenirHauteur() const { return hauteur; }
    bool estTorique() const { return torique; }
    void definirTorique(const bool toric) { this->torique = toric; }
};

#endif // GRID_H
