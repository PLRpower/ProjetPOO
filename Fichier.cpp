#include "Fichier.h"
#include <iostream>
#include <fstream>

void Fichier::definirFichierEntree(const string& filename) {
    this->fichierEntree = filename;
    ifstream file(filename);
    if(!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier");
    }
}

void Fichier::creerDossierSortie() {
    const string fileNameWithoutExtension = fichierEntree.substr(0, fichierEntree.find_last_of('.'));
    dossierSortie = fileNameWithoutExtension + "_out";
    if(exists(dossierSortie)) {
        remove_all(dossierSortie);
    }
    create_directory(dossierSortie);
}

void Fichier::ecrireFichier(const Grille& grid, const int generation) const {
    const string filename = dossierSortie + "/" + to_string(generation) + ".txt";
    ofstream file(filename);
    file << grid.obtenirHauteur() << " " << grid.obtenirLargeur() << endl;
    for (int x = 0; x < grid.obtenirHauteur(); ++x) {
        for (int y = 0; y < grid.obtenirLargeur(); ++y) {
            file << grid.obtenirCellule(x, y).estEnVie() << " ";
        }
        file << endl;
    }
    file.close();
}

Grille Fichier::obtenirGrille() const {
    ifstream file(fichierEntree);

    int height = 0, width = 0;
    file >> height >> width;

    Grille grid = Grille(width, height);
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            int value;
            file >> value;
            grid.obtenirCellule(x, y).definirVivant(value);
        }
    }

    file.close();
    return grid;
}