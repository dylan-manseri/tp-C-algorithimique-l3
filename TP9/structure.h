#ifndef TP9_STRUCTURE_H
#define TP9_STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int taille;
    int tailleMax;
    int *tab;
}ArbreParfait;

int taille(ArbreParfait a);
int tailleMax(ArbreParfait a);

ArbreParfait initAP(ArbreParfait a);
int estVideAP(ArbreParfait a);
int estPleinAP(ArbreParfait a);
int estExistNoeudAP(int nd, ArbreParfait a);
int donneeAP(int nd, ArbreParfait a);
int pereNoeudAP(int nd, ArbreParfait a);
int filsGaucheAP(int nd, ArbreParfait a);
int filsDroitAP(int nd, ArbreParfait a);
int estFeuilleAP(int nd, ArbreParfait a);
void parcoursPrefixeAP(int racine, ArbreParfait a);
void parcoursInfixeAP(int racine, ArbreParfait a);
void parcoursPostfixeAP(int racine, ArbreParfait a);
void parcoursLargeurAP(int racine, ArbreParfait a);


#endif //TP9_STRUCTURE_H