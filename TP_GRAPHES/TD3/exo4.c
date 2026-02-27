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
        if (s > n) {
            s=0;
        }
    }
    return s;
}

int* getSuccByType(int s, TypeGraphe type) {
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
    return succ;
}

void reParcoursProfondeur(int s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite)  {
    if (*nbSomVisite < n) {
        visite[s] = 1;
        printf(" %d |", s+1);       // Traiter
        *nbSomVisite = *nbSomVisite+1;
        int* succ = getSuccByType(s, type);
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

void itParcoursLargeur(int s, int* visite, void* g, int n, int nbSomVisite, TypeGraphe type) {
    File f = initL();
    f = inserQueue(s, f);       // Enfiler
    int arret = 0;
    int u;
    while (!estVide(f) && !arret) {
        u = donnee(f);
        f = suppTete(f);
        if (!visite[u]) {
            visite[u] = 1;
            // Traiter
            nbSomVisite++;
            if (nbSomVisite == n) {
                arret = 1;
            }
            else {
                int* succ = getSuccByType(s, type);

            }
        }

    }
}

void parcoursLargeur(int sd, void* g, TypeGraphe type) {
    int n = nbSomGen(g, type);
    int* visite = allocTab(n);
    for (int i=0; i<n; i++) {
        visite[i] = 0;
    }
    int nbSomVisite = 0;
    int s = sd;
    int finParcours = 0;
    while (!finParcours) {
        itParcoursLargeur(s, visite, g, n, nbSomVisite, type);
        if (nbSomVisite < n) {
            s = somSuivant(s, n, visite);
        }
        else {
            finParcours = 1;
        }
    }
    visite = libTabF(visite);
}