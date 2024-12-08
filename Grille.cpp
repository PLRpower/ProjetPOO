#include "Grille.h"
#include <string>
#include <vector>

using namespace std;

Grille::Grille(const int largeur, const int hauteur) : largeur(largeur), hauteur(hauteur) {
    cellules = vector<Cellule>(largeur * hauteur);  // Crée un vecteur de cellules
    for (int x = 0; x < hauteur; ++x) {  // Parcourir les lignes
        for (int y = 0; y < largeur; ++y) {  // Parcourir les colonnes
            obtenirCellule(x, y).initialiser(x, y);  // Initialise la cellule
        }
    }
}

void Grille::actualiser() {
    // Parallelisation
    #pragma omp parallel for  // Parallélisation de la boucle, uniquement fonctionnel si les itérations sont indépendantes
    for (Cellule& cellule : cellules) {  // Parcourir les cellules
        const int neighbors = cellule.compterVoisins(this);  // Compte le nombre de voisins vivants
        if (cellule.estEnVie()) {  // Si la cellule est vivante
            cellule.mettreEtatSuivant(neighbors == 2 || neighbors == 3);  // Mettre vivant si 2 ou 3 voisins
        } else {  // Sinon
            cellule.mettreEtatSuivant(neighbors == 3);  // Mettre vivant si 3 voisins
        }
    }

    for(Cellule& cellule : cellules) {  // Parcourir les cellules
        cellule.definirVivant(cellule.obtenirEtatSuivant());  // Définit le statut de la cellule
    }
}

void Grille::genererAleatoire() {
    for (Cellule& cellule : cellules) {  // Parcourir les cellules
        cellule.definirVivant(rand() % 2 == 1);  // Définit le statut de la cellule
    }
}

string Grille::grilleEnTexte() {
    string resultat;  // String pour le résultat
    for (Cellule& cellule : cellules) {  // Parcourir les cellules
        resultat += cellule.estEnVie() ? "1" : "0";  // Ajoute 1 si la cellule est vivante, 0 sinon
    }
    return resultat;  // Retourne le résultat
}

Cellule& Grille::obtenirCellule(const int x, const int y) {
    return cellules[x * largeur + y];  // Retourne la cellule, à partir de la position x et y
}

const Cellule& Grille::obtenirCellule(const int x, const int y) const {
    return cellules[x * largeur + y];  // Retourne la cellule, à partir de la position x et y
}
