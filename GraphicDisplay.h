#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Display.h"
#include "Grille.h"

using namespace std;
using namespace sf;

class GraphicDisplay final : public Display {
private:
    const int cellSize = 50;
    RenderWindow* window;

public:
    explicit GraphicDisplay(): window(nullptr) {}

    void afficherGrille(const Grille &grid) override {
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

    void setWindow(RenderWindow* window) {this->window = window;}
    RenderWindow* getWindow() const {return window;}

};

#endif // GRAPHICDISPLAY_H
