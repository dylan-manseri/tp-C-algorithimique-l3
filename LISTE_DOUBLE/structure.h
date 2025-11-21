#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef LISTE_DOUBLE_STRUCTURE_H
#define LISTE_DOUBLE_STRUCTURE_H
typedef struct {
    double coef;
    int degre;
}Monome;

typedef struct cellule {
    Monome monome;
    struct cellule *suivant;
    struct cellule *precedent;
}*Polynome;

typedef struct {
    Polynome tete;
    Polynome queue;
}PolynomeTQ;

int degre(Monome mon);
double coef(Monome mon);

Monome monome(Polynome p);
Polynome suivant(Polynome p);
Polynome precedent(Polynome p);
Polynome initP();
int estVideP(Polynome p);
Monome newMon(double coef, int degre);
void printPolynome(Polynome p);
#endif //LISTE_DOUBLE_STRUCTURE_H

#ifndef EXO_1
#define EXO_1
// PARTIE 1
Polynome allocMemRemp(Monome m);
Polynome inserTete(Monome m, Polynome p);
Polynome suppTete(Polynome p);
Polynome adresseInsertion(Monome m, Polynome p);
int zero(double d);
Polynome inserQueue(Monome m, Polynome der, Polynome p);
Polynome inserApres(Monome m, Polynome ai, Polynome p);
Polynome suppQueue(Polynome as, Polynome p);
Polynome suppAilleurs(Polynome ai, Polynome p);
Polynome inserMonPoly(Monome m, Polynome p);

Polynome rechMonPoly(Monome m, Polynome p);

Polynome suppMonPoly(Monome m, Polynome p);

Polynome delPolynome(Polynome p);

// PARTIE 2
double maxCoef(Polynome p);
double somCoef(Polynome p);
Polynome generPoly(int n, int *tab);
Polynome derivPoly(Polynome p);
Polynome somPoly(Polynome p1, Polynome p2);

#endif
