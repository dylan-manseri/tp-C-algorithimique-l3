#include "../include/prototypeTD3.h"
#include "../include/prototypeTD12.h"
#include <stdio.h>

int somSuivantMA(int s, int n, int* visite) {
    int trouve = 0;
    while (!trouve) {
        if (visite[s] != 1) {
            trouve = 1;
        }
        s++;
    }
    return s;
}

void reParcoursProfondeurMA(int s, int* visite, MatAdjacence mat, int n, int* nbSomVisite)  {
    if (*nbSomVisite < n) {
        visite[s] = 1;
        printf(" %d |", s+1);
        *nbSomVisite = *nbSomVisite+1;
        int* succ = getSuccMatAdj(s, mat);
        for (int i=1; i<succ[0]; i++) {
            if (!visite[i]) {
                reParcoursProfondeurMA(i, visite, mat, n, nbSomVisite);
            }
        }
    }
}

void parcoursProfondeurMA(int sd, MatAdjacence mat) {
    int n = mat.nbSom;
    int* visite = allocTab(mat.nbSom);
    for (int s=0; s<mat.nbSom; s++) {
        visite[s] = 0;
    }
    int s =sd;
    int nbSomVisite = 0;
    int finParcours = 0;
    printf("Sommets rencontrés : |");
    while (!finParcours) {
        reParcoursProfondeurMA(s, visite, mat, n, &nbSomVisite);
        if (nbSomVisite < mat.nbSom) {
            s = somSuivantMA(s, n, visite);
        }
        else {
            finParcours = 1;
        }
    }
}