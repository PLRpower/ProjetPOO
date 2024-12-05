#ifndef FILE_H
#define FILE_H

#include <string>
#include "Grille.h"
#include <filesystem>

using namespace std;
using namespace filesystem;

class Fichier {
private:
    string fichierEntree;
    string dossierSortie;

public:
    explicit Fichier() = default;
    void definirFichierEntree(const string& filename);
    void creerDossierSortie();
    void ecrireFichier(const Grille& grid, int generation) const;
    Grille obtenirGrille() const;
};

#endif // FILE_H
