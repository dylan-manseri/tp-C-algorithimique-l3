#include <stdio.h>
#include <stdlib.h>

#include "../include/prototypeTD12.h"

int nbSomGen(void* g, TypeGraphe type) {
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        return mat->nbSom;
    }
    else if (type == MAT_INCIDENCE) {
        MatIncidence* mat = (MatIncidence*) g;
        return mat->nbSom;
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* file = (FileSuccesseur*) g;
        return file->nbSom;
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* liste = (ListeAdjacence*) g;
        return liste->nbSom;
    }
    else {
        printf("\n Erreur de type");
        exit(1);
    }
}

int nbSomMA(MatAdjacence ma) {
    return ma.nbSom;
}