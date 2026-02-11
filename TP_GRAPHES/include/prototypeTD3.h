#ifndef PROTOTYPETD3_H
#define PROTOTYPETD3_H

#include "structure.h"

int mainTD3(void);

int somSuivantMA(int s, int n, int* visite);
void reParcoursProfondeurMA(int s, int* visite, MatAdjacence mat, int n, int* nbSomVisite);
void parcoursProfondeurMA(int sd, MatAdjacence mat);

#endif