#ifndef STRUCTURE_CIRCULAIRE_H
#define STRUCTURE_CIRCULAIRE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int elt;
    struct cel *suivant;
}*ListeC;

typedef struct {
    int taille;
    ListeC tete;
    ListeC queue;
}ListeCTQ;

//PRIMITIVE LISTEC
ListeC suivant(ListeC l);
int donnee(ListeC l);

//PRIMITIVE LISTECTQ
ListeC tete(ListeCTQ l);
ListeC queue(ListeCTQ l);
int taille(ListeCTQ l);

//FONCTION LISTEC
ListeC initL();
ListeC allocMem(int elt);
ListeC inserVideLC(int elt);
ListeC inserTete(int elt, ListeC l);
ListeC inserQueue(int elt, ListeC l);
void printListe(ListeC l);

//FONCTION LISTECTQ
ListeCTQ initLCTQ();
void inserListeCTQV(int elt, ListeCTQ *l);
void inserQueueLCTQ(int elt, ListeCTQ *l);
void printListeCTQ(ListeCTQ l);

//EXERCICE 1
int nbOcc(int elt, ListeC der);
int nbOccLCTQ(int elt, ListeCTQ l);


#endif

#ifndef EXERCICE1_H

int nbOcc(int elt, ListeC der);

#endif

