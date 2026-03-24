#include "../include/prototypeTD7.h"
#include "../include/prototypeTD12.h"

#define INFINI 1000

/**
 * Algorithme de Ford.
 * Il sert à déterminer le plus cours chemin depuis un sommet vers tous les sommets du graphe.
 * La particularité de Ford est qu'il n'optimise rien et parcours sans cesse jusqu'à avoir optimisé les chemins.
 * Il fonctionne tout le temps, mais est lent.
 * @param sd Le sommet de départ.
 * @param g Le graphe.
 * @param type Le type de representation du graphe.
 * @param D Le tableau des couts, chaque indice t indique le coût pour arriver à t depuis @param sd
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
 * Cependant, il ne traite pas les graphes avec des sommets négatifs.
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

/**
 * Algorithme de Bellman-Ford.
 * Il sert à trouver le plus court chemin entre un sommet et tous les autres sommets.
 * À chaque itération, il vérifie dans M quel sommet n'a AUCUN prédécesseur présent aussi dans M.
 * Cela lui permet de traiter chaque sommet en prenant compte du dernier coût enregistré pour arriver à ses prédesseceurs.
 * @param sd Le sommet de départ.
 * @param g Le graphe de réprésentation quelconque.
 * @param type Le type du graphe.
 * @param D Le tableau des coûts.
 * @param P Le tableau des prédécesseurs.
 */
void bellman(int sd, void* g, TypeGraphe type, int* D, int* P) {
    // Initialisation
    int n = nbSomGen(g, type);
    int* deg = malloc(n * sizeof(int)); // Tableau des degrés entrants
    File M = initL();                       // File des sommets avec un degré entrant de 0
    for (int s=0; s<n; s++) {
        deg[s] = getNbPred(s, g, type);
        if (deg[s] == 0) {
            M = inserQueue(s, M);
        }
        D[s] = INFINI;
        P[s] = -1;
    }
    D[sd] = 0;
    P[sd] = sd;

    // Traitement
    int t, tmp;
    while (!estVide(M)) {
        t = donnee(M);
        M = suppTete(M);
        int* pred = getPredByType(t, type, g);
        for (int s=1; s<pred[0]+1; s++) {
            tmp = D[pred[s]] + cout(pred[s], t, g, type);
            if (tmp < D[t]) {
                D[t] = tmp;
                P[t] = pred[s];
            }
        }

        // Mise à jour
        int* succ = getSuccByType(t, type, g);
        for (int s=1; s<succ[0]+1; s++) {
            deg[succ[s]]--;
            if (deg[succ[s]] == 0) {
                M = inserQueue(succ[s], M);
            }
        }
    }
}

/**
 * Algorithme de Floyd
 * @param g Le graphe
 * @param type Le type de représentation
 * @param D La matrice des coûts
 * @param P La matrice des prédécesseurs
 */
void floyd(void* g, TypeGraphe type, int** D, int** P) {
    // Initialisation
    int n = nbSomGen(g, type);
    for (int s=0; s<n; s++) {
        for (int t=0; t<n; t++) {
            D[s][t] = cout(s, t, g, type);
        }
    }
}