#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H


#include "ConsoleDisplay.h"
#include "GraphicDisplay.h"
#include "Display.h"
#include "File.h"
#include "Grille.h"
#include <filesystem>

constexpr int cellSize = 50;

class JeuDeLaVie {
private:
    int mode;
    Grille grille;
    Display *affichage;
    RenderWindow fenetre;
    File fichier;
    int delai = 100;
    int modifVisuel = 0;
    int generation = 0;
    int nbGenMax = 100;
    unordered_set<string> grillePrecedentes;


public:
    JeuDeLaVie() = default;

    void choisirFichier() {
        cout << "Choisissez le fichier d'entrée :" << endl;
        string filename;
        cin >> filename;
        fichier.setInputFile(filename);
        grille = fichier.getGrid();
    }

    void choisirDelai() {
        cout << "Choisissez le délai entre chaque génération (en ms) :" << endl;
        cin >> delai;
    }

    void choisirNbGenerations() {
        cout << "Choisissez le nombre de générations maximum (0 pour infini) :" << endl;
        cin >> nbGenMax;
    }

    void choisirGrille() {
        cout << "Voulez vous modifier les cases visuellement ? (1. Oui, 2. Non)" << endl;
        cin >> modifVisuel;
    }

    void choisirMode() {
        cout << "Choisissez le mode de jeu :" << endl;
        cout << "1. Mode console" << endl;
        cout << "2. Mode graphique" << endl;
        cin >> mode;

        if (mode == 1) {
            affichage = new ConsoleDisplay();
        } else {
            fenetre.create(VideoMode(grille.getWidth() * cellSize, grille.getHeight() * cellSize), "Jeu de la vie");
            affichage = new GraphicDisplay();
            GraphicDisplay* graphicDisplay = dynamic_cast<GraphicDisplay*>(affichage);
            graphicDisplay->setWindow(&fenetre);
        }
    }

    void choisirTorique() {
        cout << "La grille est-elle torique ? (1. Oui, 2. Non)" << endl;
        int torique;
        cin >> torique;
        grille.setToric(torique == 1);
    }

    void start() {
        fichier.creerDossierSortie();

        while (generation < nbGenMax || nbGenMax == 0) {
            if(mode == 2) {
                Event event;
                while(fenetre.pollEvent(event)) {
                    if(event.type == Event::Closed) {
                        break;
                    }
                }
            }

            affichage->afficherGrille(grille);

            fichier.ecrireFichier(grille, generation);

            grille.actualiser();

            if(grillePrecedentes.contains(grille.grilleEnTexte())) {
                cout << "La grille se repète, fin de la simulation." << endl;
                break;
            }

            grillePrecedentes.insert(grille.grilleEnTexte());

            ++generation;

            sleep(milliseconds(delai));
        }
    }
};



#endif //JEUDELAVIE_H
