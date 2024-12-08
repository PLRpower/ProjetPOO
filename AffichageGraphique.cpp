#include "AffichageGraphique.h"

AffichageGraphique::AffichageGraphique(const int largeur, const int hauteur) {
    cellSize = 800 / hauteur;
    fenetre.create(VideoMode(largeur * cellSize, hauteur * cellSize), "Jeu de la vie"); // Crée la fenêtre
}

void AffichageGraphique::afficherGrille(const Grille &grille) {
    fenetre.clear();
    RectangleShape forme(Vector2f(cellSize - 1, cellSize - 1));

    for (int x = 0; x < grille.obtenirHauteur(); ++x) {
        for (int y = 0; y < grille.obtenirLargeur(); ++y) {
            forme.setPosition(y * cellSize, x * cellSize);
            forme.setFillColor(grille.obtenirCellule(x, y).estEnVie() ? Color::White : Color::Black);
            fenetre.draw(forme);
        }
    }
    fenetre.display();
}

RenderWindow* AffichageGraphique::obtenirFenetre() {
    return &fenetre;
}