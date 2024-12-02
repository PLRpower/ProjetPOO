#include "Cell.h"

Cell::Cell() : alive(false), fixed(false) {}

void Cell::setAlive(const bool status) {
    if(!fixed) {
        alive = status;
    }
}

bool Cell::isAlive() const {
    return alive;
}