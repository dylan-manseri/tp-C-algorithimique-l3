/**
 *Fichier regroupant toutes les allocations et libération des structures (y'en a bcp)
 *Pas toutes ces allocations sont dans le TP, j'en ai rajouté
 */

#include "../include/structure.h"

int* allocTab(int nMax) {
    int* tab = malloc(nMax * sizeof(int));
    if (tab==NULL) {
        printf("Erreur d'allocation");
        exit(1);
    }
    return tab;
}

void allocTabP(int nMax, int **tab) {
    *tab = (int*) malloc(nMax * sizeof(int));
    if (*tab == NULL) {
        printf("Erreur d'allocation");
        exit(1);
    }
}

int** allocMemMatF(int nbLig, int nbCol) {
    int **mat = malloc(nbLig * sizeof(int*));   // Un pointeur vers la premiere ligne du tableau qui est un pointeur
    if (mat == NULL) {
        printf("Erreur d'allocation");
        exit(1);
    }
    for (int i=0; i<nbLig; i++) {
        mat[i] = allocTab(nbCol);                           // On alloue ensuite chaque ligne du tableau
        if (mat[i] == NULL) {
            printf("Erreur d'allocation");
            exit(1);
        }
    }
    return mat;
}

/*
 * ***mat est de type int -> c'est le premier elt de la premiere ligne
 * **mat est de type *int -> c'est le pointeur de la premiere ligne
 * *mat est de type **int -> contenu de la matrice
 * mat est de type ***int -> pointeur vers la matrice passé en paramètre
 */
void allocMemMatP(int nbLig, int nbCol, int ***mat) {
    *mat = malloc(nbLig * sizeof(int*));
    if (*mat == NULL) {
        printf("Erreur d'allocation");
        exit(1);
    }
    for (int i=0; i<nbLig; i++) {
        *mat[i] = allocTab(nbCol);
        if (mat[i] == NULL) {
            printf("Erreur d'allocation");
            exit(0);
        }
    }
}

MatAdjacence allocSMA_F(int n) {
    MatAdjacence mat;
    mat.nbSom = n;
    mat.mat = allocMemMatF(n,n);
    return mat;
}

void allocSMA_P(int n, MatAdjacence *mat) {
    mat->nbSom = n;
    mat->mat = allocMemMatF(n, n);
}

void allocLA(int nbSom, ListeAdjacence* la){
    la->nbSom = nbSom;
    la->tabAdj = malloc(la->nbSom * sizeof(struct cel));
    for(int i=0; i<nbSom; i++){
        la->tabAdj[i] = initL();
    }
}

void allocFS(int n, int nbArcs, FileSuccesseur* fs) {
    fs->nbArcs = nbArcs;
    fs->nbSom = n;
    fs->APS = malloc(n+1 * sizeof(int));
    fs->FS = malloc(nbArcs+1 * sizeof(int));
}

void allocLSP(int n, ListeAdjSuccPred* lsp) {
    lsp->nbSom = n;
    lsp->tabAdjSP = malloc(n * sizeof(ListeSuccPred));
    for (int i=0; i<n; i++) {
        lsp->tabAdjSP[i].lPred = initLP();
        lsp->tabAdjSP[i].lSucc = initLS();
    }
}

void *libTabF(int *tab) {
    free(tab);
    tab=NULL;
    return tab;
}

void libTabP(int **tab) {
    free(*tab);
    *tab = NULL;
}

void *libMatF(int **mat, int nbLig) {
    for (int i=0; i<nbLig; i++) {
        free(mat[i]);
    }
    free(mat);
    mat = NULL;
    return mat;
}

void libMatP(int ***mat, int nbLig) {
    for (int i=0; i<nbLig; i++) {
        free(*mat[i]);
    }
    free(*mat);
    *mat = NULL;
}

MatAdjacence libMatAdjF(MatAdjacence mat) {
    mat.mat = libMatF(mat.mat, mat.nbSom);
    mat.nbSom = 0;
    return mat;
}

void libMatAdjP(MatAdjacence *mat) {
    mat->mat = libMatF(mat->mat, mat->nbSom);
    mat->nbSom = 0;
}

void printMat(MatAdjacence mat) {
    for (int i=0; i<mat.nbSom; i++) {
        for (int j=0; j<mat.nbSom; j++) {
            printf("%d",mat.mat[i][j]);
        }
        printf("\n");
    }
}