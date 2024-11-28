#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

using namespace sf;

class GameOfLife {
private:
    RenderWindow window;
    Grid grid;
    Clock clock;

public:
    GameOfLife();

    void run();

private:
    void handleEvents();
    void update();
    void render();
};



#endif //GAMEOFLIFE_H
