#include <stdio.h>
#include <stdlib.h>
#include "../include/prototypeTD9.h"
#include "../include/prototypeTD12.h"
#define INFINI 1000



/**
 * Renvoi l'indice du sommet non visité au cout minimal
 * @param D Le tableau des coûts
 * @param n Le nombre de sommets
 * @param visite Le tableau des visites indicé par le sommet
 * @return l'index du minimum
 */
int indexMin(int * D, int n, int* visite) {
    int indexMin = -1;
    int min = INFINI;
    for (int s=0; s<n; s++) {
        if (D[s] < min && !visite[s]) {
            min = D[s];
            indexMin = s;
        }
    }
    return indexMin;
}

/**
 * Algorithme de Prim.
 * Il recherche l'arbre couvrant en partant d'un sommet donné
 * @param sd Le sommet de départ
 * @param g Le graphe de type quelconque
 * @param type Le type de graphe
 * @param D Le tableau des coûts
 * @param P Le tableau des prédécesseurs
 */
void prim(int sd, void* g, TypeGraphe type, int* D, int* P) {
    // Initialisation
    int n = nbSomGen(g, type);
    int* visite = malloc(n * sizeof(int));
    for (int s=0; s<n; s++) {
        D[s] = INFINI;
        P[s] = -1;
        visite[s] = 0;
    }
    D[sd] = 0;
    int nbVisiste = 0;
    int s = sd;
    int tmp;
    // Traitement
    do {
        visite[s] = 1;
        int* succ = getSuccByType(s, type, g);
        for (int t=1; t<succ[0]; t++) {
            if (!visite[succ[t]]) {
                tmp = cout(s, succ[t], g, type);
                if (tmp < D[succ[t]]) {
                    D[succ[t]] = tmp;
                    P[succ[t]] = s;
                }
            }
        }
        nbVisiste++;
        s = indexMin(D, n, visite);
    } while (nbVisiste<n);
}

/**
 * Algorithme déterminant la racine de la composante d'un sommet.
 * @param s Le sommet dont on recherche la racine
 * @param PP Le tableau des parents
 * @return La racine
 */
int find(int s, int* PP) {
    int M = s;
    while (PP[M] >= 0) {
        M = PP[M];
    }
    return M;
}

/**
 * Fonction qui teste si deux sommets font partie de la même composante.
 * Elle cherche leurs racine et les comparent.
 * Si ils n'ont pas la même racine, le parent de t devient s, PP[t] = s.
 * @param s Le sommet de départ
 * @param t Le sommet d'arrivée
 * @param PP Le tableau es parents
 * @return Si l'union à fonctionnée ou pas
 */
int estUnion(int s, int t, int* PP) {
    int estUnion = 0;
    int M1 = find(s, PP);
    int M2 = find(t, PP);
    if (M1 != M2) {
        estUnion = 1;       // On a réussi à les unir
        PP[M2] = M1;
    }
    return estUnion;
}

/**
 * Fonction qui initialise les différentes structures du programme :
 *  - Le tableau des parents à -1.
 *  - La liste d'arcs triée dans l'ordre croissant des coûts.
 *  - La matrice d'incidence colonne par colonne.
 * @param ma La matrice d'adjacence de départ.
 * @param T La matrice d'incidence colonne par colonne résultante.
 * @param PP Le tableau des parents.
 * @return La liste d'arete trié dans l'odre croissant
 */
ListeArete initKruskal(MatAdjacence ma, MatriceIncidenceCC* T, int** PP) {
    int n = nbSomMA(ma);
    ListeArete u = initLArete();
    *T = allocSMICC(n);
    *PP = allocTab(n);
    int c;
    for (int s=0; s<n; s++) {
        (*PP)[s] = -1;
        Arete a;
        for (int t=0; t<n; t++) {
            c = ma.cout[s][t];
            if (c != -1) {
                a.somS = s;
                a.somT = t;
                a.cout = c;
                u = inserTrieeLA(a, u);
            }
        }
    }
    return u;
}

/**
 * Fonction centralisant la liste d'instruction à faire lors d'une itération.
 *  - Récupère la tête de la liste et la supprime
 *  - Teste si les deux sommets peuvent s'unir
 *      - Auquel cas il faudra stocker l'arc dans la matrice d'incidence colonne par colonne
 * @param numA Le numéro de l'arc minimal
 * @param T La matrice d'incidence colonne par colonne résultante
 * @param U La liste des arcs triée dans l'ordre croissant
 * @param PP Le tableau des parents
 * @param cout Le cout de l'arc minimal
 * @return La liste d'arete mise à jour
 */
ListeArete iterKruskal(int numA, MatriceIncidenceCC* T, ListeArete U, int* PP, int* cout) {
    Arete minU = donneeLA(U);
    U = suppTeteLA(U);
    int s = minU.somS;
    int t = minU.somT;
    int c = minU.cout;
    *cout = 0;
    if (estUnion(s, t, PP)) {
        T->alpha[numA] = s;
        T->beta[numA] = t;
        T->cout[numA] = c;
        *cout = c;
    }
    else {
        printf("Rejetée cycle");
    }
    return U;
}

/**
 * Le vrai boss de fin de l'algorithmique.
 * Fonction central d'exécution de l'algorithme de Kruskal.
 * Il trouve l'arbre couvrant minimal,
 * C'est-à-dire un sous graphe tel que :
 *  - Il contient tous les sommets.
 *  - Il est connexe.
 *  - Il ne contient pas de cycle.
 * @param ma La matrice d'adjacence de base
 * @param T La matrice d'incidence colonne par colonne résultante
 * @param PP Le tableau des parents.
 */
void kruskal(MatAdjacence ma, MatriceIncidenceCC* T, int* PP) {
    ListeArete u = initKruskal(ma, T, &PP);
    int cMin = 0;
    int iter = 0;
    int n = nbSomMA(ma);
    int cout;
    while (iter < n-1 && !estVideLA(u)) {
        u = iterKruskal(iter, T, u, PP, &cout);
        if (cout != 0) {
            iter = iter+1;
            cMin = cMin+cout;
        }
    }
}