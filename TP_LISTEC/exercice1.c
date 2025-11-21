#include "structure.h"

int nbOcc(int elt, ListeC der) {
    ListeC ll = der;
    int occ=0;
    do {
        if (donnee(ll)==elt) {
            occ++;
        }
        ll = suivant(ll);
    }while (ll!=der);
    return occ;
}

int nbOccLCTQ(int elt, ListeCTQ l) {
    ListeC ll = tete(l);
    ListeC der = queue(l);
    int occ=0;
    do {
        if (donnee(ll)==elt) {
            occ++;
        }
        ll = suivant(ll);
    }while (ll!=der);
    return occ;
}