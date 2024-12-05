#include "Cellule.h"

#include <iostream>

#include "Grille.h"

Cellule::Cellule() : alive(false), fixed(false), x(0), y(0) {}

void Cellule::initialize(const int x, const int y) {
    this->x = x;
    this->y = y;
}

void Cellule::setAlive(const bool status) {
    if(!fixed) {
        alive = status;
    }
}

bool Cellule::isAlive() const {
    return alive;
}

int Cellule::countNeighbors(const Grille* grid) const {
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
                count += grid->obtenirCellule(x, y).isAlive();
            }
        }
    }

    return count;
}