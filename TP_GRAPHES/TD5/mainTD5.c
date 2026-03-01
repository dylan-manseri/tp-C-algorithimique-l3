#include <stdio.h>

#include "../include/prototypeTD5.h"
#include "../include/prototypeTD12.h"

int mainTD5(void) {
    MatAdjacence mat = loading("C://Users//dylnm//Insync//nalyd.irsnm@gmail.com//Google Drive//DrivePC//LICENCE INFORMATIQUE//L3 INFORMATIQUE//S6//Graphes et optimisation combinatoire//tp-code//TP_GRAPHES//graphe.txt");
    int* CC = getCC(&mat, MAT_ADJACENCE);
    int n = nbSomGen(&mat, MAT_ADJACENCE);
    printf("|");
    for (int i=0; i<n; i++) {
        printf(" %d |", CC[i]);
    }
    return 0;
}