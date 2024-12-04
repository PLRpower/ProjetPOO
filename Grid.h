#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

class Grid {
private:
    int width, height;
    std::vector<Cell> cells;
    bool toric;

public:
    Grid() = default;
    Grid(int width, int height);

    void update();
    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool isToric() const { return toric; }

    void setToric(const bool toric) { this->toric = toric; }
};

#endif // GRID_H
