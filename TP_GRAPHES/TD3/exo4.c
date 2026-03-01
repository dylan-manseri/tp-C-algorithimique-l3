#include "../include/prototypeTD3.h"
#include "../include/prototypeTD12.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Renvoi le sommet suivant, selon l'ordre lexicographique
 * @param s Le sommet actuel
 * @param n Le nombre de sommets
 * @param visite Le tableau des visites
 * @return Le prochain sommet à visiter
 */
int somSuivant(int s, int n, int* visite) {
    int trouve = 0;
    while (!trouve) {
        if (visite[s] != 1) {
            trouve = 1;
        }
        else {
           s++;
            if (s > n) {
            s=0;
            }
        }
    }
    return s;
}

/**
 * Renvoi un tableau des successeurs dépendamment du type du graphe (via généricité)
 * Le premier indice du tableau est le nombre de successeurs
 * @param s Le sommet dont on souhaite connaître les successeurs
 * @param type Le type de graphe
 * @return Le tableau des successeurs
 */
int* getSuccByType(int s, TypeGraphe type, void* g) {
    int* succ;
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        succ = getSuccMatAdj(s, *mat);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* fs = (FileSuccesseur*) g;
        succ = getSuccFS(s, *fs);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* la = (ListeAdjacence*) g;
        succ = getSuccL(s, *la);
    }
    else {
        printf("\nErreur de type");
        exit(1);
    }
    return succ;
}

/**
 * Algorithme récursif de parcours en profondeur d'un graphe.
 * On parcourt le plus profondement possible, s'il n'est plus possible d'avancer, on retourne d'un pas en arrière.
 * Ensuite, on recommence avec un autre sommet non visité
 * @param s Le sommet de départ
 * @param visite Le tableau des visites
 * @param g Le graphe à parcourir
 * @param type Le type du graphe
 * @param n Le nombre de sommets
 * @param nbSomVisite Le nombre de sommets visité
 */
void reParcoursProfondeur(int *s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite)  {
    if (*nbSomVisite < n) {
        visite[*s] = 1;
        printf(" %d |", *s);       // Traiter
        *nbSomVisite = *nbSomVisite+1;
        int* succ = getSuccByType(*s, type, g);
        for (int i=1; i<succ[0]+1; i++) {
            if (!visite[succ[i]]) {
                *s = succ[i];
                reParcoursProfondeur(s, visite, g, type, n, nbSomVisite);
            }
        }
    }
}

/**
 * Debut de l'algorithme de parcours en profondeur
 * @param sd Sommet de départ
 * @param g Le graphe
 * @param type Le type du graphe
 */
void parcoursProfondeur(int sd, void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* visite = allocTab(n);
    for (int s=0; s<n; s++) {
        visite[s] = 0;
    }
    int s = sd;
    int nbSomVisite = 0;
    int finParcours = 0;
    printf("Sommets rencontrés : |");
    while (!finParcours) {
        reParcoursProfondeur(&s, visite, g, type, n, &nbSomVisite);
        if (nbSomVisite < n) {
            s = somSuivant(s, n, visite);
        }
        else {
            finParcours = 1;
        }
    }
}

/**
 * Algorithme de parcours en largeur itératif d'un graphe.
 * On parcourt les successeurs les un après les autres.
 * Une fois les successeurs parcourut, on fait de même leurs successeurs
 * @param s Le sommet de départ
 * @param visite Le tableau des visites
 * @param g Le graphe
 * @param n Le nombre de sommets
 * @param nbSomVisite Le nombre de sommets visité
 * @param type Le type du graphe
 */
void itParcoursLargeur(int *s, int* visite, void* g, int n, int* nbSomVisite, TypeGraphe type) {
    File f = initL();
    f = inserQueue(*s, f);       // Enfiler
    int arret = 0;
    int u;
    while (!estVide(f) && !arret) {
        u = donnee(f);
        f = suppTete(f);
        if (!visite[u]) {
            visite[u] = 1;
            printf(" %d |", u);   // Traiter
            *nbSomVisite = *nbSomVisite+1;
            if (*nbSomVisite == n) {
                arret = 1;
            }
            else {
                int* succ = getSuccByType(u, type, g);     // succ[0] stocke le nombre de successeurs
                for (int i=1; i<succ[0]+1; i++) {
                    if (!visite[succ[i]]) {
                        f = inserQueue(succ[i], f);           // Enfiler
                    }
                }
            }
        }

    }
}

/**
 * Debut de l'algorithme de parcours en largeur.
 * @param sd Le sommet de départ.
 * @param g Le graphe
 * @param type Le type du graphe
 */
void parcoursLargeur(int sd, void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* visite = allocTab(n);
    for (int i=0; i<n; i++) {
        visite[i] = 0;
    }
    int nbSomVisite = 0;
    int s = sd;
    int finParcours = 0;
    printf("Sommets rencontrés : |");
    while (!finParcours) {
        itParcoursLargeur(&s, visite, g, n, &nbSomVisite, type);
        if (nbSomVisite < n) {
            s = somSuivant(s, n, visite);
        }
        else {
            finParcours = 1;
        }
    }
    visite = libTabF(visite);
}