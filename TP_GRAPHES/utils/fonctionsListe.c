/**
 * Toutes les fonctions relatives aux listes, il y en a 3 types pour ce TP
 * Liste classique : utilisé pour les Liste Adjacences
 * Liste Successeur : utilisé pour ListeAdjSuccPred, (cf. structure.h)
 * Liste Predecesseur : utilisé pour ListeAdjSuccPred
 *
 * Remarque : Je sais pas si avec la généricité on pourrait tout regrouper, ça serait intéressant d'éssayer
*/
#include "../include/structure.h"

// Est vide
int nbSom(MatAdjacence m){
    return m.nbSom;
}

int estVide(Liste l){
    return l == NULL;
}

int estVideLP(ListePred lp) {
    return lp==NULL;
}

int estVideLS(ListeSucc ls) {
    return ls==NULL;
}

// Donnee
int donnee(Liste l){
    return l->donnee;
}

int donneeLP(ListePred lp){
    return lp->somPred;
}

int donneeLS(ListeSucc ls){
    return ls->somSucc;
}

// Suivant
Liste suivant(Liste l){
    return l->suivant;
}

ListePred suivantLP(ListePred lp) {
    return lp->suivPred;
}

ListeSucc suivantLS(ListeSucc ls) {
    return ls->suivSucc;
}

// inserTete
Liste inserTete(int donnee, Liste l){
    Liste cel = malloc(sizeof(struct cel));
    cel->donnee = donnee;
    cel->suivant = l;
    l = cel;
    return l;
}

ListePred inserTeteLP(int somPred, ListePred lp) {
    ListePred cellulePred = malloc(sizeof(struct cellulePred));
    cellulePred->somPred = somPred;
    cellulePred->suivPred = lp;
    lp = cellulePred;
    return lp;
}

ListeSucc inserTeteLS(int somSucc, ListeSucc ls) {
    ListeSucc celluleSucc = malloc(sizeof(struct celluleSucc));
    celluleSucc->somSucc = somSucc;
    celluleSucc->suivSucc = ls;
    ls = celluleSucc;
    return ls;
}

// AdrDernier
Liste adrDernier(Liste l){
    if(estVide(l)){
        return l;
    }
    while(!estVide(suivant(l))){
        l=suivant(l);
    }
    return l;
}

ListePred adrDernierLP(ListePred lp) {
    if (estVideLP(lp)) {
        return lp;
    }
    while (!estVideLP(suivantLP(lp))){
        lp=suivantLP(lp);
    }
    return lp;
}

ListeSucc adrDernierLS(ListeSucc ls) {
    if (estVideLS(ls)) {
        return ls;
    }
    while (!estVideLS(suivantLS(ls))) {
        ls=suivantLS(ls);
    }
    return ls;
}

// inserQueue
Liste inserQueue(int donnee, Liste l){
    if(estVide(l)){
        return inserTete(donnee, l);
    }
    Liste der = adrDernier(l);
    der->suivant = inserTete(donnee, suivant(der));
    return l;
}

ListePred inserQueueLP(int somPred, ListePred lp) {
    if (estVideLP(lp)) {
        return inserTeteLP(somPred, lp);
    }
    ListePred der = adrDernierLP(lp);
    der->suivPred = inserTeteLP(somPred, suivantLP(lp));
    return lp;
}

ListeSucc inserQueueLS(int somSucc, ListeSucc ls) {
    if (estVideLS(ls)) {
        return inserTeteLS(somSucc, ls);
    }
    ListeSucc der = adrDernierLS(ls);
    der->suivSucc = inserTeteLS(somSucc, suivant(ls));
    return ls;
}

// initL
Liste initL(){
    return NULL;
}

ListeSucc initLS() {
    return NULL;
}

ListePred initLP() {
    return NULL;
}