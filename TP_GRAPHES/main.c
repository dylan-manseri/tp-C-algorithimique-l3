#include "structure.h"

int main(void) {
    MatAdjacence mat = loading("/home/dylanm/Insync/nalyd.irsnm@gmail.com/Google Drive/DrivePC/LICENCE INFORMATIQUE/L3 INFORMATIQUE/S6/Graphes et optimisation combinatoire/tp-C-algorithimique-l3/TP_GRAPHES/graphe.txt");
    //printMat(mat);

    //traitSuccMatAdj(4, mat);

    FileSuccesseur fs;
    fs.nbSom = 4;
    fs.nbArcs = 5;
    fs.FS = malloc(fs.nbArcs * sizeof(int));
    fs.APS = malloc(fs.nbSom * sizeof(int));
    fs.FS[0]=2; fs.FS[1]=3; fs.FS[2]=1; fs.FS[3]=3; fs.FS[4]=4; fs.FS[5]=0;
    fs.APS[0]=0; fs.APS[1]=1; fs.APS[2]=2; fs.APS[3]=3; fs.APS[4]=5;
    fs.FS[3] = 3;
    //traitSuccFS(4, fs);

    ListeAdjacence la = initLA(4);
    la.tabAdj[0] = inserQueue(2, la.tabAdj[0]);
    la.tabAdj[1] = inserQueue(3, la.tabAdj[1]);
    la.tabAdj[2] = inserQueue(1, la.tabAdj[2]);
    la.tabAdj[3] = inserQueue(3, la.tabAdj[3]);
    la.tabAdj[3] = inserQueue(4, la.tabAdj[3]);
    traitSuccL(4, la);

}