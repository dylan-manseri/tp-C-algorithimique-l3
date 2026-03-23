#include "../include/prototypeTD7.h"
#include "../include/prototypeTD12.h"

#define INFINI 1000

/**
 * Algorithme de Ford.
 * Il sert à déterminer le plus cours chemin depuis un sommet vers tous les sommets du graphe.
 * La particularité de Ford est qu'il n'optimise rien et parcours sans cesse jusqu'à avoir optimiser les chemins.
 * Il fonctionne tout le temps mais est lent.
 * @param sd Le sommet de départ.
 * @param g Le graphe.
 * @param type Le type de representation du graphe.
 * @param D Le tableau des cout, chaque indice t indique le coût pour arriver à t depuis @param sd
 * @param P Le tableau des prédécesseurs, chaque indice t indique le prédécesseur de t de ce chemin.
 */
void ford(int sd, void* g, TypeGraphe type, int* D, int* P) {
    D[sd] = 0;
    P[sd] = sd;
    int n = nbSomGen(g, type);
    for (int s=0; s<n; s++) {
        if (s!=sd) {
            D[s] = INFINI;
            P[s] = -1;
        }
    }
    int modif, tmp, *succ;
    do {
        modif = 0;
        for (int s=0; s<n; s++) {
            succ = getSuccByType(s, type, g);
            for (int t=1; t<succ[0]+1; t++) {
                tmp = D[s] + cout(s, succ[t], g, type);
                if (tmp < D[succ[t]]) {
                    D[succ[t]] = tmp;
                    P[succ[t]] = s;
                    modif = 1;
                }
            }
        }
    } while (modif);
}

/**
 * Algorithme de Dijkstra.
 * Il sert à trouver le plus cours chemin entre un sommet et tous les autres.
 * La particularité de Dijkstra est qu'il parcourt les sommets selon leur coût.
 * En effet, il ne parcourt pas en boucle tous les sommets comme Ford, il choisit.
 * Cependant il ne traite pas les graphes avec des sommets négatifs.
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

void bellman(int sd, void* g, TypeGraphe type, int* D, int* P) {
    // Pour M on peut prendre l'ordre du tri topologique
}