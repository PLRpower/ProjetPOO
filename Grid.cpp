#include "Grid.h"

int Grid::countNeighbors(int x, int y) const {
    int count = 0;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) continue;

            const int newX = x + i;
            const int newY = y + j;

            if(newX >= 0 && newX < width && newY >= 0 && newY < height) {
                if(cells[newX][newY].isAlive()) count++;
            }
        }
    }
    return count;
}

Grid::Grid() : cells(width, vector<Cell>(height)) {
    initialize();
}

void Grid::initialize() {
    srand(time(0));
    for(int x = 0; x < width; ++x) {
        for(int y = 0; y < height; ++y) {
            cells[x][y].setAlive(rand() % 2 == 1);
            cells[x][y].setPosition(x * cellSize, y * cellSize);
        }
    }
}

void Grid::update() {
    vector nextState(width, vector<bool>(height));

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

void Grid::render(RenderWindow& window) const {
    for(int x = 0; x < width; ++x) {
        for(int y = 0; y < height; ++y) {
            if(cells[x][y].isAlive()) {
                window.draw(cells[x][y].getShape());
            }
        }
    }
}

