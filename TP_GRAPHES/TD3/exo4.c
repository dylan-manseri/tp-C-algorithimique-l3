#include "../include/prototypeTD3.h"
#include "../include/prototypeTD12.h"
#include <stdio.h>
#include <stdlib.h>

int somSuivant(int s, int n, int* visite) {
    int trouve = 0;
    while (!trouve) {
        if (visite[s] != 1) {
            trouve = 1;
        }
        s++;
    }
    return s;
}

void reParcoursProfondeur(int s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite)  {
    if (*nbSomVisite < n) {
        visite[s] = 1;
        printf(" %d |", s+1);
        *nbSomVisite = *nbSomVisite+1;
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
        for (int i=1; i<succ[0]; i++) {
            if (!visite[i]) {
                reParcoursProfondeur(i, visite, g, type, n, nbSomVisite);
            }
        }
    }
}

void parcoursProfondeur(int sd, void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* visite = allocTab(n);
    for (int s=0; s<n; s++) {
        visite[s] = 0;
    }
    int s =sd;
    int nbSomVisite = 0;
    int finParcours = 0;
    printf("Sommets rencontrés : |");
    while (!finParcours) {
        reParcoursProfondeur(s, visite, g, type, n, &nbSomVisite);
        if (nbSomVisite < n) {
            s = somSuivant(s, n, visite);
        }
        else {
            finParcours = 1;
        }
    }
}