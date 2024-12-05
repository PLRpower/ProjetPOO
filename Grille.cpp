#include "Grille.h"
#include <string>
#include <vector>

using namespace std;

Grille::Grille(const int largeur, const int hauteur) : largeur(largeur), hauteur(hauteur) {
    cellules = vector<Cellule>(largeur * hauteur);
    for (int x = 0; x < hauteur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            obtenirCellule(x, y).initialiser(x, y);
        }
    }
}

void Grille::definirTaille(const int largeur, const int hauteur) {
    cellules = vector<Cellule>(largeur * hauteur);
    for (int x = 0; x < hauteur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            obtenirCellule(x, y).initialiser(x, y);
        }
    }
}


void Grille::actualiser() {
    for (Cellule& cellule : cellules) {
        const int neighbors = cellule.compterVoisins(this);
        if (cellule.estEnVie()) {
            cellule.mettreEtatSuivant(neighbors == 2 || neighbors == 3);
        } else {
            cellule.mettreEtatSuivant(neighbors == 3);
        }
    }

    for(Cellule& cellule : cellules) {
        cellule.definirVivant(cellule.obtenirEtatSuivant());
    }
}

string Grille::grilleEnTexte() {
    string resultat;
    for (Cellule& cellule : cellules) {
        resultat += cellule.estEnVie() ? "1" : "0";
    }
    return resultat;
}

Cellule& Grille::obtenirCellule(const int x, const int y) {
    return cellules[x * largeur + y];
}

const Cellule& Grille::obtenirCellule(const int x, const int y) const {
    return cellules[x * largeur + y];
}
