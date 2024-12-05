#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>
#include "Grille.h"
#include <filesystem>

using namespace std;
using namespace filesystem;

class File {
private:
    string inputFilename;
    string outputFolder;

public:
    explicit File() {}

    void setInputFile(const string& filename) {
        this->inputFilename = filename;
        ifstream file(filename);
        if(!file.is_open()) {
            throw runtime_error("Impossible d'ouvrir le fichier");
        }
    }

    void creerDossierSortie() {
        const string fileNameWithoutExtension = inputFilename.substr(0, inputFilename.find_last_of('.'));
        outputFolder = fileNameWithoutExtension + "_out";
        if(exists(outputFolder)) {
            remove_all(outputFolder);
        }
        create_directory(outputFolder);
    }

    void ecrireFichier(const Grille& grid, const int generation) const {
        const string filename = outputFolder + "/" + to_string(generation) + ".txt";
        ofstream file(filename);
        file << grid.getHeight() << " " << grid.getWidth() << endl;
        for (int x = 0; x < grid.getHeight(); ++x) {
            for (int y = 0; y < grid.getWidth(); ++y) {
                file << grid.obtenirCellule(x, y).isAlive() << " ";
            }
            file << endl;
        }
        file.close();
    }

    Grille getGrid() const {
        ifstream file(inputFilename);

        int height = 0, width = 0;
        file >> height >> width;

        Grille grid = Grille(width, height);
        for (int x = 0; x < height; ++x) {
            for (int y = 0; y < width; ++y) {
                int value;
                file >> value;
                grid.obtenirCellule(x, y).setAlive(value);
            }
        }

        file.close();
        return grid;
    }
};

#endif // FILE_H
