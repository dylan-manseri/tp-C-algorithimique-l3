#include "../include/structure.h"

/**
 * Crée une Liste d'adjacence à partir d'une matrice d'adjacence
 * @param ma Une matrice d'adjacence
 * @return La liste d'adjacence résultante
 */
ListeAdjacence convertMAtoLA(MatAdjacence ma) {
    ListeAdjacence la;
    int n = ma.nbSom;
    int** mat = ma.mat;
    allocLA(n, &la);
    for (int s=0; s<n; s++) {
        for (int t=0; t<n; t++) {
            if (mat[s][t] == 1) {
                la.tabAdj[s] = inserQueue(t ,la.tabAdj[s]);
            }
        }
    }
    return la;
}

/**
 * Compte le nombre d'arcs d'un graphe à partir d'unee matrice d'adjacence
 * @param ma
 * @return
 */
int countArc(MatAdjacence ma) {
    int** mat = ma.mat;
    int n = ma.nbSom;
    int nb=0;
    for (int s=0; s<n; s++) {
        for (int t=0; t<n; t++) {
            if (mat[s][t] == 1) {
                nb++;
            }
        }
    }
    return nb;
}

/**
 * Construit une file de successeur à partir d'une matrice d'adjacence
 * @param ma
 * @return
 */
FileSuccesseur convertMAtoFS(MatAdjacence ma) {
    int nbArcs = countArc(ma);  // Pour pouvoir allouer il nous faut le nombre d'élmt de FS, soit on le compte soit on définit une valeur max n*2
    FileSuccesseur fs;
    int n = ma.nbSom;
    int** mat = ma.mat;
    allocFS(n, nbArcs, &fs);
    int iaps = 0;
    int s;
    for (s=0; s<n; s++) {
        fs.APS[s] = iaps;
        for (int t=0; t<n; t++) {
            if (mat[s][t] == 1) {
                fs.FS[iaps] = t;
                iaps++;
            }
        }
    }
    fs.FS[iaps] = 0;
    fs.APS[s] = 0;
    return fs;
}

/**
 * Construit une Liste successeur prédécesseur à partir d'une matrice d'adjacence
 * @param ma
 * @return
 */
ListeAdjSuccPred convertMAtoLSP(MatAdjacence ma) {
    ListeAdjSuccPred lsp;
    int n = ma.nbSom;
    int** mat = ma.mat;
    allocLSP(n, &lsp);
    for (int s=0; s<n; s++) {
        for (int t=0; t<n; t++) {
            if (mat[s][t] == 1) {
                lsp.tabAdjSP[s].lSucc = inserQueueLS(t, lsp.tabAdjSP[s].lSucc);
                lsp.tabAdjSP[t].lPred = inserQueueLP(s, lsp.tabAdjSP[t].lPred);
            }
        }
    }
    return lsp;
}