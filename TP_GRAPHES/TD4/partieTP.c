#include <stdio.h>
#include <stdlib.h>

#include "../include/prototypeTD4.h"
#include "../include/prototypeTD3.h"

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

/**
 * On veut verifier si un graphe est Biparti.
 * On marque les successeurs d'un sommet d'un niveau+1 que le sien.
 * On les marque via un parcours en largeur.
 * À la fin les sommets marqué pair et impair forment deux groupes.
 * @param g Le graphe
 * @param type Le type du graphe
 * @return Le tableau de marquage
 */
int* marquagePL(void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* visite = allocTab(n);
    for (int i=0; i<n; i++) {
        visite[i] = 0;
    }
    int* marquage = allocTab(n);
    int nbSomVisite = 0;
    int s = 0;
    marquage[s] = 0;
    int u;
    // Parcours en largeur à partir du sommet
    File f = initL();
    f = inserQueue(s, f);
    while (!estVide(f) && nbSomVisite < n) {
        u = donnee(f);
        f = suppTete(f);
        if (!visite[u]) {
            nbSomVisite++;
            visite[u] = 1;
            int* succ = getSuccByType(u, type, g);
            for (int i=1; i<succ[0]+1; i++) {
                if (!visite[i]) {
                    f = inserQueue(succ[i], f);
                    marquage[succ[i]] = marquage[u]+1;
                }
            }
        }
    }
    while (!estVide(f)) {
        f = suppTete(f);
    }
    visite = libTabF(visite);
    free(visite);
    return marquage;
}

/**
 * On a notre tableau de marquage.
 * On regarde pour chaque sommet, quel est son groupe.
 * Pair → groupe 1
 * Impair → groupe 2
 * @param n Le nombre de sommet
 * @param marquage Le tableau des marquages indicé par le sommet
 * @param s1 Liste des sommets du groupe 1
 * @param s2 Liste des sommets du groupe 2
 */
void partition(int n, int* marquage, Liste* s1, Liste* s2) {
    *s1 = initL();
    *s2 = initL();
    for (int i=0; i<n; i++) {
        if (marquage[i]%2 == 0) {   // C'est pair
            *s1 = inserTete(i, *s1);
        }
        else {
            *s2 = inserTete(i, *s2);  // C'est impair
        }
    }
}

/**
 * On a nos deux groupes de sommets.
 * On veut vérifier qu'ils n'ont des relations qu'en dehors de leur groupe
 * @param group La liste de sommet
 * @param type Le type du graphe
 * @param g Le graphe
 * @return Un booléen, soit il y a un lien soit il n'y en a pas.
 */
int estLiaison(Liste group, TypeGraphe type, void* g) {
    int estLien = 0;
    int* succ;
    while (!estVide(group) && !estLien) {
        succ = getSuccByType(donnee(group), type, g);
        int i = 1;
        while (!estLien && i<succ[0]+1) {
            if (contain(succ[i], group)) {
                estLien = 1;
            }
            i++;
        }
        group = suivant(group);
    }
    return estLien;
}

/**
 * Fonction final regroupant le déroulement des autres.
 * Etape 1 : On marque les sommets via un parcours en largeur.
 * Etape 2 : On sépare nos deux groupes de sommets pair et impair.
 * Etape 3 : On vérifie qu'il n'y ai pas de lien entre un groupe et lui-même.
 * @param g Le graphe
 * @param type Le type du graphe
 * @return Un booléen, soit il est biparti, soit il ne l'est pas.
 */
int estBiparti(void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* marquage = marquagePL(g, type);
    Liste s1, s2;
    partition(n, marquage, &s1, &s2);
    int estBiparti = !estLiaison(s1, type, g) && !estLiaison(s2, type, g);
    return estBiparti;
}