#ifndef CELL_H
#define CELL_H

#include "SFML/Graphics/RectangleShape.hpp"

using namespace sf;

class Cell {
private:
    bool alive;
    bool fixed;

public:
    Cell();
    int countNeighbors(int x, int y) const;
    void setAlive(bool status);
    bool isAlive() const;
};



#endif //CELL_H
