#include "AffichageConsole.h"

void AffichageConsole::afficherGrille(const Grille& grille) {
    for (int x = 0; x < grille.obtenirHauteur(); ++x) {
        for (int y = 0; y < grille.obtenirLargeur(); ++y) {
            cout << grille.obtenirCellule(x, y).estEnVie();
        }
        cout << endl;
    }
    cout << endl;
}