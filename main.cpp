#include <iostream>
#include "JeuDeLaVie.h"

using namespace std;

int main() {
    JeuDeLaVie jeuDeLaVie = JeuDeLaVie();

    jeuDeLaVie.choisirFichier();

    jeuDeLaVie.choisirGrille();

    jeuDeLaVie.choisirMode();

    jeuDeLaVie.start();

    return 0;
}