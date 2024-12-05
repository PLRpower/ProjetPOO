#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <iostream>
#include "Display.h"
#include "Grille.h"

using namespace std;

class ConsoleDisplay final : public Display {
public:
    void afficherGrille(const Grille& grid) override {
        for (int x = 0; x < grid.getHeight(); ++x) {
            for (int y = 0; y < grid.getWidth(); ++y) {
                cout << grid.obtenirCellule(x, y).isAlive();
            }
            cout << endl;
        }
        cout << endl;
    }
};



#endif //CONSOLEDISPLAY_H
