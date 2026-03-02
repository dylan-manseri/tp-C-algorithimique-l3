/**
 * Je ne sais pas vraiment comment organiser les fichiers du cours.
 * Donc ici ça sera tous les algos de l'exo 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/prototypeTD12.h"

/**
 * Le tableau est bizarre, et c'est un choix, l'indice 0 stocke le nombre de successeurs
 */
int* getSuccMatAdj(int s, MatAdjacence g){
    int n = nbSomMA(g);
    int *tab = malloc((n+1) * sizeof(int));
    int j=1;
    int i;
    for(i=0; i<n; i++){
        if(g.mat[s][i] == 1){
            tab[j] = i;
            j++;
        }
    }
    tab[0] = j-1;
    return tab;
}

int* getPredMatAdj(int s, MatAdjacence g){
    int n = nbSomMA(g);
    int j=1;
    int *tab = malloc((n+1) * sizeof(int));
    for(int i=0; i<n; i++){
        if(g.mat[i][s] == 1){
            tab[j] = i;
            j++;
        }
    }
    tab[0] = j-1;
    return tab;
}

/**
 * Ici pareil, on cherche seulement à traiter les successeurs D'UN sommets.
 * On utilise la représentation avec la file de successeur.
 * Le premier indice indique la taille du tableau
 */
int* getSuccFS(int s, FileSuccesseur fs){
    int start = fs.APS[s];
    int end = fs.APS[s+1];
    int nb = end - start;
    int *tab = malloc((nb+1) * sizeof(int));
    int k=1;
    for(int i=start; i<end; i++){
        tab[k] = fs.FS[i];
        k++;
    }
    tab[0] = k-1;
    return tab;
}

int* getPredFS(int s, FileSuccesseur fs){
    int l = 1;
    int *tab = malloc((fs.nbSom+1) * sizeof(int));
    for(int i=0; i<fs.nbSom; i++){
        for(int j=fs.APS[i]; j<fs.APS[i+1]; j++){
            if(fs.FS[j] == s){
                tab[l] = i;
                l++;
            }
        }
    }
    tab[0] = l-1;
    return tab;
}

int* getSuccL(int s, ListeAdjacence la){
    Liste succ = la.tabAdj[s];
    int* tab = malloc((la.nbSom+1) * sizeof(int));
    int i=1;
    while(!estVide(succ)){
        tab[i] = donnee(succ);
        succ = suivant(succ);
        i++;
    }
    tab[0] = i-1;
    return tab;
}

int* getPredL(int s, ListeAdjacence la){
    Liste* tabL = la.tabAdj;
    int *tab = malloc((la.nbSom+1) * sizeof(int));
    Liste iSucc;
    int k = 1;
    for(int i=0; i<la.nbSom; i++){
        iSucc = tabL[i];
        while(!estVide(iSucc)){
            if(donnee(iSucc) == s){
                tab[k] = i;
                k++;
            }
            iSucc = suivant(iSucc);
        }
    }
    tab[0] = k-1;
    return tab;
}

/**
 * Renvoi un tableau des successeurs dépendamment du type du graphe (via généricité)
 * Le premier indice du tableau est le nombre de successeurs
 * @param s Le sommet dont on souhaite connaître les successeurs
 * @param type Le type de graphe
 * @return Le tableau des successeurs
 */
int* getSuccByType(int s, TypeGraphe type, void* g) {
    int* succ;
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        succ = getSuccMatAdj(s, *mat);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* fs = (FileSuccesseur*) g;
        succ = getSuccFS(s, *fs);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* la = (ListeAdjacence*) g;
        succ = getSuccL(s, *la);
    }
    else {
        printf("\nErreur de type");
        exit(1);
    }
    return succ;
}

/**
 * Même chose pour les prédécesseurs
 * @param s Le sommet dont on souhaite connaître les prédécesseurs
 * @param type Le type de graphe
 * @param g Le graphe
 * @return Le tableau des prédécesseurs
 */
int* getPredByType(int s, TypeGraphe type, void* g) {
    int* succ;
    if (type == MAT_ADJACENCE) {
        MatAdjacence* mat = (MatAdjacence*) g;
        succ = getPredMatAdj(s, *mat);
    }
    else if (type == FILE_SUCCESSEUR) {
        FileSuccesseur* fs = (FileSuccesseur*) g;
        succ = getPredFS(s, *fs);
    }
    else if (type == LISTE_ADJACENCE) {
        ListeAdjacence* la = (ListeAdjacence*) g;
        succ = getPredL(s, *la);
    }
    else {
        printf("\nErreur de type");
        exit(1);
    }
    return succ;
}

/**
 * Vérifie si un graphe contient une boucle
 * @param ma
 * @return
 */
int estBoucleMA(MatAdjacence ma){
    int i=0;
    int trouve = 0;
    while(!trouve && i<ma.nbSom){
        if(ma.mat[i][i] == 1){
            trouve = 1;
        }
        i++;
    }
    return trouve;
}

int estBoucleFS(FileSuccesseur fs){
    int trouve = 0;
    int i=0, j;
    while(!trouve && i<fs.nbSom){
        j=fs.APS[i];
        while(!trouve && j<fs.APS[i+1]){
            if(fs.FS[j] == i){
                trouve = 1;
            }
            j++;
        }
        i++;
    }
    return trouve;
}

int estBoucleLA(ListeAdjacence la){
    int i=1;
    int trouve=0;
    Liste* tabL = la.tabAdj;
    Liste succ;
    while(!trouve && i<la.nbSom){
        succ=tabL[i];
        while(!estVide(succ) && donnee(succ)<i){
            succ=suivant(succ);
        }
        if(!estVide(succ) && donnee(succ) == i){
            trouve=1;
        }
        i++;
    }
    return trouve;
}

/**
 * Recherche le sommet avec le plus de successeurs
 * @param mat
 * @return
 */
int maxSuccMA(MatAdjacence mat){
    int n = mat.nbSom;
    int** matrice = mat.mat;
    int current;
    int maxSucc = 0;
    int somMax = 0;
    for(int s=0; s<n; s++){
        current=0;
        for(int t=0; t<n; t++){
            if(matrice[s][t] == 1) current++;
        }
        if(current > maxSucc){
                maxSucc = current;
                somMax = s+1;
            }
    }
    return somMax;
}

int maxSuccFS(FileSuccesseur fs){
    int n=fs.nbSom;
    int max=0;
    int maxSucc=0;
    int current;
    for(int i=0; i<n; i++){
        current = fs.APS[i+1] - fs.APS[i];
        if(current > maxSucc){
            maxSucc=current;
            max=i+1;
        }

    }
    return max;
}

int maxSuccLA(ListeAdjacence la){
    int max=0;
    int maxSucc=0;
    Liste* tabL = la.tabAdj;
    int n = la.nbSom;
    Liste succ;
    int current;
    for(int i=0; i<n; i++){
        succ = tabL[i];
        current=0;
        while(!estVide(succ)){
            current++;
            succ=suivant(succ);
        }
        if(current>maxSucc){
            maxSucc=current;
            max=i;
        }
    }
    return max;
}