#include "Grid.h"

#include <ctime>

Grid::Grid(const int width, const int height) : width(width), height(height), cells(width, vector<Cell>(height)) {
    srand(time(0));
    for(int x = 0; x < width; ++x) {
        for(int y = 0; y < height; ++y) {
            cells[x][y].setAlive(rand() % 2 == 1);
        }
    }
}

int Grid::countNeighbors(const int x, const int y) const {
    int count = 0;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) {
                continue;  // Ignorer la cellule actuelle (centre)
            }

            int xNeighbor = x + i;
            int yNeighbor = y + j;

            if(isToric) {
                xNeighbor = (xNeighbor + width) % width;
                yNeighbor = (yNeighbor + height) % height;
            }

            if(xNeighbor >= 0 && xNeighbor < width && yNeighbor >= 0 && yNeighbor < height) {
                count += cells[xNeighbor][yNeighbor].isAlive();
            }
        }
    }

    return count;
}

void Grid::update() {
    vector nextState(width, vector<bool>(height));
    #pragma omp parallel for collapse(2)
    for(int x = 0; x < width; ++x) {
        for(int y = 0; y < height; ++y) {
            const int neighbors = countNeighbors(x, y);
            const bool currentlyAlive = cells[x][y].isAlive();

            if(currentlyAlive) {
                nextState[x][y] = (neighbors == 2 || neighbors == 3);
            } else {
                nextState[x][y] = (neighbors == 3);
            }
        }
    }

    for(int x = 0; x < width; ++x) {
        for(int y = 0; y < height; ++y) {
            cells[x][y].setAlive(nextState[x][y]);
        }
    }
}

bool Grid::isAlive(const int x, const int y) const {
    return cells[x][y].isAlive();
}

void Grid::setAlive(const int x, const int y, const bool alive) {
    cells[x][y].setAlive(alive);
}