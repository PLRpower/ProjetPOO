#include <iostream>
#include <string>

#include "File.h"
#include "GraphicDisplay.h"

using namespace std;
constexpr int cellSize = 50;

int main() {
    int generation;
    int mode;
    int gridWidth;
    int gridHeight;
    string filename;

    File file = File("C:/Users/pault/CLionProjects/ProjetPOO/input.txt");
    Grid data = file.readFile();

    cout << "Choisissez la méthode de génération pour grille initiale :" << endl;
    cout << "1. Générer aléatoirement" << endl;
    cout << "2. Générer à partir d'un fichier" << endl;
    cin >> generation;

    switch (generation) {
        case 1:
            cout << "Entrez la largeur de la grille :" << endl;
        cin >> gridWidth;
        cout << "Entrez la hauteur de la grille :" << endl;
        cin >> gridHeight;
        break;
        case 2:
            cout << "Entrez le nom du fichier :" << endl;
        cin >> filename;
        break;
        default:
            cerr << "Choix invalide" << endl;
        return 1;
    }

    cout << "Choisissez le mode de jeu :" << endl;
    cout << "1. Mode console" << endl;
    cout << "2. Mode graphique" << endl;
    cin >> mode;

    GraphicDisplay graphicDisplay = GraphicDisplay();
    RenderWindow window(VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    Grid grid = Grid(gridWidth, gridHeight);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        graphicDisplay.renderGrid(window, grid);

        sleep(milliseconds(100));

        grid.update();
    }

    return 0;
}