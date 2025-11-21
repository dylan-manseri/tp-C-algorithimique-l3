#include "structure.h"

ListeC tete(ListeCTQ l) {
    return l.tete;
}

ListeC queue(ListeCTQ l) {
    return l.queue;
}

ListeCTQ initLCTQ() {
    ListeCTQ l;
    l.tete = NULL;
    l.queue = NULL;
    l.taille = 0;
    return l;
}

void inserListeCTQV(int elt, ListeCTQ *l) {
    ListeC cel = allocMem(elt);
    cel->suivant = cel;
    (*l).tete = cel;
    (*l).queue = cel;
    (*l).taille = 1;
}

void inserTeteLCTQ(int elt, ListeCTQ *l) {
    ListeC cel = allocMem(elt);
    cel->suivant = tete(*l);
    (l->queue)->suivant = cel;
    (*l).tete = cel;
    (*l).taille++;
}

void inserQueueLCTQ(int elt, ListeCTQ *l) {
    ListeC cel = allocMem(elt);
    cel -> suivant = tete(*l);
    (l->queue)->suivant = cel;
    (*l).queue = cel;
    (*l).taille++;
}

void printListeCTQ(ListeCTQ l) {
    printListe(tete(l));
}