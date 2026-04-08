#include "../include/prototypeTD8.h"
#include "../include/prototypeTD12.h"

#define INFINI 1000;

/**
 * On veut trouver un chemin de sorte à ajouter du flux dans le graphe de flot (je ne sais pas si c'est clair)
 * Cet algorithme trouve un chemin dans un graphe.
 * Il utilise un parcours en largeur à l'aide d'une file.
 * @param S Le sommet de départ.
 * @param P Le sommet d'arrivée.
 * @param ge Le graphe d'écart.
 * @param n Le nombre de sommets.
 * @param visite Le tableau des visites indicé par les sommets.
 * @param parent Le tableau des parents indicé par les sommets.
 * @return Vrai si un chemin a été trouvé, faux sinon
 */
int estCheminSimple(int S, int P, int** ge, int n, int* visite, int* parent) {
    // Initialisation
    for (int s=0; s<n; s++) {
        parent[s] = -2;             // Aucun sommet n'a de parent
        visite[s] = 0;              // Aucun sommet n'est visité
    }
    int s = S;
    File f = initL();
    f = inserQueue(s, f);
    int arret = 0;
    int u, t;
    // Traitement
    while (!estVide(f) && !arret) {
        u = donnee(f);
        f = suppTete(f);
        if (!visite[u]) {
            visite[u] = 1;
            t = 0;
            while (t<n && !arret) {
                if (ge[u][t] > 0) {             // Si il existe un chemin u->t
                    if (!visite[t]) {
                        if (parent[t] == -2) {
                            parent[t] = u;
                        }
                        if (t == P) {               // Si on est arrivé, on arrête
                            arret = 1;
                        }
                        else {
                            f = inserQueue(t, f);   // Sinon, on enfile le sommet et rebelote
                        }
                    }
                }
                t++;
            }
        }
    }
    return arret;
}

/**
 * On copie colle notre matrice d'adjacence initiale sur une autre pour pouvoir traiter la copie.
 * @param g Le graphe a étudié sous sa forme de matrice d'adjacence.
 * @return Une matrice copier coller
 */
int** createGrapheEcart(MatAdjacence g) {
    int n = nbSomMA(g);
    int** ge = allocMemMatF(n, n);
    for (int s=0; s<n; s++) {
        for (int t=0; t<n; t++) {
            g.mat[s][t] = ge[s][t];
        }
    }
    return ge;
}

/**
 * On souhaite connaitre le flux minimal de tous les coûts d'un même chemin.
 * Cela nous permet de mettre à jour notre graphe d'écart avec une vraie valeur pour tous les flux possible dans ce même chemin.
 * @param S Le sommet de départ.
 * @param P Le sommet d'arrivée.
 * @param ge Le graphe d'écart.
 * @param parent Le tableau des parents.
 * @return Le flux minimal.
 */
int capaciteResiduelle(int S, int P, int** ge, int* parent) {
    int fMin = INFINI;
    int v = P;
    int u;
    do {
        u = parent[v];
        if (ge[u][v] < fMin) {      // On met à jour seulement si l'on trouve un flux plus petit.
            fMin = ge[u][v];
        }
        v = u;
    }while (v!=S);
    return fMin;
}

/**
 * Algorithme final AKA le boss final du module.
 * On cherche à calculer le flux maximal que l'on peut envoyer dans un graphe de S à P SANS DÉPASSER LA CAPACITÉ.
 * @param S Le sommet de départ.
 * @param P Le sommet d'arrivée.
 * @param g Le graphe représenté par sa matrice d'adjacence.
 * @return Le flux maximal
 */
int fordFulKersun(int S, int P, MatAdjacence g) {
    int n = nbSomMA(g);
    int* visite = allocTab(n);
    int* parent = allocTab(n);
    int** ge = createGrapheEcart(g);
    int fMin;
    int fMax = 0;
    int u, v;
    while (estCheminSimple(S, P, ge, n, visite, parent)) {      // Tant qu'un chemin existe dans le graphe d'écart
        // En même temps de nous dire si un chemin existe, la fonction met à jour le tableau parent pour le chemin trouvé (magnifique).
        fMin = capaciteResiduelle(S, P, ge, parent);            // On calcule le coût (s→t) minimale parmi tous ceux du chemin
        // C'est cette valeur qu'on va envoyer partout dans le chemin.
        fMax += fMin;
        v = P;
        do {
            u = parent[v];
            ge[u][v] = ge[u][v] - fMin;         // On envoie un flux, donc on supprime la quantité envoyée.
            ge[v][u] = ge[v][u] + fMin;         // Et on ajoute le flux qu'on a envoyé à l'inverse, car on l'a envoyé (on peut plus le réenvoyer)
            v = u;
        }while (v!=S);
    }
    visite = libTabF(visite);
    parent = libTabF(parent);
    return fMax;
}