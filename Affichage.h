#ifndef DISPLAY_H
#define DISPLAY_H


#include "Grille.h"

class Affichage {
public:
    virtual ~Affichage() = default;

    virtual void afficherGrille(const Grille& grid) = 0;
};

#endif //DISPLAY_H
