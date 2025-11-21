#include "../structure.h"

ArbreParfait allocMemAP(ArbreParfait a, int tMax) {
    a.tailleMax = tMax;
    a.tab = malloc(sizeof(ArbreParfait));
    return a;
}

ArbreParfait initAP(ArbreParfait a) {
    a.taille = 0;
    return a;
}

int estVideAP(ArbreParfait a) {
    return a.taille == 0;
}

int estPleinAP(ArbreParfait a) {
    return a.taille == a.tailleMax;
}

int estExistNoeudAP(int nd, ArbreParfait a) {
    return nd < a.taille;
}

int donneeAP(int nd, ArbreParfait a) {
    return a.tab[nd];
}

int pereNoeudAP(int nd, ArbreParfait a) {
    return (nd-1)/2;
}

int filsGauche(int nd, ArbreParfait a) {
    return 2*nd+1;
}

int filsDroit(int nd, ArbreParfait a) {
    return 2*nd+2;
}

int estFeuille(int nd, ArbreParfait a) {
    return (estExistNoeudAP(filsDroit(nd, a), a) && estExistNoeudAP(filsGauche(nd, a), a));
}

void parcoursInfixeAP(int racine, ArbreParfait a) {
    if (estExistNoeudAP(racine, a)) {
        parcoursInfixeAP(filsGauche(racine, a), a);
        // traiter
        parcoursInfixeAP(filsDroit(racine, a), a);
    }
}

void parcoursPrefixeAP(int racine, ArbreParfait a) {
    if (estExistNoeudAP(racine, a)) {
        // traiter
        parcoursPrefixeAP(filsGaucheAP(racine, a), a);
        parcoursPrefixeAP(filsDroit(racine, a), a);
    }
}

void parcoursPostfixeAP(int racine, ArbreParfait a) {
    if (estExistNoeudAP(racine, a)) {
        parcoursPostfixeAP(filsGauche(racine, a), a);
        parcoursPostfixeAP(filsDroit(racine, a), a);
        // traiter
    }
}

void parcoursLargeur(int racine, ArbreParfait a) {
    int nbNoeuds = taille(a);
    for (int i=0; i<nbNoeuds; i++) {
        // traiter
    }
}

ArbreParfait inserEltAP(int elt, ArbreParfait a) {

}

