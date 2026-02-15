#ifndef PROTOTYPETD3_H
#define PROTOTYPETD3_H

#include "structure.h"

int mainTD3(void);

int somSuivant(int s, int n, int* visite);
void reParcoursProfondeur(int s, int* visite, void* g, TypeGraphe type, int n, int* nbSomVisite);
void parcoursProfondeur(int sd, void* g, TypeGraphe type);

#endif