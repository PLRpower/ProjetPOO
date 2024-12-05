#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Affichage.h"
#include "Grille.h"

using namespace std;
using namespace sf;

class AffichageGraphique final : public Affichage {
private:
    const int cellSize = 50;
    RenderWindow* fenetre;

public:
    explicit AffichageGraphique();
    void afficherGrille(const Grille &grille) override;
    void definirFenetre(RenderWindow* fenetre);
    RenderWindow* obtenirFenetre() const;
};

#endif // GRAPHICDISPLAY_H
