//
// Created by dylnm on 01/03/2026.
//

#ifndef TD_GRAPHES_PROTOTYPETD5_H
#define TD_GRAPHES_PROTOTYPETD5_H

#include "structure.h"

void reParcoursProfondeurCC(int *s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite, int* CC, int* nbCC);
int* getCC(void* g, TypeGraphe type);
void reParcoursProfondeurSuffixe(int s, Pile* p, int* nbSomVisite, void* g, int* visite, int n, TypeGraphe type);
void reParcoursProfondeurCFC_T(int s, int* nbSomVisite, void* g, int* visite, int n, int nbCFC, int* CFC, TypeGraphe type);
int* getCFC(void* g, TypeGraphe type);
void fermetureTransitive(void* g, TypeGraphe type, int** mat);

int mainTD5(void);

#endif //TD_GRAPHES_PROTOTYPETD5_H