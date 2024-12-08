#include "AffichageConsole.h"

void AffichageConsole::afficherGrille(const Grille& grille) {
    for (int x = 0; x < grille.obtenirHauteur(); ++x) {  // Parcours de la grille en hauteur
        for (int y = 0; y < grille.obtenirLargeur(); ++y) {  // Parcours de la grille en largeur
            cout << grille.obtenirCellule(x, y).estEnVie();  // Affichage de l'état de la cellule (1 en vie, 0 morte)
        }
        cout << endl;  // Saut de ligne
    }
    cout << endl;  // Saut de ligne
}

RenderWindow* AffichageConsole::obtenirFenetre() {
    return nullptr;  // Retourne une fenêtre nulle
}