#ifndef GRID_H
#define GRID_H

#include "Cellule.h"
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Grille {
private:
    int width, height;
    vector<Cellule> cellules;
    bool toric;

public:
    Grille() = default;
    Grille(int largeur, int hauteur);
    void definirTaille(int largeur, int hauteur);
    void actualiser();
    string grilleEnTexte();
    Cellule& obtenirCellule(int x, int y);
    const Cellule& obtenirCellule(int x, int y) const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool isToric() const { return toric; }
    void setToric(const bool toric) { this->toric = toric; }
};

#endif // GRID_H
