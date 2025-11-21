#include "structure_exo3.h"

Liste searchElt(Liste l, int elt) { //Une cellule est déjà un adresse, donc on renvoi juste la cellule.
    int trouve = 0;
    Liste res = NULL;
    while (!estVide(l) && !trouve) {
        if (donnee(l) == elt) {
            trouve = 1;
            res = l;
        }
    }
    return res;
}

Liste adrInsert(Liste l, int elt) { //Renvoyer l'adresse d'insertion dans un tableau trié pour un elt donnée
    while (!estVide(l) && donnee(l) < elt) {
        l=suivant(l);
    }
    return l;
}

Liste inserTriee(Liste l, int elt) {    //On réalise l'insertion avec l'adresse d'insertion
    if (estVide(l)) {
        return inserTete(l, elt);
    }
    Liste adr = adrInsert(l, elt);
    adr = inserTete(adr, elt);          //Pourquoi ça marche ? -> l est un variable copié mais son contenu est une REELLE adresse
    return l;                           //Ainsi on peut modifier l comme on veut ça va rien changer n global, PAR CONTRE
}                                       //Modifier le contenu de sa structure ex (l->donnee = 2) se fais en global car
                                        //Nous ne sommes plus dans la variable mais dans la struct Liste qui est un pointeur :)
