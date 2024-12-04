#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Display.h"
#include "Grid.h"

using namespace std;
using namespace sf;

class GraphicDisplay final : public Display {
private:
    const int cellSize = 50;
    RenderWindow& window;

public:
    explicit GraphicDisplay(RenderWindow& window) : window(window) {}

    void renderGrid(const Grid &grid) override {
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

    bool isGraphic() const override {
        return true;
    }

    RenderWindow& getWindow() const {
        return window;
    }

    bool isRunning() const {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return false;
            }
        }
        return window.isOpen();
    }

};

#endif // GRAPHICDISPLAY_H
