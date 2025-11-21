#include "../structure.h"

Polynome inserTete(Monome m, Polynome p) {
    Polynome cel = allocMemRemp(m);
    cel->suivant = p;
    cel->precedent = initP();
    p=cel;
    return p;
}

Polynome suppTete(Polynome p) {
    if (estVideP(p)) {
        return p;
    }
    Polynome as=p;
    p=p->suivant;
    free(as);
    return p;
}

Polynome adresseInsertion(Monome m, Polynome p) {
    while (!estVideP(suivant(p)) && degre(monome(suivant(p))) < degre(m) ) {
        p=p->suivant;
    }
    return p;
}

int zero(double d) {
    double epsilon = 1e-9;
    if (fabs(d) < epsilon) {
        return 1;
    }
    return 0;
}

Polynome inserQueue(Monome m, Polynome der, Polynome p) {
    Polynome cel = allocMemRemp(m);
    cel->suivant = NULL;
    cel->precedent = der;
    der->suivant = cel;
    return p;
}

Polynome inserApres(Monome m, Polynome ai,Polynome p) {
    Polynome cel = allocMemRemp(m);
    Polynome sai = suivant(ai);
    cel->suivant = sai;
    sai->precedent = cel;
    ai->suivant = cel;
    cel->precedent = ai;
    return p;
}

Polynome suppQueue(Polynome as, Polynome p) {
    (as->precedent)->suivant = NULL;
    free(as);
    return p;
}

Polynome suppAilleurs(Polynome as, Polynome p) {
    (as->precedent)->suivant = suivant(as);
    (as->suivant)->precedent = precedent(as);
    free(as);
    return p;
}

Polynome inserMonPoly(Monome m, Polynome p) {
    if (estVideP(p)) {
        return inserTete(m,p);
    }
    double dm = degre(m);
    double dmp = degre(monome(p));
    if (dm < dmp) {                         //On fait les tests pour le premier monome
        return inserTete(m,p);
    }
    if (dm == dmp) {
        double sc = coef(m) + coef(monome(p));
        if (zero(sc)) {
            return suppTete(p);
        }
        p->monome.coef = sc;
    }
    Polynome ai = adresseInsertion(m,p);    //L'insertion ne se faisant pas au debut, on cherche l'adresse d'insertion
    Polynome sai = suivant(ai);
    if (estVideP(sai)) {                    //On fait les mêmes tests pour ce polynome
        return inserQueue(m,ai,p);
    }
    int dmsai = degre(monome(sai));
    if (dm<dmsai) {
        return inserApres(m, ai, p);
    }
    double sc  = coef(monome(sai))+coef(m);
    if (zero(sc)) {
        if (estVideP(suivant(sai))) {
            return suppQueue(sai,p);
        }
        return suppAilleurs(sai,p);
    }
    (sai->monome).coef = sc;
    return p;
}

Polynome rechMonPoly(Monome m, Polynome p) {    // Pas compris "renvoyer l'adresse du monome" alors que Monome
    int dm = degre(m);                          // n'est pas une structure pointée, donc j'ai renvoyé le polynome
    double cm = coef(m);
    int dmp = degre(monome(p));
    double cmp = coef(monome(p));
    while (!estVideP(p) && dm!=dmp && cm!=cmp) {
        p=p->suivant;
        dmp = degre(monome(p));
        cmp = coef(monome(p));
    }
    return p;
}

Polynome suppMonPoly(Monome m, Polynome p) {
    Polynome as = rechMonPoly(m, p);
    if (estVideP(precedent(as))) {
        return suppTete(as);
    }
    if (estVideP(suivant(as))) {
        return suppQueue(as, p);
    }
    return suppAilleurs(as,p);
}

Polynome delPolynome(Polynome p) {
    while (!estVideP(p)) {
        p=suppTete(p);
    }
    return p;
}

double maxCoef(Polynome p) {
    double cp = coef(monome(p));
    double cmax = cp;
    p=suivant(p);
    while (!estVideP(p)) {
        cp = coef(monome(p));
        if (cp>cmax) {
            cmax=cp;
        }
        p=suivant(p);
    }
    return cmax;
}

double somCoef(Polynome p) {
    double som = 0;
    while (!estVideP(p)) {
        som+=coef(monome(p));
        p=suivant(p);
    }
    return som;
}

Polynome generPoly(int n, int *tab) {
    Polynome p = initP();
    Monome m;
    double coef;
    for (int i=0; i<n; i++) {
        coef=tab[i];
        if (coef!=0) {
            m = newMon(coef, i);
            p=inserMonPoly(m,p);
        }
    }
    return p;
}

Polynome derivPoly(Polynome p) {
    Polynome pderiv = initP();
    Monome m;
    int deg;
    double coeff;
    while (!estVideP(p)) {
        m = monome(p);
        if (degre(m) != 0) {
            deg = degre(m)-1;
            coeff = coef(m)*degre(m);
            m = newMon(coeff, deg);
            pderiv = inserMonPoly(m, pderiv);
        }
        p=suivant(p);
    }
    return pderiv;
}

Polynome somPoly(Polynome p1, Polynome p2) {
    Polynome sp = initP();
    int dp1, dp2;
    double cp1, cp2;
    Monome m;
    while (!estVideP(p1) && !estVideP(p2)) {
        dp1 = degre(monome(p1));
        dp2 = degre(monome(p2));
        if (dp1<dp2) {
            sp = inserMonPoly(monome(p1), sp);
            p1=suivant(p1);
        }
        else if (dp1>dp2) {
            sp = inserMonPoly(monome(p2), sp);
            p2=suivant(p2);
        }
        else {
            cp1 = coef(monome(p1));
            cp2 = coef(monome(p2));
            if (cp1+cp2 != 0) {
                m = newMon(cp1+cp2, dp1);
                sp = inserMonPoly(m,sp);
            }
            p1=suivant(p1);
            p2=suivant(p2);
        }
    }
    while (!estVideP(p1)) {
        sp = inserMonPoly(monome(p1), sp);
        p1=suivant(p1);
    }
    while (!estVideP(p2)) {
        sp = inserMonPoly(monome(p2), sp);
        p2=suivant(p2);
    }
    return sp;
}