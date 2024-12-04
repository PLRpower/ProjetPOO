#include <iostream>

#include "JeuDeLaVie.h"

using namespace std;

int main() {
    JeuDeLaVie jeuDeLaVie = JeuDeLaVie();
    jeuDeLaVie.choisirGrille();

    jeuDeLaVie.choisirMode();
    jeuDeLaVie.start();

    return 0;
}