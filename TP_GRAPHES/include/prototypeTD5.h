//
// Created by dylnm on 01/03/2026.
//

#ifndef TD_GRAPHES_PROTOTYPETD5_H
#define TD_GRAPHES_PROTOTYPETD5_H

#include "structure.h"

void reParcoursProfondeurCC(int *s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite, int* CC, int* nbCC);
int* getCC(void* g, TypeGraphe type);

int mainTD5(void);

#endif //TD_GRAPHES_PROTOTYPETD5_H