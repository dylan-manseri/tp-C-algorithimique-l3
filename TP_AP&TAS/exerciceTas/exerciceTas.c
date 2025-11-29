#include "../structure.h"

int sommetTas(Tas t) {
    return t.tab[0];
}

Tas inserTas(int elt, Tas t) {
    int n = taille(t);
    if (n == 0) {
        t.tab[n] = elt;
        t.taille++;
    }
    else {
        int dp = donneeAP(pereNoeudAP(n, t), t);
        while (n>0 && elt>dp) {
            t.tab[n] = dp;
            n = pereNoeudAP(n, t);
            dp = donneeAP(pereNoeudAP(n, t), t);
        }
        t.tab[n] = elt;
        t.taille++;
    }
    return t;
}

Tas recInserTas(int elt, int n, Tas t) {
    if (n == 0) {
        t.tab[n] = elt;
        t.taille++;
        return t;
    }
    int dp = donneeAP(pereNoeudAP(n, t), t);
    if (elt<=dp) {
        t.tab[n] = elt;
        t.taille++;
        return t;
    }
    t.tab[n] = dp;
    n = pereNoeudAP(n, t);
    return recInserTas(elt, n, t);
}

Tas suppTas(Tas t) {
    int r=0;
    t.taille--;
    t.tab[r] = donneeAP(taille(t), t);
    int elt = donneeAP(r, t);
    int fmax;
    if (!estVideAP(t)) {
        int fg = filsGaucheAP(r, t), fd;
        int echange = 1;
        while (estExistNoeudAP(fg, t) && echange) {
            fd = filsDroitAP(r, t);
            fmax = fg;
            if (estExistNoeudAP(fd, t) && donneeAP(fd, t) > donneeAP(fg, t)) {
                fmax = fd;
            }
            if (elt > donneeAP(fmax, t)) {
                echange = 0;
            }
            else {
                t.tab[r] = donneeAP(fmax, t);
                r=fmax;
                fg = filsGaucheAP(r, t);
            }
        }
        t.tab[r] = elt;
    }
    return t;
}

Tas recSuppTasBis(int elt, int r, int fg, Tas t) {
    if (!estExistNoeudAP(fg,t)) {
        t.tab[r] = elt;
        return t;
    }
    int fmax = fg;
    int fd = filsDroitAP(r, t);
    if (estExistNoeudAP(fd, t) && donneeAP(fd, t) > donneeAP(fg, t)) {
        fmax = fd;
    }
    if (elt>=donneeAP(fmax, t)) {
        t.tab[r] = elt;
        return t;
    }
    t.tab[r] = donneeAP(fmax, t);
    r = fmax;
    fg = filsGaucheAP(r, t);
    return recSuppTasBis(elt, r, fg, t);
}

Tas recSuppTas(Tas t) {
    t.taille--;
    int r = 0;
    t.tab[r] = donneeAP(taille(t), t);
    int elt = donneeAP(taille(t), t);
    if (!estVideAP(t)) {
        int fg = filsGaucheAP(r, t);
        return recSuppTasBis(elt, r, fg ,t);
    }
    return t;
}

int max(int a, int b) {
    if (a>b) {
        return a;
    }
    return b;
}

int estTasVer1(int n, ArbreParfait a) {     // Parcours du bas vers le haut
    if (n<=1) {
        return 1;
    }
    n--;
    int r = 0;
    while (n>r && a.tab[n]<a.tab[pereNoeudAP(n, a)]) {
        n--;
    }
    return n == r;
}

int recEstTasVer1(int n, ArbreParfait a) {  // Parcours du bas vers le haut
    if (n<=1) {
        return 1;
    }
    int nd = n-1;
    int p = pereNoeudAP(nd, a);
    if (donneeAP(nd, a) > donneeAP(p, a)) {
        return 0;
    }
    return recEstTasVer1(nd, a);
}

int estTasVer2(int n, ArbreParfait a) {     // Parcours du haut vers le bas
    if (n<=1) {
        return 1;
    }
    int r = 0;
    int fg = filsGaucheAP(r, a);
    int fd = filsDroitAP(r, a);
    while (estExistNoeudAP(fg, a) && estExistNoeudAP(fd, a) && donneeAP(r, a)>max(donneeAP(fg, a), donneeAP(fd, a))) {
        r++;
        fg = filsGaucheAP(r, a);
        fd = filsDroitAP(r, a);
    }
    if (estExistNoeudAP(fg, a) && estExistNoeudAP(fd, a)) {
        return 0;
    }
    if (estExistNoeudAP(fg, a)) {
        return a.tab[fg] <= donneeAP(r, a);
    }
    return 1;
}

int recEstTasVer2(int n, int r , ArbreParfait a) {
    int fg = filsGaucheAP(r, a);
    if (!estExistNoeudAP(r, a) || !estExistNoeudAP(fg, a)) {
        return 1;
    }
    int fd = filsDroitAP(r, a);
    if (estExistNoeudAP(fd, a)) {
        return donneeAP(r, a) >= max(donneeAP(fg, a), donneeAP(fd, a))
        && recEstTasVer2(n, fg, a) && recEstTasVer2(n, fd, a);
    }
    return donneeAP(r, a) >= donneeAP(fg, a);
}

Tas convertTabtoTas(int n, int *tab) {
    ArbreParfait tas;
    tas = allocMemAP(tas, n);
    tas = initAP(tas);
    for (int i=0; i<n; i++) {
        tas=inserTas(tab[i], tas);
    }
    return tas;
}

Tas recConvertTabToTas(int n, ArbreParfait tas, int *tab) {
    if (n == 0) {
        return tas;
    }
    tas = recInserTas(tab[n-1], taille(tas), tas);
    return recConvertTabToTas(n-1, tas, tab);
}

void triParTas(int n, int *tab) {
    Tas tas;
    tas = allocMemAP(tas, n);
    tas = initAP(tas);
    for (int i=0; i<n; i++) {
        tas = inserTas(tab[i], tas);
    }
    int e;
    for (int j=n-1; j>-1; j--) {
        e = sommetTas(tas);
        tas = suppTas(tas);
        tab[j] = e;
    }
    free(tas.tab);
}