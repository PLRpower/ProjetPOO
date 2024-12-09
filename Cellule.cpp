#include "Cellule.h"
#include "Grille.h"

Cellule::Cellule() : enVie(false), etatSuivant(false), fixe(false), x(0), y(0) {}  // Constructeur par défaut

void Cellule::initialiser(const int x, const int y) {  // Initialise la cellule
    this->x = x;  // Définit la position x
    this->y = y;  // Définit la position y
}

void Cellule::definirVivant(const bool status) {
    if(!fixe) {  // Si la cellule n'est pas fixe (obstacle)
        enVie = status;  // Définit le statut de la cellule
    }
}

bool Cellule::estEnVie() const {
    return enVie;  // Retourne le statut de la cellule
}

int Cellule::compterVoisins(const Grille* grille) const {
    int compteur = 0;  // Initialise le compteur à 0
    for(int i = -1; i <= 1; ++i) {  // Parcourir les voisins horizontaux
        for(int j = -1; j <= 1; ++j) {  // Parcourir les voisins verticaux
            if(i == 0 && j == 0) {  // Si la cellule est la cellule actuelle (0, 0)
                continue;  // Passe à la prochaine itération
            }

            int x = this->x + i;  // Définit la position x
            int y = this->y + j;  // Définit la position y

            if (grille->estTorique()) {  // Si la grille est torique
                x = (x + grille->obtenirHauteur()) % grille->obtenirHauteur();  // x = (x + hauteur) % hauteur
                y = (y + grille->obtenirLargeur()) % grille->obtenirLargeur();  // y = (y + largeur) % largeur
            }

            if (x >= 0 && x < grille->obtenirHauteur() && y >= 0 && y < grille->obtenirLargeur()) {  // Si la cellule est dans la grille
                compteur += grille->obtenirCellule(x, y).estEnVie();  // Incrémente le compteur (pour le nombre de voisins vivants)
            }
        }
    }
    return compteur;  // Retourne le nombre de voisins vivants
}