#include <iostream>
#include <string>

#include "File.h"
#include "GraphicDisplay.h"

using namespace std;
constexpr int cellSize = 50;

int main() {
    int generation;
    int mode;
    File file = File("C:/Users/pault/CLionProjects/ProjetPOO/input.txt");

    cout << "Choisissez la méthode de génération pour grille initiale :" << endl;
    cout << "1. Générer aléatoirement" << endl;
    cout << "2. Générer à partir d'un fichier" << endl;
    cin >> generation;

    Grid grid;
    if (generation == 1) {
        grid = Grid(10, 10);
    } else {
        grid = file.readFile();
    }

    cout << "Choisissez le mode de jeu :" << endl;
    cout << "1. Mode console" << endl;
    cout << "2. Mode graphique" << endl;
    cin >> mode;

    GraphicDisplay graphicDisplay = GraphicDisplay();
    RenderWindow window(VideoMode(grid.getWidth() * cellSize, grid.getHeight() * cellSize), "Game of Life");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        graphicDisplay.renderGrid(window, grid);

        sleep(milliseconds(1));

        grid.update();
    }

    return 0;
}