#include "AffichageGraphique.h"

AffichageGraphique::AffichageGraphique(): window(nullptr) {}

void AffichageGraphique::afficherGrille(const Grille &grid) {
    window->clear();
    RectangleShape shape(Vector2f(cellSize - 1, cellSize - 1));

    for (int x = 0; x < grid.getHeight(); ++x) {
        for (int y = 0; y < grid.getWidth(); ++y) {
            shape.setPosition(y * cellSize, x * cellSize);
            shape.setFillColor(grid.obtenirCellule(x, y).isAlive() ? Color::White : Color::Black);
            window->draw(shape);
        }
    }
    window->display();
}

void AffichageGraphique::setWindow(RenderWindow* window) {
    this->window = window;
}

RenderWindow* AffichageGraphique::getWindow() const {
    return window;
}
