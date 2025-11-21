#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permutation(int indice1, int indice2, int *tab) {
    int tmp = *(tab+indice1);
    *(tab+indice1) = *(tab+indice2);
    *(tab+indice2) = tmp;
}

int partitionner(int ind_inf, int ind_sup, int *tab) {
    int indPivot = ind_inf;
    int pivot = *(tab+indPivot);
    int l=ind_inf+1;
    int k=ind_sup;
    while (l<=k) {
        if (*(tab+l)<=pivot) {
            l++;
        }
        else {
            if (*(tab+k)>pivot) {
                k--;
            }
            else {
                if (l<k) {
                    permutation(l, k, tab);
                    l++;
                    k--;
                }
            }
        }
    }
    if (indPivot != k) {
        permutation(indPivot, k, tab);
    }
    return k;
}

int partitionner2(int ind_inf, int ind_sup, int *tab) {
    int ind_pivot=ind_inf;
    int pivot = *(tab+ind_pivot);
    int l = ind_inf+1;
    int k = ind_sup;
    while (l<=k) {
        while ((l<=k) && (*(tab+l)<=pivot)) {
            l++;
        }
        while ((l<=k) && (*(tab+1)<pivot)) {
            k--;
        }
        if (l<k) {
            l++;
            k--;
        }
    }
    if (ind_pivot!=k) {
        permutation(ind_pivot,k,tab);
    }
    return k;
}

void triRapide(int ind_inf, int ind_sup, int *tab) {
    if (ind_inf<ind_sup) {
        int indPivot = partitionner2(ind_inf, ind_sup, tab);
        triRapide(ind_inf, indPivot-1, tab);
        triRapide(indPivot+1, ind_sup, tab);
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
    printf("Le tableau avant le tri : \n");
    printTab(tab, 8);
    printf("\n");
    triRapide(0,7,tab);
    printf("Le tableau apres le tri : \n");
    printTab(tab, 8);
}

void exo1b() {
    int n;
    printf("Merci d'indiquer une taille pour votre tableau.\n");
    scanf("%d", &n);
    int *tab = malloc(n * sizeof(int));
    printf("Merci d'indiquer les valeurs de votre tableau à la suite\n");
    for (int i=0; i<n; i++) {
        scanf("%d",tab+i);
    }
    printf("Le tableau que vous avez entre : \n");
    printTab(tab, n);
    printf("\n");
    triRapide(0,n-1,tab);
    printf("Le tableau trie : \n");
    printTab(tab, n);
}

void exo2a() {
    int n = rand() % 100 + 100;
    int *tab = randomTab(n);
    printf("Le tableau genere aleatoirement : \n");
    printTab(tab, n);
    printf("\n");
    triRapide(0,n-1,tab);
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
    for (int i=0; i<n; i++) {
        fscanf(f, "%d", tab+i);
    }
    printf("Le tableau cree a partir du fichier : \n");
    printTab(tab, n);
    printf("\n");
    triRapide(0,n-1,tab);
    printf("Le tableau trie : \n");
    printTab(tab, n);
    free(tab);
    tab=NULL;
}

void exo3() {
    FILE *f = fopen("../data/resultRapide.txt", "w");
    int n=0;
    double t;
    int *tab, *tmp1, *tmp2;
    int i;
    for (i=0; i<40; i++) {
        n=n+10000;
        tab = randomTab(n);
        clock_t start = clock();
        triRapide(0,n-1,tab);
        clock_t end = clock();
        t = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(f, "%d %f\n", n, t);
    }
    free(tab); tab=NULL;
    fclose(f);
    printf("Tris realises avec succes, resultats dans data/resultRapide.txt");
}

void main() {
    srand(time(NULL));
    //exo1a();
    //exo1b();
    //exo2a();
    //exo2b();
    exo3();

}