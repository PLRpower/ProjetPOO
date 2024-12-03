#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

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
        RectangleShape shape(Vector2f(cellSize - 1, cellSize - 1));

        for (int x = 0; x < grid.getHeight(); ++x) {
            for (int y = 0; y < grid.getWidth(); ++y) {
                shape.setPosition(y * cellSize, x * cellSize);
                shape.setFillColor(grid.getCell(x, y).isAlive() ? Color::White : Color::Black);
                window.draw(shape);
            }
        }
        window.display();
    }
};

#endif // GRAPHICDISPLAY_H
