#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

class Cell {
private:
    bool alive;
    RectangleShape shape;

public:
    Cell() : alive(false) {
        shape.setSize(Vector2f(9.0f, 9.0f)); // cellSize - 1
        shape.setFillColor(Color::White);
    }

    void setAlive(const bool status) {
        alive = status;
    }

    bool isAlive() const {
        return alive;
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
    }

    const RectangleShape& getShape() const {
        return shape;
    }
};

class Grid {
private:
    static constexpr int cellSize = 10;
    static constexpr int width = 80;
    static constexpr int height = 80;
    vector<vector<Cell>> cells;

    int countNeighbors(int x, int y) const {
        int count = 0;
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(i == 0 && j == 0) continue;

                int newX = x + i;
                int newY = y + j;
w
                if(newX >= 0 && newX < width && newY >= 0 && newY < height) {
                    if(cells[newX][newY].isAlive()) count++;
                }
            }
        }
        return count;
    }

public:
    Grid() : cells(width, vector<Cell>(height)) {
        initialize();
    }

    void initialize() {
        srand(time(0));
        for(int x = 0; x < width; ++x) {
            for(int y = 0; y < height; ++y) {
                cells[x][y].setAlive(rand() % 2 == 1);
                cells[x][y].setPosition(x * cellSize, y * cellSize);
            }
        }
    }

    void update() {
        vector<vector<bool>> nextState(width, vector<bool>(height));

        for(int x = 0; x < width; ++x) {
            for(int y = 0; y < height; ++y) {
                int neighbors = countNeighbors(x, y);
                bool currentlyAlive = cells[x][y].isAlive();

                if(currentlyAlive) {
                    nextState[x][y] = (neighbors == 2 || neighbors == 3);
                } else {
                    nextState[x][y] = (neighbors == 3);
                }
            }
        }

        // Apply new state
        for(int x = 0; x < width; ++x) {
            for(int y = 0; y < height; ++y) {
                cells[x][y].setAlive(nextState[x][y]);
            }
        }
    }

    void render(RenderWindow& window) const {
        for(int x = 0; x < width; ++x) {
            for(int y = 0; y < height; ++y) {
                if(cells[x][y].isAlive()) {
                    window.draw(cells[x][y].getShape());
                }
            }
        }
    }

    static int getWindowWidth() { return width * cellSize; }
    static int getWindowHeight() { return height * cellSize; }
};

class GameOfLife {
private:
    RenderWindow window;
    Grid grid;
    Clock clock;

public:
    GameOfLife() : window(VideoMode(Grid::getWindowWidth(), Grid::getWindowHeight()), "Jeu de la vie") {
        window.setFramerateLimit(60);
    }

    void run() {
        while(window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

private:
    void handleEvents() {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
        }
    }

    void update() {
        if(clock.getElapsedTime().asMilliseconds() >= 100) {
            grid.update();
            clock.restart();
        }
    }

    void render() {
        window.clear(Color::Black);
        grid.render(window);
        window.display();
    }
};

int main() {
    GameOfLife game;
    game.run();
    return 0;
}