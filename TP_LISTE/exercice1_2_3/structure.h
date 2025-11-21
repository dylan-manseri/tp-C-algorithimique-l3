#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int fact;
    int nbOcc;
}FactPremier;

typedef struct cellule {
    FactPremier donnee;
    struct cellule *suivant;
}*Liste;

typedef struct {
    int nbr;
    Liste ldfp;
}TabLDFP;

int fact(FactPremier f);
int nbOcc(FactPremier f);
FactPremier donnee(Liste l);
Liste suivant(Liste l);
Liste createListe();
FactPremier createFactPremier(int fact, int nbOcc);
TabLDFP createTabLDFP(int nbr, Liste l);
int nombre(TabLDFP cel);
Liste liste(TabLDFP cel);

int estVide(Liste l);
Liste adrDernier(Liste l);
Liste inserTete(FactPremier fp, Liste l);
Liste inserQueue(FactPremier fp, Liste l);
void printFactPremier(FactPremier fp);
void printListe(Liste l);
void printTabLDFP(TabLDFP* tab, int taille);

#endif

#ifndef EXO1_H
#define  EXO1_H

int estPremier(int nbr);
int nbrDivision(int *nbr, int p);
Liste decomposition(int nbr, Liste l);

TabLDFP* convertTabToListe(int *tab, int taille);

int minimum(int a, int b);
int puissance(int nbr, int exp);
Liste intersection(Liste l1, Liste l2);
int pgcd(int* tab, int n);

#endif


