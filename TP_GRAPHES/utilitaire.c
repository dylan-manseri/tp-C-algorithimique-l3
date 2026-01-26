#include "structure.h"

int nbSom(MatAdjacence m){
    return m.nbSom;
}

int estVide(Liste l){
    return l == NULL;
}

int donnee(Liste l){
    return l->donnee;
}

Liste suivant(Liste l){
    return l->suivant;
}

Liste inserTete(int donnee, Liste l){
    Liste cel = malloc(sizeof(struct cel));
    cel->donnee = donnee;
    cel->suivant = l;
    l = cel;
    return l;
}

Liste adrDernier(Liste l){
    if(estVide(l)){
        return l;
    }
    while(!estVide(suivant(l))){
        l=suivant(l);
    }
    return l;
}

Liste inserQueue(int donnee, Liste l){
    if(estVide(l)){
        return inserTete(donnee, l);
    }
    Liste der = adrDernier(l);
    der->suivant = inserTete(donnee, suivant(der));
    return l;
}

Liste initL(){
    return NULL;
}

ListeAdjacence initLA(int nbSom){
    ListeAdjacence la;
    la.nbSom = nbSom;
    la.tabAdj = malloc(la.nbSom * sizeof(struct cel));
    for(int i=0; i<nbSom; i++){
        la.tabAdj[i] = initL();
    }
    return la;
}