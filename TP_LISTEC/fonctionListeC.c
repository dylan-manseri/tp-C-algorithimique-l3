#include "structure.h"

ListeC suivant(ListeC l) {
    return l->suivant;
}

int donnee(ListeC der) {
    return der->elt;
}

ListeC initL() {
    return NULL;
}

ListeC allocMem(int elt) {
    ListeC cel = malloc(sizeof(struct cel));
    if (cel == NULL) {
        printf("erreur d'allocation");
        exit(1);
    }
    cel->elt = elt;
    return cel;
}

ListeC inserVideLC(int elt) {
    ListeC cel = allocMem(elt);
    cel->suivant = cel; //Liste circulaire
    return cel;
}

ListeC inserTete(int elt, ListeC der) {
    ListeC cel = allocMem(elt);
    cel->suivant = suivant(der);
    der->suivant = cel;
    return der;
}

ListeC inserQueue(int elt, ListeC der) {
    ListeC cel = allocMem(elt);
    cel->suivant = suivant(der);
    der->suivant = cel;
    der=cel;
    return der;
}

void printListe(ListeC l) {
    ListeC ll=l;
    do {
        printf("| %d ",donnee(ll));
        ll=suivant(ll);
    }while (ll!=l);
    printf("|");
}