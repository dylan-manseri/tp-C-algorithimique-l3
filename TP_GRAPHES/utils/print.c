#include "../include/structure.h"

// Fonction d'écriture pour chaque structure, afin de pouvoir débugger !!

void printTab(int n, int* tab){
    printf("\n|");
    for(int l=0; l<n; l++){
        printf(" %d |", tab[l]);
    }
    printf("\n");
}

void printListe(Liste l) {
    printf("| ");
    while (!estVide(l)) {
        printf("%d | ", donnee(l)+1);
        l=suivant(l);
    }
}

void printLA(ListeAdjacence la) {
    for (int i=0; i<la.nbSom; i++) {
        printf("%d : ", i+1);
        printListe(la.tabAdj[i]);
        printf("\n");
    }
}

void printFS(FileSuccesseur fs) {
    printf("FS : | ");
    for (int i=0; i<fs.nbArcs; i++) {
        printf("%d | ", fs.FS[i]+1);
    }
    printf("\nAPS : | ");
    for (int j=0; j<fs.nbSom; j++) {
        printf("%d | ", fs.APS[j]);
    }
    printf("\n");
}

void printLS(ListeSucc ls) {
    printf("| ");
    while (!estVideLS(ls)) {
        printf("%d | ", donneeLS(ls)+1);
        ls=suivantLS(ls);
    }
    printf("\n");
}

void printLP(ListePred lp) {
    printf("| ");
    while (!estVideLP(lp)) {
        printf("%d | ", donneeLP(lp)+1);
        lp=suivantLP(lp);
    }
    printf("\n");
}

void printLSP(ListeAdjSuccPred lsp) {
    for (int i=0; i<lsp.nbSom; i++) {
        printf("---------------\n");
        printf("%d\nSuccesseur : ", i+1);
        printLS(lsp.tabAdjSP[i].lSucc);
        printf("Predecesseur : ");
        printLP(lsp.tabAdjSP[i].lPred);
    }
}