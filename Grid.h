#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

class Grid {
private:
    int width, height;
    std::vector<Cell> cells;
    bool toric = true;

public:
    Grid() = default;
    Grid(int width, int height);

    void update();
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setToric(const bool toric) { this->toric = toric; }
    bool isToric() const { return toric; }

    Cell& getCell(int x, int y) { return cells[x * width + y]; }

    const Cell& getCell(int x, int y) const { return cells[x * width + y]; }
};

#endif // GRID_H
