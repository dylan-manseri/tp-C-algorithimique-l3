#include <stdio.h>
#include <stdlib.h>

#include "../include/prototypeTD12.h"
#include "../include/prototypeTD3.h"
#include "../include/prototypeTD4.h"
#include "../include/prototypeTD5.h"

/**
 * Algorithme de parcours en profondeurs (cf. TD4) adapté à la recherche de composantes connexes.
 * Chaque appel INITIAL (cad ceux non récursif) traite UNE composante connexe
 * @param s Le sommet en cours
 * @param visite Le tableau des visite indicé par le sommet
 * @param g Le graphe
 * @param type Le type du graphe
 * @param n Le nombre de sommets
 * @param nbSomVisite Le nombre de sommets visités
 * @param CC Le tableau des composantes connexes indicé par le sommets
 * @param nbCC Le numéro de la composante connexe actuel (ou le nombre de CC, on peut le voir des deux façons)
 */
void reParcoursProfondeurCC(int *s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite, int* CC, int* nbCC)  {
    if (*nbSomVisite < n) {
        visite[*s] = 1;
        CC[*s] = *nbCC;     // On indique le numéro de la composante connexe du sommet actuel
        *nbSomVisite = *nbSomVisite+1;
        int* succ = getSuccByType(*s, type, g);
        for (int i=1; i<succ[0]+1; i++) {
            if (!visite[succ[i]]) {
                *s = succ[i];
                reParcoursProfondeurCC(s, visite, g, type, n, nbSomVisite, CC, nbCC);
            }
        }
    }
}

/**
 * Un graphe est connexe si pour tout (u,v) il existe un chemin entre u et v.
 * On parcours en profondeur depuis un sommet de départ.
 * L'ensembles des sommets rencontré représente une composante connexe.
 * On réitère pour chaque sommet non visité.
 * @param g
 * @param type
 * @return
 */
int* getCC(void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* visite = allocTab(n);      // Tableau de visite du parcours
    int* CC = allocTab(n);          // Tableau indicé par le sommet indiquant le numéro de la CC du sommet
    for (int i=0; i<n; i++) {
        visite[i] = 0;
    }
    int nbSomVisite = 0;
    int nbCC = 1;
    int finParcours = 0;
    int s = 0;
    while (!finParcours) {
        reParcoursProfondeurCC(&s, visite, g, type, n, &nbSomVisite, CC, &nbCC);
        if (nbSomVisite < n) {      // Si on a pas tous visité, il reste des CCs.
            s = somSuivant(s, n, visite);
            nbCC++;                 // On augmente le nombre pour préparer le prochain parcours.
        }
        else {
            finParcours = 1;
        }
    }
    visite = libTabF(visite);
    free(visite);
    return CC;
}