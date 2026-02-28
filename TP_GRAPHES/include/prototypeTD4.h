//
// Created by dylanm on 14/02/2026.
//

#ifndef TD_GRAPHES_PROTOTYPETD4_H
#define TD_GRAPHES_PROTOTYPETD4_H

#include "prototypeTD12.h"
#include "structure.h"

MatAdjacence getCarreMA(MatAdjacence g);
ListeAdjacence getCarreLA(ListeAdjacence g);

int* marquagePL(void* g, TypeGraphe type);
void partition(int n, int* marquage, Liste* s1, Liste* s2);
int estLiaison(Liste group, TypeGraphe type, void* g);
int estBiparti(void* g, TypeGraphe type);
int mainTD4(void);

#endif //TD_GRAPHES_PROTOTYPETD4_H