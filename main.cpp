#include <iostream>
#include "JeuDeLaVie.h"

using namespace std;

int main() {
    JeuDeLaVie jeuDeLaVie = JeuDeLaVie();  // Crée un jeu de la vie

    jeuDeLaVie.start();  // Démarre le jeu

    if(jeuDeLaVie.testUnitaire()) {  // Si le test unitaire est vrai
        cout << "Test unitaire réussi !" << endl;  // Affiche le message
    } else {  // Sinon
        cout << "Test unitaire échoué !" << endl;  // Affiche le message
    }

    return 0;
}