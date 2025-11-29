#include "../structure.h"

ArbreParfait allocMemAP(ArbreParfait a, int tMax) {
    a.tailleMax = tMax;
    a.tab = malloc(tMax * sizeof(ArbreParfait));
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

int filsGaucheAP(int nd, ArbreParfait a) {
    return 2*nd+1;
}

int filsDroitAP(int nd, ArbreParfait a) {
    return 2*nd+2;
}

int estFeuille(int nd, ArbreParfait a) {
    return (estExistNoeudAP(filsDroitAP(nd, a), a) && estExistNoeudAP(filsGaucheAP(nd, a), a));
}

void parcoursInfixeAP(int racine, ArbreParfait a) {
    if (estExistNoeudAP(racine, a)) {
        parcoursInfixeAP(filsGaucheAP(racine, a), a);
        // traiter
        parcoursInfixeAP(filsDroitAP(racine, a), a);
    }
}

void parcoursPrefixeAP(int racine, ArbreParfait a) {
    if (estExistNoeudAP(racine, a)) {
        // traiter
        parcoursPrefixeAP(filsGaucheAP(racine, a), a);
        parcoursPrefixeAP(filsDroitAP(racine, a), a);
    }
}

void parcoursPostfixeAP(int racine, ArbreParfait a) {
    if (estExistNoeudAP(racine, a)) {
        parcoursPostfixeAP(filsGaucheAP(racine, a), a);
        parcoursPostfixeAP(filsDroitAP(racine, a), a);
        // traiter
    }
}

void parcoursLargeurAP(int racine, ArbreParfait a) {
    int nbNoeuds = taille(a);
    for (int i=0; i<nbNoeuds; i++) {
        // traiter
    }
}

void parcoursLargeurParNiveau(ArbreParfait a, int n) {
    int noeud = 0;
    int nbNoeudNiv = 1;
    int compteur;
    while (estExistNoeudAP(noeud, a)) {
        compteur = 0;
        while (estExistNoeudAP(noeud, a) && (compteur < nbNoeudNiv)) {
            printf("%d ",donneeAP(noeud, a));
            noeud++;
            compteur++;
        }
        printf("\n");
        nbNoeudNiv *= 2;
    }
}

void parcoursArbreParfaitNiveauPlein(ArbreParfait a) {  // L'arbre doit être plein
    int n = taille(a);
    int h = (int) round(log(n+1)/log(2));           // h=log2(n+1) est double donc je le convertis en int
    int hM = h-1;                                       // On s'arrête à l'avant-dernier nœud
    int nbNiveau = 1;                                   // La racine a forcément 1 noeud
    int noeud = 0;
    for (int i=0; i<hM; i++) {
        for (int k=0; k<nbNiveau; k++) {
            printf("%d ", donneeAP(noeud, a));
            noeud++;
        }
        nbNiveau *= 2;                                  // Le prochain niveau a nbNiveau*2 noeuds
        printf("\n");
    }
    for (; noeud<n; noeud++) {                          // On refait une boucle juste pour la fin pour ne pas devoir
        printf("%d ", donneeAP(noeud, a));        // recalculer nbNiveau, avec 'n' on a déjà ce qu'il nous faut.
    }
    printf("\n");
}

ArbreParfait inserEltAP(int elt, ArbreParfait a) {
    if (!estPleinAP(a)) {
        a.tab[taille(a)] = elt;
        a.taille++;
    }
    return a;
}

ArbreParfait constAP() {
    ArbreParfait a;
    int tMax = 100, t;
    printf("Bienvenue dans l'algorithme de creation d'arbre parfait.\n");
    printf("Pour commencer, indiquez la taille de l'arbre.\n");
    scanf("%d", &t);
    a = allocMemAP(a, tMax);
    a = initAP(a);
    printf("Ecoute en cours, indiquez à la suite les elements de l'arbre.\n");
    int donnee;
    for (int i=0; i<t; i++) {
        scanf("%d", &donnee);
        a = inserEltAP(donnee, a);
    }
    return a;

}

