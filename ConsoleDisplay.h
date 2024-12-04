#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <iostream>
#include "Display.h"
#include "Grid.h"

using namespace std;

class ConsoleDisplay final : public Display {
public:
    void renderGrid(const Grid& grid) override {
        for (int x = 0; x < grid.getHeight(); ++x) {
            for (int y = 0; y < grid.getWidth(); ++y) {
                cout << grid.getCell(x, y).isAlive();
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isGraphic() const override {
        return false;
    }
};



#endif //CONSOLEDISPLAY_H
