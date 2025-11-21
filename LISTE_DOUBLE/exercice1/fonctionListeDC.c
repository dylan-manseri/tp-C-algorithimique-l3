#include "../structure.h"

double coef(Monome mon) {
    return mon.coef;
}

int degre(Monome mon) {
    return mon.degre;
}

Monome monome(Polynome p) {
    return p->monome;
}

Polynome suivant(Polynome p) {
    return p->suivant;
}

Polynome precedent(Polynome p) {
    return p->precedent;
}

Polynome initP() {
    return NULL;
}

int estVideP(Polynome p) {
    return p==NULL;
}

Monome newMon(double coef, int degre) {
    Monome m;
    m.coef = coef;
    m.degre = degre;
    return m;
}

void printPolynome(Polynome p) {
    while (!estVideP(p)) {
        printf("%fx^%d", coef(monome(p)), degre(monome(p)));
        if (!estVideP(suivant(p))) {
            printf(" + ");
        }
        p=p->suivant;
    }
    printf("\n");
}

Polynome allocMemRemp(Monome m) {
    Polynome p = (Polynome) malloc(sizeof(struct cellule));
    if (p==NULL) {
        printf("Erreur d'allocation");
        exit(1);
    }
    p->monome = m;
    return p;
}