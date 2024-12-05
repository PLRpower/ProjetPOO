#ifndef CELL_H
#define CELL_H

class Grille;

class Cellule {
private:
    bool alive, nextState, fixed;
    int x, y;

public:
    Cellule();
    void initialize(int x, int y);
    void setAlive(bool status);
    bool isAlive() const;
    int getX() const { return x; }
    int getY() const { return y; }
    void setFixed(const bool fixed) { this->fixed = fixed; }
    int countNeighbors(const Grille* grid) const;
    bool getNextState() const { return nextState; }
    void setNextState(const bool nextState) { this->nextState = nextState; }
};



#endif //CELL_H
