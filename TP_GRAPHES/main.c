/**
 *Fonction principale, décommenter pour tester chaque fonctions
 */

#include "include/structure.h"

int main(void) {
    // STRUCTURE MATRICE ADJACENCE

    MatAdjacence mat = loading("/home/dylanm/Insync/nalyd.irsnm@gmail.com/Google Drive/DrivePC/LICENCE INFORMATIQUE/L3 INFORMATIQUE/S6/Graphes et optimisation combinatoire/tp-code/TP_GRAPHES/graphe.txt");
    //printMat(mat);

    //traitSuccMatAdj(3, mat);
    //traitPredMatAdj(3, mat);
    /*if(estBoucleMA(mat)){
        printf("C'est une boucle !\n");
    }
    else{
        printf("Ce n'est pas une boucle...\n");
    }*/

   //printf("%d\n", maxSuccMA(mat));

    /*ListeAdjacence lAdj = convertMAtoLA(mat);
    printLA(lAdj);*/

    /*FileSuccesseur fsu = convertMAtoFS(mat);
    printFS(fsu);*/

    /*ListeAdjSuccPred lsp = convertMAtoLSP(mat);
    printLSP(lsp);*/

    // STRUCTURE FILE DE SUCCESSEUR

    FileSuccesseur fs;
    fs.nbSom = 4;
    fs.nbArcs = 5;
    fs.FS = malloc(fs.nbArcs * sizeof(int));
    fs.APS = malloc(fs.nbSom * sizeof(int));
    fs.FS[0]=2; fs.FS[1]=3; fs.FS[2]=1; fs.FS[3]=2; fs.FS[4]=3; fs.FS[5]=0;
    fs.APS[0]=0; fs.APS[1]=2; fs.APS[2]=3; fs.APS[3]=4; fs.APS[4]=5;

    //traitSuccFS(4, fs);

    //traitPredFS(3, fs);

    /*if(estBoucleFS(fs)){
        printf("C'est une boucle !\n");
    }

    else{
        printf("Ce n'est pas une boucle...\n");
    }*/

   //printf("%d\n", maxSuccFS(fs));

    /*ListeAdjacence listeAdj = convertFStoLA(fs);
    printLA(listeAdj);*/

    // STRUCTURE LISTE ADJACENCE

    ListeAdjacence la;
    allocLA(4, &la);
    la.tabAdj[0] = inserQueue(2, la.tabAdj[0]);
    la.tabAdj[1] = inserQueue(3, la.tabAdj[1]);
    la.tabAdj[2] = inserQueue(1, la.tabAdj[2]);
    la.tabAdj[2] = inserQueue(2, la.tabAdj[2]);
    la.tabAdj[3] = inserQueue(4, la.tabAdj[3]);

    //traitSuccL(4, la);

    //traitPredL(3, la);

    /*if(estBoucleLA(la)){
        printf("C'est une boucle !\n");
    }
    else{
        printf("Ce n'est pas une boucle...\n");
    }*/

   //printf("%d\n", maxSuccLA(la));

    FileSuccesseur f = convertLAtoFS(la);
    printFS(fs);
}