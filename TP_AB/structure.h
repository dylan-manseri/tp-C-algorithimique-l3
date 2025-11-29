#ifndef TP_AB_STRUCT
#define TP_AB_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef union {
    char operateur;
    double operande;
}DNoeud;

typedef enum {
    OPERATEUR,
    OPERANDE
}NNoeud;

typedef struct {
    NNoeud nNoeud;
    DNoeud dNoeud;
}TElementA;

typedef struct noeud {
    TElementA donnee;
    struct noeud *filsGauche;
    struct noeud *filsDroit;
}*ArbreExp;

// Représentation chainée d'une pile psk c bon on est en L3 venez on fait des vrais bails non ?
typedef struct cel {
    void* donnee;
    struct cel *suivant;
}*Pile;

Pile suivant(Pile p);
Pile initP();
int estVideP(Pile p);
Pile allocMemPile();
void* sommetP(Pile p);
Pile empiler(void* donnee, Pile p);
Pile depiler(Pile p);

#endif

#ifndef TP_AB_EX1
#define TP_AB_EX1

char operateur(DNoeud dnoeud);
double operande(DNoeud dnoeud);
DNoeud dNoeud(TElementA elt);
ArbreExp filsGauche(ArbreExp a);
ArbreExp filsDroit(ArbreExp a);
TElementA donneeA(ArbreExp a);
int estVideA(ArbreExp a);
int estFeuille(ArbreExp a);
int estPO(char c);
int estPF(char c);
int estChiffre(char c);
int estOperateur(char c);
double extraireNbReel(int *i, char* exp);
int estPont(char c);
int estSep(char c);
ArbreExp createFeuille(TElementA elt);
ArbreExp createNoeud(TElementA, ArbreExp fd, ArbreExp fg);
ArbreExp consA(char* exp);
int codeAscii(char c);
double evalOper(char oper, double vg, double vd);
double evalAExp(ArbreExp aExp);


#endif
