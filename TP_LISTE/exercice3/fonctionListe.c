#include "structure_exo3.h"

int donnee(Liste l) {
    return l->donnee;
}

Liste suivant(Liste l) {
    return l->suivant;
}

int estVide(Liste l) {
    return l==NULL;
}

Liste initL() {
    return NULL;
}

Liste allocMem() {
    return malloc(sizeof(struct cellule));
}

Liste inserTete(Liste l, int elt) {
    Liste cel = allocMem();
    cel->donnee = elt;
    cel->suivant = l;
    l=cel;
    return l;
}