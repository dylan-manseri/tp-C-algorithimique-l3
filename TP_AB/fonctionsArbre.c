#include "structure.h"

char operateur(DNoeud dnoeud) {
    return dnoeud.operateur;
}

double operande(DNoeud dnoeud) {
    return dnoeud.operande;
}

DNoeud dNoeud(TElementA elt) {
    return elt.dNoeud;
}

ArbreExp fileGauche(ArbreExp a) {
    return a->filsGauche;
}

ArbreExp filsDroit(ArbreExp a) {
    return a->filsDroit;
}

TElementA donneeA(ArbreExp a) {
    return a->donnee;
}

int estVideA(ArbreExp ae) {
    return ae==NULL;
}

int estFeuille(ArbreExp ae) {
    return estVideA(filsDroit(ae)) && estVideA(fileGauche(ae));
}

ArbreExp createFeuille(TElementA a) {
    ArbreExp ae = malloc(sizeof(struct noeud));
    ae->donnee = a;
    ae->filsDroit = NULL;
    ae->filsGauche = NULL;
    return ae;
}

ArbreExp createNoeud(TElementA elt, ArbreExp fg, ArbreExp fd) {
    ArbreExp ae = malloc(sizeof(struct noeud));
    ae->donnee = elt;
    ae->filsGauche = fg;
    ae->filsDroit = fd;
    return ae;

}