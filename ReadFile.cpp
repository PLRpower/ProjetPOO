#include "ReadFile.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ReadFile::ReadFile
(int r, int c) : rows(r), cols(c) {
    grid.resize(rows, vector<bool>(cols, false));
}

void ReadFile::setCell(int i, int j, bool value) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        grid[i][j] = value;
    }
}

bool ReadFile ::getCell(int i, int j) const {
    return grid[i][j];
}

int ReadFile::getRows() const {
    return rows;
}

int ReadFile::getCols() const {
    return cols;
}

ReadFile ReadFile::readFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier " + filename);
    }

    string line;
    getline(inputFile, line);
    istringstream dimensions(line);
    int rows = 0, cols = 0;
    dimensions >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        throw runtime_error("Dimensions invalides dans le fichier");
    }

    ReadFile
 game(rows, cols);

    int currentRow = 0;
    while (getline(inputFile, line) && currentRow < rows) {
        if (line.length() >= cols) {
            for (int j = 0; j < cols; j++) {
                game.setCell(currentRow, j, line[j] == '1');
            }
            currentRow++;
        }
    }

    inputFile.close();
    return game;
}

void ReadFile::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << (grid[i][j] ? "■" : "□");
        }
        cout << endl;
    }
}