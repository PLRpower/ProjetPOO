#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include <iostream>
#include "Affichage.h"
#include "Grille.h"

using namespace std;

class AffichageConsole final : public Affichage {
public:
    void afficherGrille(const Grille& grid) override;
};



#endif //CONSOLEDISPLAY_H
