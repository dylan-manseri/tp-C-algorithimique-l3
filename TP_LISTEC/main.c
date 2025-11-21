#include "structure.h"

int main(void) {
    printf("EXERCICE 1 (circulaire) \n");
    ListeC l = initL();
    l = inserVideLC(6);
    l = inserQueue(5, l);
    l = inserQueue(8, l);
    l = inserQueue(1, l);
    l = inserQueue(5, l);
    printListe(l);
    printf("\nNombre d occurrence : %d\n",nbOcc(5,l));

    printf("EXERCICE 1 (circulaire tete queue)\n");
    ListeCTQ l1 = initLCTQ();
    inserListeCTQV(9, &l1);
    inserQueueLCTQ(3, &l1);
    inserQueueLCTQ(9, &l1);
    inserQueueLCTQ(9, &l1);
    inserQueueLCTQ(9, &l1);
    printListeCTQ(l1);
    printf("\nNombre d occurrence : %d\n",nbOccLCTQ(9,l1));

}