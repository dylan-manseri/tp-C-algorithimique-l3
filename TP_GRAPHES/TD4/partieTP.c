#include <stdio.h>
#include <stdlib.h>

#include "../include/prototypeTD4.h"

/**
 * (s, t) appartient à G² ssi, il existe un u tq (s, u) appartient à G et (u, t) appartient à G
 * @param g La matrice adjacence
 * @return g² la matrice adjacence du carré du graphe
 */
MatAdjacence getCarreMA(MatAdjacence g) {
    int n = g.nbSom;
    MatAdjacence g2 = allocSMA_F(n);
    int u;
    for (int s=0; s<n; s++) {
        for (int t=0; t<n; t++) {
            u = 0;
            while (u<n && g.mat[s][u]*g.mat[u][t] != 1) {
                u++;
            }
            if (u<n) {
                g2.mat[s][t] = 1;
            }
            else {
                g2.mat[s][t] = 0;
            }
        }
    }
    return g2;
}

/**
 * La même chose, mais avec la liste d'adjacence
 * @param g La liste d'adjacence initial
 * @return La liste d'adjacence du graphe au carré
 */
ListeAdjacence getCarreLA(ListeAdjacence g) {
    ListeAdjacence g2;
    g2.tabAdj = malloc(g.nbSom*sizeof(struct cel));
    g2.nbSom = g.nbSom;
    Liste lu;
    Liste ls;
    int u;
    int t;
    for (int s=0; s<g.nbSom; s++) {
        Liste l2 = initL();
        ls = g.tabAdj[s];
        while (!estVide(ls)) {
            u = donnee(ls);
            ls = suivant(ls);
            lu = g.tabAdj[u];
            while (!estVide(lu)) {
                t = donnee(lu);
                l2 = inserTrie(t, l2);
                lu  = suivant(lu);
            }
        }
        g2.tabAdj[s] = l2;
    }
    return g2;
}