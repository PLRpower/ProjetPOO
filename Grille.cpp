#include "Grille.h"

#include <string>
#include <vector>

using namespace std;

Grille::Grille(const int largeur, const int hauteur) : width(largeur), height(hauteur) {
    cellules = std::vector<Cellule>(largeur * hauteur);
    for (int x = 0; x < hauteur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            obtenirCellule(x, y).initialize(x, y);
        }
    }
}

void Grille::definirTaille(const int largeur, const int hauteur) {
    cellules = std::vector<Cellule>(largeur * hauteur);
    for (int x = 0; x < hauteur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            obtenirCellule(x, y).initialize(x, y);
        }
    }
}


void Grille::actualiser() {
    for (Cellule& cellule : cellules) {
        const int neighbors = cellule.countNeighbors(this);
        if (cellule.isAlive()) {
            cellule.setNextState(neighbors == 2 || neighbors == 3);
        } else {
            cellule.setNextState(neighbors == 3);
        }
    }

    for(Cellule& cellule : cellules) {
        cellule.setAlive(cellule.getNextState());
    }
}

string Grille::grilleEnTexte() {
    string result;
    for (Cellule& cellule : cellules) {
        result += cellule.isAlive() ? "1" : "0";
    }
    return result;
}

Cellule& Grille::obtenirCellule(const int x, const int y) {
    return cellules[x * width + y];
}

const Cellule& Grille::obtenirCellule(const int x, const int y) const {
    return cellules[x * width + y];
}
