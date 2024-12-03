```mermaid 
graph LR
U((Utilisateur))

    U --> C[Choisir la méthode de génération]
    U --> A[Choisir le mode d'affichage]
    U --> F[Fermer le jeu]
    
    C --> G1[Générer grille aléatoire]
    C --> G2[Générer grille à la souris]
    C --> G3[Générer grille depuis un fichier]
    G3 --> P[Définir les paramètres de la grille]
    
    A --> M1[Afficher le mode graphique]
    A --> M2[Afficher le mode console]
    
    M1 --> S[Simuler l'évolution des cellules]
    M2 --> S
``````