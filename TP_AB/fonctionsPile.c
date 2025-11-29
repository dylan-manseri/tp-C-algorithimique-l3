#include "structure.h"

Pile suivant(Pile p) {
    return p->suivant;
}

Pile initP() {
    return NULL;
}

int estVideP(Pile p) {
    return p==NULL;
}

Pile allocMemPile() {
    Pile p = malloc(sizeof(struct cel));
    return p;
}

void* sommetP(Pile p) {
    return p->donnee;
}

Pile empiler(void* donnee, Pile p) {
    Pile cel = allocMemPile();
    cel->donnee = donnee;
    cel->suivant = p;
    p = cel;
    return p;
}

Pile depiler(Pile p) {
    if (estVideP(p)) {
        return p;
    }
    Pile tmp = p;
    p = suivant(p);
    free(tmp);
    return p;
}

