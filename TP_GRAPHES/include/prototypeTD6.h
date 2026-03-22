#include <stdio.h>


#ifndef TD_GRAPHES_PROTOTYPETD6_H
#define TD_GRAPHES_PROTOTYPETD6_H

#include "structure.h"

int estVideMA(MatAdjacence ma);
int estVideFS(FileSuccesseur fs);
int estVideLA(ListeAdjacence la);
int estVideGraphe(void* g, TypeGraphe type);

int degreEntrantMA(MatAdjacence ma, int t);
int degreEntrantFS(FileSuccesseur fs, int t);
int degreEntrantLA(ListeAdjacence la, int t);
int degreEntrant(void* g, TypeGraphe type, int t);

File triTopologiqueAcyclique(void* g, TypeGraphe type);

int mainTD6();
#endif //TD_GRAPHES_PROTOTYPETD6_H