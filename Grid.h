#ifndef GRID_H
#define GRID_H
#include "Cell.h"
#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"

using namespace std;
using namespace sf;

class Grid {
private:
    static constexpr int cellSize = 10;
    static constexpr int width = 80;
    static constexpr int height = 80;
    vector<vector<Cell>> cells;

    int countNeighbors(int x, int y) const;

public:
    Grid();

    void initialize();

    void update();

    void render(RenderWindow& window) const;

    static int getWindowWidth() { return width * cellSize; }
    static int getWindowHeight() { return height * cellSize; }
};




#endif //GRID_H
