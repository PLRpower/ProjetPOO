#ifndef FILE_H
#define FILE_H

#include <string>
#include "Grille.h"
#include <filesystem>

using namespace std;
using namespace filesystem;

class Fichier {
private:
    string inputFilename;
    string outputFolder;

public:
    explicit Fichier() = default;
    void setInputFile(const string& filename);
    void creerDossierSortie();
    void ecrireFichier(const Grille& grid, const int generation) const;
    Grille getGrid() const;
};

#endif // FILE_H
