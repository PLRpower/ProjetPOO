#include "AffichageGraphique.h"

AffichageGraphique::AffichageGraphique(const int largeur, const int hauteur) {
    cellSize = 800 / hauteur;  // On adapte la taille des cellules en fonction du nombre de cellules en hauteur
    fenetre.create(VideoMode(largeur * cellSize, hauteur * cellSize), "Jeu de la vie"); // Crée la fenêtre
}

void AffichageGraphique::afficherGrille(const Grille &grille) {
    fenetre.clear();  // Efface la fenêtre
    RectangleShape forme(Vector2f(cellSize - 1, cellSize - 1));  // Crée une forme (cellule)

    for (int x = 0; x < grille.obtenirHauteur(); ++x) {  // Parcours de la grille en hauteur
        for (int y = 0; y < grille.obtenirLargeur(); ++y) {  // Parcours de la grille en largeur
            forme.setPosition(y * cellSize, x * cellSize);  // Définit la position de la forme
            forme.setFillColor(grille.obtenirCellule(x, y).estEnVie() ? Color::White : Color::Black);  // Définit la couleur de la forme en fonction de l'état de la cellule
            fenetre.draw(forme);  // Dessine la forme
        }
    }
    fenetre.display();  // Affiche la fenêtre
}

RenderWindow* AffichageGraphique::obtenirFenetre() {
    return &fenetre;  // Retourne la fenêtre
}