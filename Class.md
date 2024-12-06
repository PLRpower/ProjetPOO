    ```mermaid 
    classDiagram
    class JeuDeLaVie {
    -mode: int
    -grille: Grille
    -affichage: Affichage*
    -fenetre: RenderWindow
    -fichier: Fichier
    -delai: int
    -modifVisuel: int
    -generation: int
    -nbGenMax: int
    -grillePrecedentes: unordered_set~string~
    +choisirFichier()
    +choisirDelai()
    +choisirNbGenerations()
    +choisirGrille()
    +choisirMode()
    +choisirTorique()
    +start()
    }
    
        class Affichage {
            <<abstract>>
            +afficherGrille(grille: Grille)* : void
        }
    
        class AffichageConsole {
            +afficherGrille(grille: Grille) : void
        }
    
        class AffichageGraphique {
            -cellSize: int
            -fenetre: RenderWindow*
            +AffichageGraphique()
            +afficherGrille(grille: Grille) : void
            +definirFenetre(fenetre: RenderWindow*)
            +obtenirFenetre() : RenderWindow*
        }
    
        class Grille {
            -largeur: int
            -hauteur: int
            -cellules: vector~Cellule~
            -torique: bool
            +Grille()
            +Grille(largeur: int, hauteur: int)
            +definirTaille(largeur: int, hauteur: int)
            +actualiser()
            +grilleEnTexte() : string
            +obtenirCellule(x: int, y: int) : Cellule&
            +obtenirLargeur() : int
            +obtenirHauteur() : int
            +estTorique() : bool
            +definirTorique(torique: bool)
        }
    
        class Cellule {
            -enVie: bool
            -nextState: bool
            -fixe: bool
            -x: int
            -y: int
            +Cellule()
            +initialiser(x: int, y: int)
            +definirVivant(status: bool)
            +estEnVie() : bool
            +obtenirX() : int
            +obtenirY() : int
            +definirFixe(fixed: bool)
            +compterVoisins(grille: Grille*) : int
            +obtenirEtatSuivant() : bool
            +mettreEtatSuivant(nextState: bool)
        }
    
        class Fichier {
            -fichierEntree: string
            -dossierSortie: string
            +Fichier()
            +definirFichierEntree(filename: string)
            +creerDossierSortie()
            +ecrireFichier(grid: Grille, generation: int)
            +obtenirGrille() : Grille
        }
        Cellule --> Grille
        Affichage <|-- AffichageConsole
        Affichage <|-- AffichageGraphique
        JeuDeLaVie o-- Grille
        JeuDeLaVie o-- Affichage
        JeuDeLaVie o-- Fichier
    ```