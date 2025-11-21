#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int donnee;
    struct cellule *suivant;
}*Liste;

int donnee(Liste l);
Liste suivant(Liste l);
int estVide(Liste l);
Liste initL();
Liste allocMem();

Liste searchElt(Liste l, int elt); //Rechercher l'adresse d'une cellule
Liste inserTete(Liste l, int elt);
Liste inserTriee(Liste l, int elt);

#endif