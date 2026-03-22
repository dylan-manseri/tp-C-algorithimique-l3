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

int coutMA(int s, int t, MatAdjacence ma) {
    return ma.cout[s][t];
}

int coutMI(int s, int t, MatIncidence mi) {
    return mi.cout[s][t];
}

int coutFS(int s, int t, FileSuccesseur fs) {
    int i = fs.APS[s];
    while (fs.FS[i] != t) {
        i++;
    }
    return fs.cout[i];
}

int coutLA(int s, int t, ListeAdjacence la) {
    Liste l = la.tabAdj[s];
    while (donnee(l) != t) {
        l = suivant(l);
    }
    return l->cout;
}

int cout(int s, int t, void* g, TypeGraphe type) {
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        return coutMA(s, t, *mat);
    }
    else if (type == MAT_INCIDENCE) {
        MatIncidence* mat = (MatIncidence*) g;
        return coutMI(s, t, *mat);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* file = (FileSuccesseur*) g;
        return coutFS(s, t, *file);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* liste = (ListeAdjacence*) g;
        return coutLA(s, t, *liste);
    }
    else {
        printf("\n Erreur de type");
        exit(1);
    }
}

int existMA(int s, int t, MatAdjacence ma) {
    return ma.mat[s][t] == 1;
}

int existMI(int s, int t, MatIncidence mi) {
    return mi.mat[s][t] == 1;
}

int existFS(int s, int t, FileSuccesseur fs) {
    int iaps = fs.APS[s];
    int n = fs.APS[s+1] - fs.APS[s];
    int exist = 0;
    while (!exist && iaps<n) {
        if (fs.FS[iaps] == t) {
            exist = 1;
        }
        iaps++;
    }
    return exist;
}

int existLA(int s, int t, ListeAdjacence la) {
    Liste l = la.tabAdj[s];
    int exist = 0;
    while (!exist && !estVide(l)) {
        if (donnee(l) == t) {
            exist = 1;
        }
        l = suivant(l);
    }
    return exist;
}

int exist(int s, int t, void* g, TypeGraphe type) {
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        return existMA(s, t, *mat);
    }
    else if (type == MAT_INCIDENCE) {
        MatIncidence* mat = (MatIncidence*) g;
        return existMI(s, t, *mat);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* file = (FileSuccesseur*) g;
        return existFS(s, t, *file);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* liste = (ListeAdjacence*) g;
        return existLA(s, t, *liste);
    }
    else {
        printf("\n Erreur de type");
        exit(1);
    }
}


int nbSomMA(MatAdjacence ma) {
    return ma.nbSom;
}