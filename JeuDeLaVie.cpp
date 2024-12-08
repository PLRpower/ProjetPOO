#include "JeuDeLaVie.h"
#include <iostream>

#include "AffichageConsole.h"

JeuDeLaVie::JeuDeLaVie() {
    chosisirMethodeGeneration();  // Choix de la méthode de génération
    choisirTorique();  // Choix de la grille torique
    choisirDelai();  // Choix du délai
    choisirNbGenerations();  // Choix du nombre de générations
    choisirModeAffichage();  // Choix du mode de jeu
}

JeuDeLaVie::~JeuDeLaVie() {
    delete affichage;  // Supprime l'affichage
}

void JeuDeLaVie::chosisirMethodeGeneration() {
    cout << "Choisissez la méthode de génération :" << endl
        << "1. Par fichier" << endl
        << "2. Aléatoire" << endl;
    cin >> methodeGeneration;  // Récupère la méthode
    if(methodeGeneration == 1) {  // Si la méthode est 1
        choisirFichier();  // Choix du fichier
    } else {
        cout << "Choisissez la largeur de la grille :" << endl;
        int largeur, hauteur;  // Largeur et hauteur de la grille
        cin >> largeur;  // Récupère la largeur
        cout << "Choisissez la hauteur de la grille :" << endl;
        cin >> hauteur;  // Récupère la hauteur
        grille = Grille(largeur, hauteur);  // Crée une grille
        grille.genererAleatoire();  // Génère une grille aléatoire
    }
}

void JeuDeLaVie::choisirFichier() {
    cout << "Choisissez le fichier d'entrée :" << endl;
    string nomFichier;  // Nom du fichier
    cin >> nomFichier;  // Récupère le nom du fichier
    fichier.definirFichierEntree(nomFichier);  // Définit le fichier d'entrée
    grille = fichier.obtenirGrille();  // Obtient la grille
}

void JeuDeLaVie::choisirModeAffichage() {
    cout << "Choisissez le mode d'affichage du jeu :" << endl
        << "1. Mode console" << endl
        << "2. Mode graphique" << endl;
    cin >> modeAffichage;  // Récupère le mode

    if (modeAffichage == 1) {  // Si le mode est 1
        affichage = new AffichageConsole();  // Crée un affichage console
    } else {  // Sinon
        affichage = new AffichageGraphique(grille.obtenirLargeur(), grille.obtenirHauteur());  // Crée un affichage graphique
    }
}

void JeuDeLaVie::choisirTorique() {
    cout << "La grille est-elle torique ? (1. Oui, 2. Non)" << endl;
    int torique;  // Torique
    cin >> torique;  // Récupère le torique
    grille.definirTorique(torique == 1);  // Définit si la grille est torique
}

void JeuDeLaVie::choisirDelai() {
    cout << "Choisissez le délai entre chaque génération (en ms) :" << endl;
    cin >> delai;  // Récupère le délai
}

void JeuDeLaVie::choisirNbGenerations() {
    cout << "Choisissez le nombre de générations maximum (0 pour infini) :" << endl;
    cin >> nbGenMax;  // Récupère le nombre de générations maximum
}

bool JeuDeLaVie::verifierFermetureFenetre() const {
    Event event;  // Crée un événement
    RenderWindow* fenetre = affichage->obtenirFenetre();  // Obtient la fenêtre
    while(fenetre->pollEvent(event)) {  // Tant qu'il y a un événement
        if(event.type == Event::Closed) {  // Si l'événement est une fermeture de fenêtre
            fenetre->close();  // Ferme la fenêtre
            return true;  // Retourne vrai
        }
    }
    return false;  // Retourne faux
}

void JeuDeLaVie::start() {
    RenderWindow* fenetre = affichage->obtenirFenetre();  // Obtient la fenêtre

    fichier.creerDossierSortie();  // Crée le dossier de sortie

    while (generation < nbGenMax || nbGenMax == 0) {  // Tant que la génération est inférieure au nombre de générations maximum
        if(fenetre->isOpen()) {  // Si on est en mode graphique
            if(verifierFermetureFenetre()) {  // Si la fenêtre est fermée
                break;  // Arrête la simulation
            }
        }

        affichage->afficherGrille(grille);  // Affiche la grille

        fichier.ecrireFichier(grille, generation);  // Écrit la nouvelle génération de grille dans le fichier

        grille.actualiser();  // Actualise la grille

        if(grillePrecedentes.contains(grille.grilleEnTexte())) {  // Si la grille actualisée est déjà présente dans les grilles précédentes
            cout << "La grille se repète, fin de la simulation." << endl;
            break;  // Arrête la simulation
        }

        grillePrecedentes.insert(grille.grilleEnTexte());  // Ajoute la grille actualisée dans les grilles précédentes

        ++generation;  // Incrémente la génération

        sleep(milliseconds(delai));  // Attend le délai
    }

    while (fenetre->isOpen()) {  // Tant que la fenêtre est ouverte
        if (verifierFermetureFenetre()) {  // Si la fenêtre est fermée
            break;  // Arrête la simulation
        }
    }
}

bool JeuDeLaVie::testUnitaire() {
    Fichier fichier;
    fichier.definirFichierEntree("testUnitaire-initial.txt");  // Définit le fichier d'entrée
    Grille grille = fichier.obtenirGrille();  // Obtient la grille
    if(grille.obtenirHauteur() != 25 || grille.obtenirLargeur() != 25) {  // Si la hauteur ou la largeur de la grille est différente de 25
        return false;  // Retourne faux
    }
    if(grille.obtenirCellule(0, 0).estEnVie()) {  // Si la cellule (0, 0) est vivante
        return false;  // Retourne faux
    }
    if(!grille.obtenirCellule(0, 1).estEnVie()) {  // Si la cellule (0, 1) est morte
        return false;  // Retourne faux
    }
    generation = 0;  // Génération actuelle
    nbGenMax = 5;  // Nombre de générations maximum
    while(generation < nbGenMax) {  // Tant que la génération est inférieure au nombre de générations maximum
        grille.actualiser();  // Actualise la grille
        ++generation;  // Incrémente la génération
    }
    fichier.definirFichierEntree("testUnitaire-final.txt");  // Définit le fichier d'entrée
    Grille grilleTest = fichier.obtenirGrille();  // Obtient la grille
    if(grille.grilleEnTexte() != grilleTest.grilleEnTexte()) {  // Si la grille actuelle est différente de la grille de test
        cout << "Erreur de grille" << endl;
        return false;  // Retourne faux
    }

    return true;  // Si tout est bon, retourne vrai
}