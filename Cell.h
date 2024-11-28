#ifndef CELL_H
#define CELL_H
#include "SFML/Graphics/RectangleShape.hpp"

using namespace sf;


class Cell {
private:
    bool alive;
    RectangleShape shape;

public:
    Cell();
    void setAlive(bool status);
    bool isAlive() const;
    void setPosition(float x, float y);
    const RectangleShape& getShape() const;
};



#endif //CELL_H
