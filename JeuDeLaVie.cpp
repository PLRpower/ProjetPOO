#include "JeuDeLaVie.h"

void JeuDeLaVie::choisirFichier() {
    cout << "Choisissez le fichier d'entrée :" << endl;
    string filename;
    cin >> filename;
    fichier.setInputFile(filename);
    grille = fichier.getGrid();
}

void JeuDeLaVie::choisirDelai() {
    cout << "Choisissez le délai entre chaque génération (en ms) :" << endl;
    cin >> delai;
}

void JeuDeLaVie::choisirNbGenerations() {
    cout << "Choisissez le nombre de générations maximum (0 pour infini) :" << endl;
    cin >> nbGenMax;
}

void JeuDeLaVie::choisirGrille() {
    cout << "Voulez vous modifier les cases visuellement ? (1. Oui, 2. Non)" << endl;
    cin >> modifVisuel;
}

void JeuDeLaVie::choisirMode() {
    cout << "Choisissez le mode de jeu :" << endl;
    cout << "1. Mode console" << endl;
    cout << "2. Mode graphique" << endl;
    cin >> mode;

    if (mode == 1) {
        affichage = new AffichageConsole();
    } else {
        fenetre.create(VideoMode(grille.getWidth() * cellSize, grille.getHeight() * cellSize), "Jeu de la vie");
        affichage = new AffichageGraphique();
        AffichageGraphique* graphicDisplay = dynamic_cast<AffichageGraphique*>(affichage);
        graphicDisplay->setWindow(&fenetre);
    }
}

void JeuDeLaVie::choisirTorique() {
    cout << "La grille est-elle torique ? (1. Oui, 2. Non)" << endl;
    int torique;
    cin >> torique;
    grille.setToric(torique == 1);
}

void JeuDeLaVie::start() {
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