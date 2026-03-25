//
// Created by dylanm on 25/03/2026.
//

#ifndef TD_GRAPHES_PROTOTYPETD8_H
#define TD_GRAPHES_PROTOTYPETD8_H

#include <stdio.h>
#include "structure.h"

int estCheminSimple(int S, int P, int** g, int n, int* visite, int* parent);
int** createGrapheEcart(MatAdjacence g);
int capaciteResiduelle(int S, int P, int** ge, int* parent);
int fordFulKersun(int S, int P, MatAdjacence g);

#endif //TD_GRAPHES_PROTOTYPETD8_H