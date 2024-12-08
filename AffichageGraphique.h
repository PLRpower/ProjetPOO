#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Affichage.h"
#include "Grille.h"

using namespace std;
using namespace sf;

class AffichageGraphique final : public Affichage {  // Classe héritée de Affichage
private:
    int cellSize;  // Taille d'une cellule
    RenderWindow fenetre;  // Fenêtre d'affichage

public:
    explicit AffichageGraphique(int largeur, int hauteur);  // Constructeur par défaut
    void afficherGrille(const Grille &grille) override;  // Affiche la grille
    RenderWindow* obtenirFenetre() override;  // Obtenir la fenêtre
};

#endif // GRAPHICDISPLAY_H
