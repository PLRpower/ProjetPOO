#include "Cell.h"
#include "SFML/Graphics/RectangleShape.hpp"

using namespace sf;

Cell::Cell() : alive(false) {
    shape.setSize(Vector2f(9.0f, 9.0f));
    shape.setFillColor(Color::White);
}

void Cell::setAlive(const bool status) {
    alive = status;
}

bool Cell::isAlive() const {
    return alive;
}

void Cell::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

const RectangleShape& Cell::getShape() const {
    return shape;
}