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
    RenderWindow* window;

public:
    explicit AffichageGraphique();
    void afficherGrille(const Grille &grid) override;
    void setWindow(RenderWindow* window);
    RenderWindow* getWindow() const;
};

#endif // GRAPHICDISPLAY_H
