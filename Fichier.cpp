#include "Fichier.h"
#include <iostream>
#include <fstream>

void Fichier::definirFichierEntree(const string& nomFichier) {
    this->fichierEntree = nomFichier;  // Définit le fichier d'entrée
    ifstream file(nomFichier);  // Ouvre le fichier
    if(!file.is_open()) {  // Si le fichier n'est pas ouvert
        throw runtime_error("Impossible d'ouvrir le fichier");  // Lève une exception
    }
}

void Fichier::creerDossierSortie() {
    const string fileNameWithoutExtension = fichierEntree.substr(0, fichierEntree.find_last_of('.'));  // Nom du fichier sans extension
    dossierSortie = fileNameWithoutExtension + "_out";  // Nom du dossier de sortie
    if(exists(dossierSortie)) {  // Si le dossier existe
        remove_all(dossierSortie);  // Supprime le dossier et son contenu
    }
    create_directory(dossierSortie);  // Crée le dossier
}

Grille Fichier::obtenirGrille() const {
    ifstream file(fichierEntree);  // Ouvre le fichier

    int hauteur, largeur;  // Hauteur et largeur de la grille
    file >> hauteur >> largeur;  // Lit la hauteur et la largeur

    Grille grid = Grille(largeur, hauteur);  // Crée une grille
    for (int x = 0; x < hauteur; ++x) {  // Parcourir les lignes
        for (int y = 0; y < largeur; ++y) {  // Parcourir les colonnes
            int value;  // Valeur de la cellule
            file >> value;  // Lit la valeur
            if(value == 3 || value == 1) {  // Si la valeur est 3 ou 1
                grid.obtenirCellule(x, y).definirVivant(true);  // Définit la cellule comme vivante
            } else {
                grid.obtenirCellule(x, y).definirVivant(false);  // Définit la cellule comme morte
            }
            if(value == 2 || value == 3) {  // Si la valeur est 2 ou 3
                grid.obtenirCellule(x, y).definirObstacle(true);  // Définit la cellule comme obstacle
            } else {
                grid.obtenirCellule(x, y).definirObstacle(false);  // Définit la cellule comme non obstacle
            }
        }
    }

    file.close();  // Ferme le fichier
    return grid;  // Retourne la grille
}

void Fichier::ecrireFichier(const Grille& grille, const int generation) const {
    const string nomFichier = dossierSortie + "/" + to_string(generation) + ".txt";  // Nom du fichier
    ofstream file(nomFichier);  // Ouvre le fichier
    file << grille.obtenirHauteur() << " " << grille.obtenirLargeur() << endl;  // Écrit la hauteur et la largeur
    for (int x = 0; x < grille.obtenirHauteur(); ++x) {  // Parcourir les lignes
        for (int y = 0; y < grille.obtenirLargeur(); ++y) {  // Parcourir les colonnes
            file << grille.obtenirCellule(x, y).estEnVie() << " ";  // Écrit le statut de la cellule
        }
        file << endl;  // Saut de ligne
    }
    file.close();  // Ferme le fichier
}