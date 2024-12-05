//
// Created by pault on 04/12/2024.
//

#ifndef DISPLAY_H
#define DISPLAY_H


#include "Grille.h"

class Display {
public:
    virtual ~Display() = default;

    virtual void afficherGrille(const Grille& grid) = 0;
};

#endif //DISPLAY_H
