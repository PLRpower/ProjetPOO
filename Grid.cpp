#include "Grid.h"

#include <iostream>
#include <vector>

Grid::Grid(const int width, const int height) : width(width), height(height) {
    cells = std::vector<Cell>(width * height);
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            getCell(x, y).initialize(x, y);
        }
    }
}

void Grid::update() {
    for (Cell& cell : cells) {
        const int neighbors = cell.countNeighbors(this);
        if (cell.isAlive()) {
            cell.setNextState(neighbors == 2 || neighbors == 3);
        } else {
            cell.setNextState(neighbors == 3);
        }
    }

    for(auto& cell : cells) {
        cell.setAlive(cell.getNextState());
    }
}
