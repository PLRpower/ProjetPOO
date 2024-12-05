#include "AffichageConsole.h"

void AffichageConsole::afficherGrille(const Grille& grid) {
    for (int x = 0; x < grid.getHeight(); ++x) {
        for (int y = 0; y < grid.getWidth(); ++y) {
            cout << grid.obtenirCellule(x, y).isAlive();
        }
        cout << endl;
    }
    cout << endl;
}