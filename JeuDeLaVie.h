#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include <iostream>

#include "ConsoleDisplay.h"
#include "Display.h"
#include "File.h"
#include "GraphicDisplay.h"
#include "Grid.h"
#include "SFML/System/Sleep.hpp"
#include "SFML/Window/Event.hpp"

class GraphicDisplay;
using namespace sf;

constexpr int cellSize = 50;

class JeuDeLaVie {
private:
    int mode;
    Grid grid;
    Display *display;
    RenderWindow window;
    int delai = 100;  // En ms
    int nbGenerations = 0;  // Nombre de générations maximum

public:
    JeuDeLaVie() = default;

    void choisirDelai() {
        cout << "Choisissez le délai entre chaque génération (en ms) :" << endl;
        cin >> delai;
    }

    void choisirNbGenerations() {
        cout << "Choisissez le nombre de générations maximum (0 pour infini) :" << endl;
        cin >> nbGenerations;
    }

    void choisirGrille() {
        cout << "Choisissez la méthode de génération pour grille initiale :" << endl;
        cout << "1. Générer aléatoirement" << endl;
        cout << "2. Générer à partir d'un fichier" << endl;
        int generation;
        cin >> generation;

        if (generation == 1) {
            grid = Grid(10, 10);
        } else {
            const File file = File("C:/Users/nicol/CLionProjects/ProjetPOO/input.txt");
            grid = file.getGrid();
        }
    }

    void choisirMode() {
        cout << "Choisissez le mode de jeu :" << endl;
        cout << "1. Mode console" << endl;
        cout << "2. Mode graphique" << endl;
        cin >> mode;

        if (mode == 1) {
            display = new ConsoleDisplay();
        } else {
            window.create(VideoMode(grid.getWidth() * cellSize, grid.getHeight() * cellSize), "Jeu de la vie");
            display = new GraphicDisplay(window);
        }
    }

    void start() {
        while(true) {
            if(mode == 2) {
                if(!window.isOpen()) {
                    break;
                }
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                       window.close();
                       break;
                    }
                }
            } else {

            }

            display->renderGrid(grid);

            sleep(milliseconds(delai));

            grid.update();
        }
    }
};



#endif //JEUDELAVIE_H
