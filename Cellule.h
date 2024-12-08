#ifndef CELL_H
#define CELL_H

class Grille;

class Cellule {
private:
    bool enVie, etatSuivant, fixe;
    int x, y;

public:
    Cellule();  // Constructeur par défaut
    void initialiser(int x, int y);  // Initialise la cellule
    void definirVivant(bool status);  // Définit le statut de la cellule
    bool estEnVie() const;  // Retourne le statut de la cellule
    void definirObstacle(const bool fixe) { this->fixe = fixe; }  // Définit si la cellule est fixe
    int compterVoisins(const Grille* grille) const;  // Compte le nombre de voisins vivants
    bool obtenirEtatSuivant() const { return etatSuivant; }  // Retourne l'état suivant
    void mettreEtatSuivant(const bool nextState) { this->etatSuivant = nextState; }  // Définit l'état suivant
};



#endif //CELL_H
