#include "Cell.h"

#include <iostream>

#include "Grid.h"

Cell::Cell() : alive(false), fixed(false), x(0), y(0) {}

void Cell::initialize(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void Cell::setAlive(const bool status) {
    if(!fixed) {
        alive = status;
    }
}

bool Cell::isAlive() const {
    return alive;
}

int Cell::countNeighbors(const Grid* grid) const {
    int count = 0;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) {
                continue;
            }

            int x = this->x + i;
            int y = this->y + j;

            if (grid->isToric()) {
                x = (x + grid->getHeight()) % grid->getHeight();
                y = (y + grid->getWidth()) % grid->getWidth();
            }

            if (x >= 0 && x < grid->getHeight() && y >= 0 && y < grid->getWidth()) {
                count += grid->getCell(x, y).isAlive();
            }
        }
    }

    return count;
}