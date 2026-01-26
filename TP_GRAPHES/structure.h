#ifndef TP1_2
#define TP1_2

#include <stdio.h>
#include <stdlib.h>

int* allocTab(int nMax);
void allocTabP(int nMax, int **tab);
int** allocMemMatF(int nbLig, int nbCol);
void allocMemMatP(int nbLig, int nbCol, int*** mat);

typedef struct {
    int nbSom;
    int **mat;
}MatAdjacence;

typedef struct {
    int nbSom;
    int nbArc;
    int **mat;
}MatIncidence;

typedef struct{
    int nbSom;
    int nbArcs;
    int *FS;
    int *APS;
}FileSuccesseur;

typedef struct cel{
    int donnee;
    struct cel* suivant; 
}*Liste;

typedef struct{
    int nbSom;
    Liste *tabAdj;
}ListeAdjacence;

int nbSom(MatAdjacence m);

int estVide(Liste l);
int donnee(Liste l);
Liste suivant(Liste l);
Liste inserTete(int donnee, Liste l);
Liste adrDernier(Liste l);
Liste inserQueue(int donnee, Liste l);
Liste initL();

ListeAdjacence initLA(int nbSom);

MatAdjacence allocSMA_F(int n);
void allocSMA_P(int n, MatAdjacence *ma);
void *libTabF(int *tab);
void libTabP(int **tab);
void *libMatF(int **mat, int nbLig);
void libMatP(int ***mat, int nbLig);
MatAdjacence libMatAdjF(MatAdjacence mat);
void libMatAdjP(MatAdjacence *mat);

MatAdjacence loading(char* nom);
void printMat(MatAdjacence mat);

void traitSuccMatAdj(int s, MatAdjacence g);
void traitSuccFS(int s, FileSuccesseur fs);
void traitSuccL(int s, ListeAdjacence la);


#endif


