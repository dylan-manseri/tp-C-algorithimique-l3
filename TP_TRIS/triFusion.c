#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int VMAX = 1000000;

int indiceMilieu(int n) {
    return n/2;
}
/*--------------------------ALGORITHMES DE TRI--------------------------*/
/*void fusion(int * tab, int *tmp, int debut, int ind_mil, int fin) {   //Ma version, plus coûteuse que celle du prof
    int i=debut;
    int j=ind_mil + 1;
    int k = debut;
    while (i<=ind_mil && j<=fin) {
        if (tab[i]<tab[j]) {
            *(tmp+k) = *(tab+i);
            i++;
        }
        else {
            *(tmp+k) = *(tab+j);
            j++;
        }
        k++;
    }
    while (j<=fin) tmp[k++]=tab[j++];
    while (i<=ind_mil) tmp[k++]=tab[i++];
    for (int l=debut; l<=fin; l++) {
        tab[l] = tmp[l];
    }
}*/

void copie(int *tab, int indInf, int indSup, int *tmp) {
    int j=0;
    for (int i=indInf; i<indSup+1; i++) {
        *(tmp+j) = *(tab+i);
        j++;
    }
}

void fusion(int *tab, int indInf, int indMil, int indSup, int *tmp1, int *tmp2) {
    copie(tab, indInf, indMil, tmp1);
    copie(tab, indMil+1, indSup, tmp2);
    tmp1[indMil-indInf+1] = VMAX;
    tmp2[indSup-indMil] = VMAX;
    int i=0;
    int j=0;
    for (int k=indInf; k<=indSup; k++) {
        if (*(tmp1+i) < *(tmp2+j)) {
            *(tab+k) = *(tmp1+i);
            i++;
        }
        else {
            *(tab+k) = *(tmp2+j);
            j++;
        }
    }

}

void triFusion(int *tab, int indMin, int indSup, int *tmp1, int *tmp2) {
    if (indMin<indSup) {
        int indMil = indiceMilieu(indMin+indSup);
        triFusion(tab, indMin, indMil, tmp1, tmp2);
        triFusion(tab, indMil+1, indSup, tmp1, tmp2);
        fusion(tab, indMin, indMil, indSup, tmp1, tmp2);
    }
}
/*--------------------------UTILITAIRES--------------------------*/

int* randomTab(int n) {
    int *tab = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        *(tab+i) = (rand() % 100) + 100;
    }
    return tab;
}

void printTab(int *tab, int n) {
    printf("{ ");
    for (int i=0; i<n; i++) {
        printf("%d ", *(tab+i));
    }
    printf("}\n");
}

/*--------------------------EXERCICES--------------------------*/
void exo1a(){
    int tab[8] = {7,8,3,5,9,1,1,8};
    int *tmp1 = malloc(8 * sizeof(int));
    int *tmp2 = malloc(8 * sizeof(int));
    printf("Le tableau avant le tri : \n");
    printTab(tab, 8);
    printf("\n");
    triFusion(tab, 0, 7, tmp1, tmp2);
    printf("Le tableau apres le tri : \n");
    printTab(tab, 8);
}

void exo1b() {
    int n;
    printf("Merci d'indiquer une taille pour votre tableau.\n");
    scanf("%d", &n);
    int *tab = malloc(n * sizeof(int));
    int *tmp1 = malloc(n * sizeof(int));
    int *tmp2 = malloc(n * sizeof(int));
    printf("Merci d'indiquer les valeurs de votre tableau à la suite\n");
    for (int i=0; i<n; i++) {
        scanf("%d",tab+i);
    }
    printf("Le tableau que vous avez entre : \n");
    printTab(tab, n);
    printf("\n");
    triFusion(tab, 0, n-1, tmp1, tmp2);
    printf("Le tableau trie : \n");
    printTab(tab, n);
}

void exo2a() {
    int n = rand() % 100 + 100;
    int *tab = randomTab(n);
    int *tmp1 = malloc(n * sizeof(int));
    int *tmp2 = malloc(n * sizeof(int));
    printf("Le tableau genere aleatoirement : \n");
    printTab(tab, n);
    printf("\n");
    triFusion(tab, 0, n-1, tmp1, tmp2);
    printf("Le tableau trie : \n");
    printTab(tab, n);
    free(tab);
    tab=NULL;
}

void exo2b() {
    int n;
    FILE *f = fopen("../data/donnees.txt", "r");
    fscanf(f, "%d", &n);
    int *tab = malloc(n * sizeof(int));
    int *tmp1 = malloc(n * sizeof(int));
    int *tmp2 = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        fscanf(f, "%d", tab+i);
    }
    printf("Le tableau cree a partir du fichier : \n");
    printTab(tab, n);
    printf("\n");
    triFusion(tab, 0, n-1, tmp1, tmp2);
    printf("Le tableau trie : \n");
    printTab(tab, n);
    free(tab);
    tab=NULL;
}

void exo3() {
    FILE *f = fopen("../data/resultFusion.txt", "w");
    int n=0;
    double t;
    int *tab, *tmp1, *tmp2;
    int i;
    for (i=0; i<40; i++) {
        n=n+10000;
        tab = randomTab(n);
        tmp1 = malloc(n * sizeof(int));
        tmp2 = malloc(n * sizeof(int));
        clock_t start = clock();
        triFusion(tab,0, n-1, tmp1, tmp2);
        clock_t end = clock();
        t = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(f, "%d %f\n", n, t);
        free(tab); tab=NULL;
    }
    fclose(f);
    printf("Tris realises avec succes, resultats dans data/resultFusion.txt");
}

void main() {
    srand(time(NULL));
    //exo1a();
    //exo1b();
    //exo2a();
    //exo2b();
    exo3();

}
