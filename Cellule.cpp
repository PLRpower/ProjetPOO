#include "Cellule.h"
#include "Grille.h"

Cellule::Cellule() : enVie(false), fixe(false), x(0), y(0) {}

void Cellule::initialiser(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void Cellule::definirVivant(const bool status) {
    if(!fixe) {
        enVie = status;
    }
}

bool Cellule::estEnVie() const {
    return enVie;
}

int Cellule::compterVoisins(const Grille* grille) const {
    int compteur = 0;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) {
                continue;
            }

            int x = this->x + i;
            int y = this->y + j;

            if (grille->estTorique()) {
                x = (x + grille->obtenirHauteur()) % grille->obtenirHauteur();
                y = (y + grille->obtenirLargeur()) % grille->obtenirLargeur();
            }

            if (x >= 0 && x < grille->obtenirHauteur() && y >= 0 && y < grille->obtenirLargeur()) {
                compteur += grille->obtenirCellule(x, y).estEnVie();
            }
        }
    }

    return compteur;
}