#include "../include/prototypeTD3.h"
#include "../include/prototypeTD12.h"

int mainTD3(void) {

    MatAdjacence mat = loading("/home/dylanm/Insync/nalyd.irsnm@gmail.com/Google Drive/DrivePC/LICENCE INFORMATIQUE/L3 INFORMATIQUE/S6/Graphes et optimisation combinatoire/tp-code/TP_GRAPHES/graphe.txt");
    parcoursProfondeur(0, &mat, MAT_ADJACENCE);
    return 0;
}