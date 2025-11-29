#include "../structure.h"

int main(void) {
    Tas t;
    t = allocMemAP(t, 100);
    t = initAP(t);
    t = recInserTas(8, taille(t), t);
    t = recInserTas(5, taille(t), t);
    t = recInserTas(10, taille(t), t);
    t = recInserTas(9, taille(t), t);
    t = recInserTas(16, taille(t), t);
    t = recInserTas(13, taille(t), t);
    t = recInserTas(2, taille(t), t);

    parcoursLargeurParNiveau(t, taille(t)); // Avant suppression
    t = recSuppTas(t);
    parcoursLargeurParNiveau(t, taille(t)); // Apres suppression

    ArbreParfait a;     // Construction d'un AP qui n'est pas un tas pour tester
    a = allocMemAP(a, 100);
    a = initAP(a);
    a = inserEltAP(4, a);
    a = inserEltAP(8, a);
    a = inserEltAP(7, a);
    a = inserEltAP(5, a);
    a = inserEltAP(3, a);
    a = inserEltAP(18, a);
    if (recEstTasVer2(taille(a),0 , a)) {   // On teste si c'est un tas
        printf("c'est un tas\n");
    }
    else {
        printf("ce n'est pas un tas\n");
    }
    parcoursLargeurParNiveau(a, taille(a));
    ArbreParfait tas;
    tas = allocMemAP(tas, taille(a));
    tas = initAP(tas);
    a = recConvertTabToTas(taille(a), tas, a.tab);
    parcoursLargeurParNiveau(a, taille(a));
    int tab[7] = {2,5,6,7,6,4,7};
    triParTas(7, tab);
    for (int i=0; i<7; i++) {
        printf("%d", tab[i]);
    }
}