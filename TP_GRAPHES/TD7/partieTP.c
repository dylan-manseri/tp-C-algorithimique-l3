#include "../include/prototypeTD7.h"
#include "../include/prototypeTD12.h"

#define INFINI 1000

/**
 * Algorithme pour trouver le plus cours chemin entre un sommet et tous les autres.
 * @param s Le sommet de départ
 * @param g Le graphe
 * @param type Le type de représentation du graphe
 * @param D Le tableau des coûts
 * @param P Le tableau des prédécesseur
 */
void djikstra(int s, void* g, TypeGraphe type, int* D, int* P) {
    int n = nbSomGen(g, type);
    Liste M = NULL;
    for (int t=0; t<n; t++) {       // Le mieux est de le faire avec un Tas, mais je n'ai pas le temps là
        if (s!=t) {
            if (exist(s, t, g, type) ){
                D[t] = cout(s, t, g, type);
                P[t] = s;
            }
            else {
                D[t] = INFINI;
                P[t] = -1;
            }
            M = inserTrieeCout(t, M, D);
        }
    }
    int accessible = 1;
    int m;
    while (accessible && !estVide(M)) {
        m = donnee(M);
        if (D[m] == INFINI) {
            accessible = 0;
        }
        else {
            M = suppTete(M);
            int* succ = getSuccByType(m, type, g);
            int tmp;
            for (int t=1; t<succ[0]+1; t++) {
                tmp = D[m] + cout(m, succ[t], g, type);
                if (tmp < D[succ[t]]) {
                    D[succ[t]] = tmp;
                    P[succ[t]] = m;
                    M = suppEltCout(succ[t], M);
                    M = inserTrieeCout(succ[t], M, D);    // Mise à jour de la liste
                }
            }
        }
    }
}