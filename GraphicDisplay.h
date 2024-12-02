#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include "Grid.h"

using namespace std;
using namespace sf;

class GraphicDisplay {
private:
    const int cellSize = 50;

public:
    GraphicDisplay() {}

    void renderGrid(RenderWindow &window, const Grid &grid) const {
        window.clear();
        RectangleShape cell(Vector2f(cellSize - 1, cellSize - 1));

        // Rendu de la grille
        for (int x = 0; x < grid.getWidth(); ++x) {
            for (int y = 0; y < grid.getHeight(); ++y) {
                if (grid.isAlive(x, y)) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    window.draw(cell);
                }
            }
        }
        window.display();
    }
};

#endif // GRAPHICDISPLAY_H
