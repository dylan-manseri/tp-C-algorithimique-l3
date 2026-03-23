#include <stdio.h>
#include <stdlib.h>

#include "../include/prototypeTD6.h"
#include "../include/prototypeTD12.h"

int estVideMA(MatAdjacence mat) {
    return mat.nbSom == 0;
}

int estVideFS(FileSuccesseur fs) {
    return fs.nbSom == 0;
}

int estVideLA(ListeAdjacence la) {
    return la.nbSom == 0;
}

/**
 * Vérifie qu'un graphe est vide.
 * Il ne sert à rien pour le TP, j'avais juste mal compris le CM.
 * Mais bon, on ne sait jamais donc je garde.
 * @param g Le graphe
 * @param type Le type
 * @return Un booléen
 */
int estVideGraphe(void* g, TypeGraphe type) {
    int estVide;
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        estVide = estVideMA(*mat);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* fs = (FileSuccesseur*) g;
        estVide = estVideFS(*fs);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* la = (ListeAdjacence*) g;
        estVide = estVideLA(*la);
    }
    else {
        printf("\nErreur de type");
        exit(1);
    }
    return estVide;
}

/**
 * Parcours partiel de la matrice d'adjacence.
 * Son but est de trouver le nombre de sommets qui atteignent t.
 * @param mat La matrice d'adjacence.
 * @param t Le sommet à atteindre.
 * @return Le degré
 */
int degreEntrantMA(MatAdjacence mat, int t) {
    int d = 0;
    int n = nbSomMA(mat);
    for (int s=0; s<n; s++) {
        if (mat.mat[s][t] == 1) {
            d++;
        }
    }
    return d;
}

/**
 * Parcours total du tableau de la file de successeur.
 * Si on trouve arc atteignant t, alors on ajoute un degré.
 * @param fs La file de successeur.
 * @param t Le sommet.
 * @return Le degré.
 */
int degreEntrantFS(FileSuccesseur fs, int t) {
    int d = 0;
    for (int arc=0; arc<fs.nbArcs; arc++) {
        if (fs.FS[arc] == t) {
            d++;
        }
    }
    return d;
}

/**
 * Parcours total de la liste d'adjacence.
 * Son but est de trouver le nombre de prédécesseurs de t sans stocker le sommet.
 * @param la La liste d'adjacence.
 * @param t Le sommet.
 * @return Le degré.
 */
int degresEntrantLA(ListeAdjacence la, int t) {
    int d = 0;
    int n = nbSomGen(&la, LISTE_ADJACENCE);
    Liste l;
    for (int s=0; s<n; s++) {
        l = la.tabAdj[s];
        while (!estVide(l)) {
            if (donnee(l) == t) {
                d++;
            }
            l = suivant(l);
        }
    }
    return d;
}

/**
 * Regroupement via généricité des precedentes fonctions.
 * Utilisé pour calculer le degré entrant d'un graphe quelconque.
 * @param g Le graphe d'un type quelconque.
 * @param type Le type du graphe.
 * @param t Le sommets.
 * @return Le degré.
 */
int degreEntrant(void* g, TypeGraphe type, int t) {
    int degreEntrant;
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        degreEntrant = degreEntrantMA(*mat, t);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* fs = (FileSuccesseur*) g;
        degreEntrant = degreEntrantFS(*fs, t);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* la = (ListeAdjacence*) g;
        degreEntrant = degresEntrantLA(*la, t);
    }
    else {
        printf("\nErreur de type");
        exit(1);
    }
    return degreEntrant;
}

/**
 * Effectue le tri topologique d'un graphe quelconque.
 * Ce tri renvoi l'ordre des sommets dans les chemins.
 * Si A→B alors A apparaitra avant B dans le tri.
 * @param g Le graphe
 * @param type Le type du graphe
 * @return La file du tri
 */
File triTopologiqueAcyclique(void* g, TypeGraphe type) {
    // Initialisation
    File f = initL();
    int n = nbSomGen(g, type);
    int* D = allocTab(n);
    Liste M = initL();
    int de;
    for (int s=0; s<n; s++) {           // On remplit notre liste des sommets sans prédécesseurs
        de = degreEntrant(g, type, s);
        if (de == 0) {
            M = inserTete(s, M);
        }
        D[s] = de;                      // On remplit notre tableau des degrés
    }
    // Traitement
    while (!estVide(M)) {
        int t = donnee(M);              // On choisit un sommet sans pred quelconque
        M = suppTete(M);
        D[t] = D[t] - 1;
        f = inserQueue(t, f);
        int* succ = getSuccByType(t, type, g);      // On met à jour le degré de ces successeurs.
        for (int i=1; i<succ[0]+1; i++) {
            D[succ[i]] = D[succ[i]] - 1;
            if (D[succ[i]] == 0) {                  // On met à jour M, si besoin.
                M = inserTete(succ[i], M);
            }
        }
    }
    D = libTabF(D);
    return f;
}

