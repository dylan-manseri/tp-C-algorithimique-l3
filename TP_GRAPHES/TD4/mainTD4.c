#include "../include/prototypeTD4.h"

int mainTD4(void) {
    //MatAdjacence ma = loading("/home/dylanm/Insync/nalyd.irsnm@gmail.com/Google Drive/DrivePC/LICENCE INFORMATIQUE/L3 INFORMATIQUE/S6/Graphes et optimisation combinatoire/tp-code/TP_GRAPHES/graphe.txt");
    //MatAdjacence ma2 = getCarreMA(ma);
    //printMat(&ma2, MAT_ADJACENCE);

    ListeAdjacence la;
    allocLA(4, &la);
    la.tabAdj[0] = inserQueue(1, la.tabAdj[0]);
    la.tabAdj[1] = inserQueue(2, la.tabAdj[1]);
    la.tabAdj[2] = inserQueue(0, la.tabAdj[2]);
    la.tabAdj[2] = inserQueue(1, la.tabAdj[2]);
    la.tabAdj[3] = inserQueue(3, la.tabAdj[3]);
    ListeAdjacence l2 = getCarreLA(la);
    printLA(l2);

    return 0;
}