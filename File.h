#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <vector>
#include <string>

#include "Grid.h"

using namespace std;

class File {
private:
    string filename;
    int width = 0;
    int height = 0;

public:
    explicit File(const string &filename): filename(filename) {}

    Grid readFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }

        file >> width >> height;  // Lire les dimensions de la grille (deux premiers entiers du fichier)

        Grid grid = Grid(width, height);
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                bool alive;
                file >> alive;
                grid.setAlive(x, y, alive);
            }
        }

        file.close();
        return grid;
    }

    // Écrire un vecteur de vecteurs de booléens dans un fichier
    void writeFile(const Grid &grid) {
        ofstream file(filename + "_");
        if (!file.is_open()) {
            throw runtime_error("Impossible d'ouvrir le fichier.");
        }

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                file << grid.isAlive(x, y) << " ";
            }
            file << endl;
        }

        file.close();
    }
};



#endif //FILE_H
