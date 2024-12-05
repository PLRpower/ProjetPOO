#ifndef CELL_H
#define CELL_H

class Grille;

class Cellule {
private:
    bool enVie, nextState, fixe;
    int x, y;

public:
    Cellule();
    void initialiser(int x, int y);
    void definirVivant(bool status);
    bool estEnVie() const;
    int obtenirX() const { return x; }
    int obtenirY() const { return y; }
    void definirFixe(const bool fixed) { this->fixe = fixed; }
    int compterVoisins(const Grille* grille) const;
    bool obtenirEtatSuivant() const { return nextState; }
    void mettreEtatSuivant(const bool nextState) { this->nextState = nextState; }
};



#endif //CELL_H
