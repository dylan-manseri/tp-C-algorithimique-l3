#include "structure.h"

int main(void) {
    printf("QUESTION 2)\n");
    Liste l = createListe();
    l = decomposition(210, l);
    printListe(l);

    printf("\nQUESTION 3)\n");
    int tab[4] = {40, 15, 13, 210};
    TabLDFP *l2 = convertTabToListe(tab, 4);
    printTabLDFP(l2, 4);

    printf("\nQUESTION 5)\n");
    Liste l3 = createListe(); Liste l4 = createListe();
    l3 = decomposition(6, l3);
    l4 = decomposition(30, l4);
    Liste l5 = intersection(l3, l4);
    printListe(l5);

    printf("\nQUESTION 6)\n");
    int tab1[3] = {12, 18, 30};
    int pgcdV = pgcd(tab1, 3);
    printf("%d", pgcdV);
}