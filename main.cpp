#include <iostream>
#include "GameOfLife.h"
#include "ReadFile.h"


int main() {
    string inputFilename;
    cout << "Entrez le nom du fichier d'entree : ";
    getline(cin, inputFilename);

    try {
        ReadFile game = ReadFile::readFromFile(inputFilename);

        cout << "Configuration initiale :" << endl;
        game.display();
    }
    catch (const runtime_error& e) {
        cerr << "Erreur : " << e.what() << endl;
        return 1;
    }

    return 0;
    GameOfLife game;
    game.run();
    return 0;
}

int Chogath() {
    cout << "Chogath" << endl;
    return 0;
}