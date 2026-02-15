//
// Created by dylanm on 10/02/2026.
//

#ifndef PROTOTYPETD12_H
#define PROTOTYPETD12_H

#include "structure.h"

int nbSomGen(void* g, TypeGraphe type);
int nbSomMA(MatAdjacence mat);

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
Liste adrInsert(int donnee, Liste l);
Liste inserQueue(int donnee, Liste l);
ListePred inserQueueLP(int somPred, ListePred lp);
ListeSucc inserQueueLS(int somSucc, ListeSucc ls);
Liste inserTrie(int donnee, Liste l);
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

int* getSuccMatAdj(int s, MatAdjacence g);
int* getPredMatAdj(int s, MatAdjacence g);
int* getSuccFS(int s, FileSuccesseur fs);
int* getPredFS(int s, FileSuccesseur fs);
int* getSuccL(int s, ListeAdjacence la);
int* getPredL(int s, ListeAdjacence la);

void printTab(int n, int* tab);
void printListe(Liste l);
void printLA(ListeAdjacence la);
void printFS(FileSuccesseur fs);
void printLS(ListeSucc ls);
void printLP(ListePred lp);
void printLSP(ListeAdjSuccPred lsp);
void printMat(void* mat, TypeGraphe type);

int estBoucleMA(MatAdjacence ma);
int estBoucleFS(FileSuccesseur fs);
int estBoucleLA(ListeAdjacence la);

int maxSuccMA(MatAdjacence ma);
int maxSuccFS(FileSuccesseur fs);
int maxSuccLA(ListeAdjacence la);

ListeAdjacence convertMAtoLA(MatAdjacence ma);
int countArc(MatAdjacence ma);
int countArcLA(ListeAdjacence la);
FileSuccesseur convertMAtoFS(MatAdjacence ma);
ListeAdjSuccPred convertMAtoLSP(MatAdjacence ma);
ListeAdjacence convertFStoLA(FileSuccesseur fs);
FileSuccesseur convertLAtoFS(ListeAdjacence la);
MatIncidence convertMAtoMI(MatAdjacence ma);

int mainTD1_2(void);

#endif //TD1_2_PROTOTYPETD12_H