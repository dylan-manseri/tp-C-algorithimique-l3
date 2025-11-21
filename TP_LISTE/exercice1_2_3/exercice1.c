#include "structure.h"

int estPremier(int nbr) {
    int x = nbr/2;
    int i=2;
    while (i*i <= nbr && nbr%i != 0) {
        i++;
    }
    return i*i > nbr;
}

int nbrDivision(int *nbr, int p) {
    int cpt=0;
    while ((*nbr) % p == 0) {
        *nbr = (*nbr)/p;
        cpt++;
    }
    return cpt;
}

Liste decomposition(int nbr, Liste l) {
    int i=2;
    int div;
    while (i <= nbr) {
        if (estPremier(i) && nbr%i == 0) {
            div = nbrDivision(&nbr, i);
            FactPremier fp = createFactPremier(i, div);
            l = inserQueue(fp, l);
        }
        i++;
    }
    return l;
}

TabLDFP* convertTabToListe(int *tab, int taille) {    //Pourquoi j'ai mit un pointeur ? -> psk c'est un tableau t'es bête...
    TabLDFP *tab_ldfp = malloc(taille * sizeof(TabLDFP));
    int nbr;
    for (int i=0; i<taille; i++) {
        Liste current = createListe();
        nbr = tab[i];
        current = decomposition(nbr, current);
        TabLDFP cel = createTabLDFP(nbr, current);
        *(tab_ldfp+i) = cel;
    }
    return tab_ldfp;
}

int minimum(int a, int b) {
    if (a<b) return a;
    else return b;
}

int puissance(int nbr, int exp){
    for (int i=1; i<exp; i++) {
        nbr *= nbr;
    }
    return nbr;
}

Liste intersection(Liste l1, Liste l2) {
    int f1, f2, occ1, occ2;
    Liste l = createListe();
    l = malloc(sizeof(struct cellule));
    FactPremier fp;
    fp.fact = 1;
    fp.nbOcc = 1;
    l->donnee = fp;
    l->suivant = NULL;
    while (!estVide(l1) && !estVide(l2)) {
        f1 = fact(donnee(l1));
        f2 = fact(donnee(l2));
        occ1 = nbOcc(donnee(l1));
        occ2 = nbOcc(donnee(l2));
        if (f1 == f2) {
            fp.fact *= puissance(f1, minimum(occ1, occ2));  //-> Le dernier fact et l'actuel son commun aux deux listes donc on les
            fp.nbOcc = 1;                                               //Multiplie en conservant l'exposant minimal pour avoir la plus grande val
            l->donnee = fp;                                             //-> On écrase le dernier elt car celui-ci est plus grand
            l1 = suivant(l1);
            l2 = suivant(l2);
        }
        else {
            if (f1 < f2) {
                l1 = suivant(l1);
            }
            else {
                l2 = suivant(l2);
            }
        }
    }
    return l;
}

int pgcd(int *tab, int n) {
    if (n < 1 ) {
        return tab[n];
    }
    TabLDFP *tab_ldfp = convertTabToListe(tab, n); //PB ICI
    Liste l = intersection(liste(tab_ldfp[0]), liste(tab_ldfp[1]));
    for (int i=2; i<n; i++) {
        l = intersection(liste(tab_ldfp[i]), l);
    }
    free(tab_ldfp);
    return fact(donnee(l));
}