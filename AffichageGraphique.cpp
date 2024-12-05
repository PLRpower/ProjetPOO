#include "AffichageGraphique.h"

AffichageGraphique::AffichageGraphique(): fenetre(nullptr) {}

void AffichageGraphique::afficherGrille(const Grille &grille) {
    fenetre->clear();
    RectangleShape forme(Vector2f(cellSize - 1, cellSize - 1));

    for (int x = 0; x < grille.obtenirHauteur(); ++x) {
        for (int y = 0; y < grille.obtenirLargeur(); ++y) {
            forme.setPosition(y * cellSize, x * cellSize);
            forme.setFillColor(grille.obtenirCellule(x, y).estEnVie() ? Color::White : Color::Black);
            fenetre->draw(forme);
        }
    }
    fenetre->display();
}

void AffichageGraphique::definirFenetre(RenderWindow* fenetre) {
    this->fenetre = fenetre;
}

RenderWindow* AffichageGraphique::obtenirFenetre() const {
    return fenetre;
}
