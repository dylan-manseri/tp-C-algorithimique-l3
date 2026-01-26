/**
 * Je ne sais pas vraiment comment organiser les fichiers du cours.
 * Donc ici ça sera tous les algos traitant des successeurs et prédécesseurs.
 */

#include "../structure.h"

/**
 * On va prendre print pour l'exemple mais on peut mettre n'importe quoi
 * Ici notre représentation est la matrice adjacence
 */
void traitSuccMatAdj(int s, MatAdjacence g){
    s--;
    int n = nbSom(g);
    int *tab = malloc(n * sizeof(int));
    int j=0;
    for(int i=0; i<n; i++){
        if(g.mat[s][i] == 1){
            tab[j] = i+1; 
        }
        else{
            tab[j] = 0;
        }
        j++;
    }
    printf("\n|");
    for(int k=0; k<j; k++){
        printf(" %d |", tab[k]);
    }
}

/**
 * Ici pareil on cherche seulement à traiter les successeurs D'UN sommets.
 * On utilise la représentation avec la file de successeur.
 */
void traitSuccFS(int s, FileSuccesseur fs){
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
    printf("\n|");
    for(int l=0; l<nb; l++){
        printf(" %d |", tab[l]);
    }
}

void traitSuccL(int s, ListeAdjacence la){
    s--;
    Liste succ = la.tabAdj[s];
    int* tab = malloc(la.nbSom * sizeof(struct cel));
    int i=0;
    while(!estVide(succ)){
        tab[i] = donnee(succ);
        succ = suivant(succ);
        i++;
    }
    printf("\n|");
    for(int k=0; k<i; k++){
        printf(" %d |", tab[k]);
    }
}