#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <iostream>
#include "Affichage.h"
#include "Grille.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class AffichageConsole final : public Affichage {  // Classe héritée de Affichage
public:
    void afficherGrille(const Grille& grille) override;  // Méthode redéfinie
    RenderWindow* obtenirFenetre() override;  // Méthode redéfinie
};



#endif //CONSOLEDISPLAY_H
