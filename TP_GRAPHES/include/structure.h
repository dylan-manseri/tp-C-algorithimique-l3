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

typedef enum{
    MAT_ADJACENCE,
    MAT_INCIDENCE
}TypeMatrice;

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

/**
 * La structure liste successeur et prédécesseur
 */
typedef struct celluleSucc{     // C'est vraiment juste des listes hein
    int somSucc;
    struct celluleSucc* suivSucc;
}*ListeSucc;

typedef struct cellulePred{
    int somPred;
    struct cellulePred* suivPred;
}*ListePred;

typedef struct{
    ListeSucc lSucc;
    ListePred lPred;
}ListeSuccPred;

typedef struct{
    int nbSom;
    ListeSuccPred *tabAdjSP;
}ListeAdjSuccPred;

int nbSom(MatAdjacence m);

int estVide(Liste l);
int estVideLS(ListeSucc ls);
int estVideLP(ListePred lp);
int donnee(Liste l);
int donneeLP(ListePred lp);
int donneeLS(ListeSucc ls);
Liste suivant(Liste l);
ListePred suivantLP(ListePred lp);
ListeSucc suivantLS(ListeSucc ls);
Liste inserTete(int donnee, Liste l);
ListePred inserTeteLP(int somPred, ListePred lp);
ListeSucc inserTeteLS(int somSucc, ListeSucc ls);
Liste adrDernier(Liste l);
ListePred adrDernierLP(ListePred lp);
ListeSucc adrDernierLS(ListeSucc ls);
Liste inserQueue(int donnee, Liste l);
ListePred inserQueueLP(int somPred, ListePred lp);
ListeSucc inserQueueLS(int somSucc, ListeSucc ls);
Liste initL();
ListeSucc initLS();
ListePred initLP();

ListeAdjacence initLA(int nbSom);

MatAdjacence allocSMA_F(int n);
void allocSMA_P(int n, MatAdjacence *ma);
void *libTabF(int *tab);
void libTabP(int **tab);
void *libMatF(int **mat, int nbLig);
void libMatP(int ***mat, int nbLig);
MatAdjacence libMatAdjF(MatAdjacence mat);
void libMatAdjP(MatAdjacence *mat);
void allocLA(int n, ListeAdjacence* la);
void allocFS(int n, int nbArcs, FileSuccesseur* fs);
void allocLSP(int n, ListeAdjSuccPred* lsp);
MatIncidence alloc_SMI_F(int nbSom, int nbArcs);

MatAdjacence loading(char* nom);

void traitSuccMatAdj(int s, MatAdjacence g);
void traitPredMatAdj(int s, MatAdjacence g);
void traitSuccFS(int s, FileSuccesseur fs);
void traitPredFS(int s, FileSuccesseur fs);
void traitSuccL(int s, ListeAdjacence la);
void traitPredL(int s, ListeAdjacence la);

void printTab(int n, int* tab);
void printListe(Liste l);
void printLA(ListeAdjacence la);
void printFS(FileSuccesseur fs);
void printLS(ListeSucc ls);
void printLP(ListePred lp);
void printLSP(ListeAdjSuccPred lsp);
void printMat(void* mat, TypeMatrice type);
//void printMat(MatAdjacence mat);

int estBoucleMA(MatAdjacence ma);
int estBoucleFS(FileSuccesseur fs);
int estBoucleLA(ListeAdjacence la);

int maxSuccMA(MatAdjacence ma);
int maxSuccFS(FileSuccesseur fs);
int maxSuccLA(ListeAdjacence la);

ListeAdjacence convertMAtoLA(MatAdjacence ma);
int countArc(MatAdjacence ma);
FileSuccesseur convertMAtoFS(MatAdjacence ma);
ListeAdjSuccPred convertMAtoLSP(MatAdjacence ma);
ListeAdjacence convertFStoLA(FileSuccesseur fs);
FileSuccesseur convertLAtoFS(ListeAdjacence la);
MatIncidence convertMAtoMI(MatAdjacence ma);

#endif