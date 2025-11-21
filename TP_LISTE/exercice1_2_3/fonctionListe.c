#include "structure.h"

int fact(FactPremier f) {
    return f.fact;
}

int nbOcc(FactPremier f) {
    return f.nbOcc;
}

FactPremier donnee(Liste l) {
    return l->donnee;
}

Liste suivant(Liste l) {
    return l->suivant;
}

Liste createListe() {
    return NULL;
}

int nombre(TabLDFP cel) {
    return cel.nbr;
}
Liste liste(TabLDFP cel) {
    return cel.ldfp;
}

FactPremier createFactPremier(int fact, int nbOcc) {
    FactPremier fp;
    fp.fact = fact;
    fp.nbOcc = nbOcc;
    return fp;
}

int estVide(Liste l) {
    if (l==NULL) {
        return 1;
    }
    return 0;
}

Liste adrDernier(Liste l) {
    while (!estVide(suivant(l))) {
        l=suivant(l);
    }
    return l;
}

Liste inserTete(FactPremier fp, Liste l) {
    Liste cel = malloc(sizeof(struct cellule));
    cel-> donnee = fp;
    cel->suivant = l;
    return l = cel;
}

Liste inserQueue(FactPremier fp, Liste l) {
    if (estVide(l)) {
        return inserTete(fp, l);
    }
    Liste der = adrDernier(l);
    der->suivant = inserTete(fp, suivant(der));
    return l;
}

TabLDFP createTabLDFP(int nbr, Liste l) {
    TabLDFP cel;
    cel.nbr = nbr;
    cel.ldfp = l;
    return cel;
}

void printFactPremier(FactPremier fp) {
    printf("%d^%d", fact(fp), nbOcc(fp));
}

void printListe(Liste l) {
    if (estVide(l)) {
        printf("Liste vide");
    }
    else {
        printf("| ");
        while (!estVide(l)) {
            printFactPremier(donnee(l));
            printf(" | ");
            l = suivant(l);
        }
    }
    printf("\n");
}

void printTabLDFP(TabLDFP* tab, int taille) {
    int nbr;
    for (int i=0; i<taille; i++) {
        nbr = nombre(*(tab+i));
        printf("%d -> ",nbr);
        Liste l = liste(*(tab+i));
        printListe(l);
    }
}

