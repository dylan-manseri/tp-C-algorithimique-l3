#include "structure.h"

int estPO(char c) {
    return c == '(';
}

int estPF(char c) {
    return c == ')';
}

int estSep(char c) {
    return c == ' ';
}

int estPoint(char c) {
    return c=='.';
}

int estChiffre(char c) {
    return c == '0' || c == '1' || c == '2' ||  c == '3' || c == '4' || c == '5' ||
        c == '6' || c == '7' || c == '8' || c == '9';
}
int estOperateur(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int codeAscii(char chr) {
    return (int)chr;
}

double extraireNbReel(int *i, char* exp) {
    char chr = exp[*i];
    double n;
    double nbr=0;
    if (estChiffre(chr)) {
        do {
            n = codeAscii(chr) - codeAscii('0');
            nbr = nbr*10+n;
            (*i)++;
            chr = exp[*i];
        }while (estChiffre(chr));
    }
    if (estPoint(chr)) {
        (*i)++;
        chr=exp[*i];
        double dec = 0.1;
        do {
            n = codeAscii(chr) - codeAscii('0');
            nbr = nbr + n*dec;
            dec/=10;
            (*i)++;
            chr = exp[*i];
        }while (estChiffre(chr));
    }
    return nbr;
}

ArbreExp consA(char* exp) {
    Pile pOperateur = initP();
    Pile pArbre = initP();
    int i = 0;
    int lg = strlen(exp);
    int erreur = 0;
    while (i < lg && !erreur) {
        char chr = exp[i];
        if (estPO(chr) || estSep(chr)) {
            i++;
        }
        else {
            if (estChiffre(chr) || estPoint(chr)) {
                double nM = extraireNbReel(&i, exp);
                TElementA a;
                a.nNoeud = OPERANDE;
                a.dNoeud.operande = nM;
                ArbreExp f = createFeuille(a);
                pArbre = empiler(f, pArbre);
            }
            else {
                if (estOperateur(chr)) {
                    char *copie = malloc(sizeof(char));
                    memcpy(copie, &chr, sizeof(char));
                    pOperateur = empiler(copie, pOperateur);
                    i++;
                }
                else {
                    if (estPF(chr)) {
                        ArbreExp opD = sommetP(pArbre);
                        pArbre = depiler(pArbre);
                        ArbreExp opG = sommetP(pArbre);
                        pArbre = depiler(pArbre);
                        char *opA = sommetP(pOperateur);
                        pOperateur = depiler(pOperateur);
                        TElementA elt;
                        elt.nNoeud = OPERATEUR;
                        DNoeud dnoeud; dnoeud.operateur = *opA;
                        elt.dNoeud = dnoeud;
                        ArbreExp nd = createNoeud(elt, opG, opD);
                        pArbre = empiler(nd, pArbre);
                        i++;
                    }
                    else {
                        erreur = 1;
                        printf("y'a un blem");
                    }
                }
            }
        }
    }
    ArbreExp aExp = sommetP(pArbre);
    pArbre = depiler(pArbre);
    return aExp;
}

double evalOper(char oper, double vd, double vg) {
    switch (oper) {
        case '+': return vd+vg;
        case '-': return vd-vg;
        case '*': return vd*vg;
        case '/': return vd/vg;
    }
}

double evalAExp(ArbreExp aExp) {
    if (estFeuille(aExp)) {
        return operande(dNoeud(donneeA(aExp)));
    }
    double vg = evalAExp(aExp->filsGauche);
    double vd = evalAExp(aExp->filsDroit);
    char oper = operateur(dNoeud(donneeA(aExp)));
    return evalOper(oper, vd, vg);
}