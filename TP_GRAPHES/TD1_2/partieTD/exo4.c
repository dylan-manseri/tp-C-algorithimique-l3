#include "../../include/prototypeTD12.h"

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
                la.tabAdj[s] = inserQueue(t+1 ,la.tabAdj[s]); // t+1 pour insérer la bonne valeur non algorithmique
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
                fs.FS[iaps] = t+1;
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

/**
 * Construit une liste d'adjacence en fonction d'une file de successeur
 * @param fs la fille de successeur initial
 * @return la liste d'adjacence crée
 */
ListeAdjacence convertFStoLA(FileSuccesseur fs) {
    int n = fs.nbSom;
    ListeAdjacence la;
    allocLA(fs.nbSom, &la);
    int iaps, nbr;
    for (int s=0; s<n; s++) {
        iaps = fs.APS[s];
        nbr = fs.APS[s+1] - fs.APS[s];
        for (int j=iaps; j<iaps+nbr; j++) {
            la.tabAdj[s] = inserQueue(fs.FS[j], la.tabAdj[s]);
        }
    }
    return la;
}

/**
 * Construit une File de successeur à partir d'une liste d'adjacence
 * @param la La liste d'adjacence initiale
 * @return La File de successeur resultante
 */
FileSuccesseur convertLAtoFS(ListeAdjacence la) {
    int n = la.nbSom;
    FileSuccesseur fs;
    allocFS(n, n*2, &fs);
    int iaps;
    Liste tmp;
    int s;
    for (s=0; s<n; s++) {
        iaps = s;
        fs.APS[s] = iaps;
        tmp = la.tabAdj[s];
        while (!estVide(tmp)) {
            fs.FS[iaps] = donnee(la.tabAdj[s]);
            iaps++;
            tmp = suivant(tmp);
        }
    }
    fs.APS[s] = iaps;       // Sommets virtuels
    fs.FS[iaps] = 0;
    return fs;
}

/**
 * Convertit une matrice d'incidence à partir d'une matrice d'adjacence
 * @param ma la matrice d'adjacence initial
 * @return la matrice d'incidence résultante
 */
MatIncidence convertMAtoMI(MatAdjacence ma) {
    int nbSom = ma.nbSom;
    int nbArcs = countArc(ma);
    MatIncidence matI = alloc_SMI_F(nbSom, nbArcs);
    int currentArc = 0;
    for (int s=0; s<nbSom; s++) {
        for (int t=0; t<nbSom; t++) {
            if (ma.mat[s][t] == 1) {
                matI.mat[s][currentArc] = +1;
                matI.mat[t][currentArc] = -1;
                currentArc++;
            }
        }
    }
    return matI;
}