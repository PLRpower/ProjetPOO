#ifndef DISPLAY_H
#define DISPLAY_H


#include "Grille.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Affichage {
public:
    virtual ~Affichage() = default;  // Destructeur virtuel

    virtual void afficherGrille(const Grille& grid) = 0;  // Méthode virtuelle pure
    virtual RenderWindow* obtenirFenetre() = 0;  // Méthode virtuelle pure
};

#endif //DISPLAY_H
