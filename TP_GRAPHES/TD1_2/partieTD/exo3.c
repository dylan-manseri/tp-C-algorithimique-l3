/**
 * Je ne sais pas vraiment comment organiser les fichiers du cours.
 * Donc ici ça sera tous les algos de l'exo 3.
 */

#include <stdlib.h>
#include "../../include/prototypeTD12.h"

/**
 * On va prendre print pour l'exemple, mais on peut mettre n'importe quoi
 * Ici notre représentation est la matrice adjacence.
 */
int* getSuccMatAdj(int s, MatAdjacence g){
    int n = nbSom(g);
    int *tab = malloc(n+1 * sizeof(int));
    int j=0;
    int i;
    for(i=0; i<n; i++){
        if(g.mat[s][i] == 1){
            tab[j] = i;
        }
        else{
            tab[j] = 0;
        }
        j++;
    }
    tab[0] = i;
    return tab;
}

int* getPredMatAdj(int s, MatAdjacence g){
    s--;
    int n = nbSom(g);
    int j=0;
    int *tab = malloc(n+1 * sizeof(int));
    int i;
    for(i=1; i<n; i++){
        if(g.mat[i][s] == 1){
            tab[j] = 1;
        }
        else{
            tab[j] = 0;
        }
        j++;
    }
    tab[0] = i;
    return tab;
}

/**
 * Ici pareil on cherche seulement à traiter les successeurs D'UN sommets.
 * On utilise la représentation avec la file de successeur.
 */
int* getSuccFS(int s, FileSuccesseur fs){
    s--;                        // On soustrait car sommet logique = sommet algorithmique +1
    int start = fs.APS[s];
    int end = fs.APS[s+1];
    int nb = end - start;
    int *tab = malloc(nb * sizeof(int));
    int k=0;
    for(int i=start; i<end; i++){
        tab[k] = fs.FS[i];
        k++;
    }
    return tab;
}

int* getPredFS(int s, FileSuccesseur fs){     // Pas besoin de soustraire s, on ne s'en sert pas comme indice mais comme contenu
    int nbArcs = fs.nbArcs;
    int nbrSom;
    int k = 0;
    int *tab = malloc(fs.nbSom * sizeof(int));
    for(int i=0; i<fs.nbSom; i++){
        for(int j=fs.APS[i]; j<fs.APS[i+1]; j++){
            if(fs.FS[j] == s){
                tab[k] = k+1;
            }
            else{
                tab[k] = 0;
            }
            k++;
        }
    }
    return tab;
}

int* getSuccL(int s, ListeAdjacence la){
    s--;
    Liste succ = la.tabAdj[s];
    int* tab = malloc(la.nbSom * sizeof(int));
    int i=0;
    while(!estVide(succ)){
        tab[i] = donnee(succ);
        succ = suivant(succ);
        i++;
    }
    return tab;
}

int* getPredL(int s, ListeAdjacence la){
    Liste* tabL = la.tabAdj;
    int *tab = malloc(la.nbSom * sizeof(int));
    Liste iSucc;
    int k = 0;
    for(int i=0; i<la.nbSom; i++){
        iSucc = tabL[i];
        while(!estVide(iSucc)){
            if(donnee(iSucc) == s){
                tab[k] = i+1;
                k++;
            }
            iSucc = suivant(iSucc);
        }
    }
    return tab;
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
            if(fs.FS[j] == i+1){
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
        /*while(!trouve && !estVide(succ)){
            if(donnee(succ) == i){
                trouve=1;
            }
            succ=suivant(succ);
        }*/
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
            max=i+1;
        }
    }
    return max;
}