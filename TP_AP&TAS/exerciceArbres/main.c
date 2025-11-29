#include "../structure.h"

int main(void) {
    ArbreParfait a = constAP();
    parcoursLargeurParNiveau(a, taille(a));
    parcoursArbreParfaitNiveauPlein(a);
}