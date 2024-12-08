#ifndef FILE_H
#define FILE_H

#include <string>
#include "Grille.h"
#include <filesystem>

using namespace std;
using namespace filesystem;

class Fichier {
private:
    string fichierEntree;  // Nom du fichier d'entrée
    string dossierSortie;  // Nom du dossier de sortie

public:
    explicit Fichier() = default;  // Constructeur par défaut
    void definirFichierEntree(const string& nomFichier);  // Définit le fichier d'entrée
    void creerDossierSortie();  // Crée le dossier de sortie
    void ecrireFichier(const Grille& grille, int generation) const;  // Écrit le fichier
    Grille obtenirGrille() const;  // Obtenir la grille
};

#endif // FILE_H
