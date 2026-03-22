#include "../include/prototypeTD6.h"
#include "../include/prototypeTD12.h"

int mainTD6(void) {
    MatAdjacence mat = loading("/home/dylanm/Insync/nalyd.irsnm@gmail.com/Google Drive/DrivePC/LICENCE INFORMATIQUE/L3 INFORMATIQUE/S6/Graphes et optimisation combinatoire/tp-code/TP_GRAPHES/graphe.txt");
    File f = triTopologiqueAcyclique(&mat, MAT_ADJACENCE);

    while (!estVide(f)) {
        printf("%d | ",donnee(f)+1);
        f = suppTete(f);
    }
}