#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include "Grid.h"

class File {
private:
    std::string filename;

public:
    explicit File(const std::string& filename) : filename(filename) {}

    Grid getGrid() const {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir le fichier : " + filename);
        }

        int height = 0, width = 0;
        file >> height >> width;

        Grid grid = Grid(width, height);
        for (int x = 0; x < height; ++x) {
            for (int y = 0; y < width; ++y) {
                int value;
                file >> value;
                grid.getCell(x, y).setAlive(value);
            }
        }

        file.close();
        return grid;
    }

    void writeFile(const Grid& grid) const {
        std::ofstream file(filename + "_out.txt");
        if (!file.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir le fichier pour écrire : " + filename + "_out.txt");
        }

        file.close();
    }
};

#endif // FILE_H
