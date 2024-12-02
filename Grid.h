#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

using namespace std;

class Grid {
private:
    int width;
    int height;
    vector<vector<Cell>> cells;
    bool isToric = true;
    int countNeighbors(int x, int y) const;

public:
    Grid(int width, int height);

    void update();
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool isAlive(int x, int y) const;
    void setAlive(int x, int y, bool alive);
};



#endif //GRID_H
