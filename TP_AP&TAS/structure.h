#ifndef TP_ARBRES_STRUCTURE_H
#define TP_ARBRES_STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int taille;
    int tailleMax;
    int *tab;
}ArbreParfait;

int taille(ArbreParfait a);
int tailleMax(ArbreParfait a);

ArbreParfait initAP(ArbreParfait a);
ArbreParfait allocMemAP(ArbreParfait a, int tMax);
int estVideAP(ArbreParfait a);
int estPleinAP(ArbreParfait a);
int estExistNoeudAP(int nd, ArbreParfait a);
int donneeAP(int nd, ArbreParfait a);
int pereNoeudAP(int nd, ArbreParfait a);
int filsGaucheAP(int nd, ArbreParfait a);
int filsDroitAP(int nd, ArbreParfait a);
int estFeuille(int nd, ArbreParfait a);
void parcoursPrefixeAP(int racine, ArbreParfait a);
void parcoursInfixeAP(int racine, ArbreParfait a);
void parcoursPostfixeAP(int racine, ArbreParfait a);
void parcoursLargeurAP(int racine, ArbreParfait a);
void parcoursLargeurParNiveau(ArbreParfait a, int n);
void parcoursArbreParfaitNiveauPlein(ArbreParfait a);
ArbreParfait inserEltAP(int elt, ArbreParfait a);
ArbreParfait constAP();


#endif

#ifndef TP_TAS_STRUCTURE_H
#define TP_TAS_STRUCTURE_H
typedef ArbreParfait Tas;

int sommetTas(Tas t);
Tas inserTas(int elt, Tas t);
Tas recInserTas(int elt, int n, Tas t);
Tas suppTas(Tas t);
Tas recSuppTas(Tas t);
Tas recSuppTasBis(int elt, int r, int fg, Tas t);
int max(int a, int b);
int estTasVer1(int n, ArbreParfait a);
int estTasVer2(int n, ArbreParfait a);
int recEstTasVer1(int n, ArbreParfait a);
int recEstTasVer2(int n, int r, ArbreParfait a);
Tas convertTabtoTas(int n, int *tab);
Tas recConvertTabToTas(int n, ArbreParfait tas, int *tab);
void triParTas(int n, int *tab);

#endif
