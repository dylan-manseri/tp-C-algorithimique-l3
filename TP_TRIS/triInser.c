#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--------------------------ALGORITHMES DE TRI--------------------------*/
void triInser(int *tab, int n) {
    int carte, j;
    for (int i=1; i<n; i++) { //On réalise un parcours dans la partie NON TRIE, on suppose i=0 déjà trié
        carte=*(tab+i); //On définit notre carte
        j=i-1;  //On place notre index à la fin du tableau déjà trié
        while (j>=0 && (*(tab+j) > carte)) {   //On parcourt le sous-tableau trié pour trouver la place d'insertion
            *(tab+j+1)=*(tab+j);
            j--;    //On fait le parcourt de droite à gauche
        }
        *(tab+j+1) = carte; //On réalise l'insertion
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

void printTab(int* tab, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", *(tab+i));
    }
    printf("\n\n");
}

/*--------------------------EXERCICES--------------------------*/
void exo1a(){
    int tab[5] = {8,3,2,10,7};
    printf("Le tableau avant le tri : \n");
    printTab(tab, 5);
    printf("\n");
    triInser(tab, 5);
    printf("Le tableau apres le tri : \n");
    printTab(tab, 5);
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
    triInser(tab, n);
    printf("Le tableau trie : \n");
    printTab(tab, n);
    free(tab);
    tab=NULL;
}

void exo2a() {
    int *tab;
    int n = rand() % 100 + 100;
    tab=randomTab(n);
    printf("Le tableau genere aleatoirement : \n");
    printTab(tab, 5);
    printf("\n");
    triInser(tab, n);
    printf("Le tableau trie : \n");
    printTab(tab, 5);
    free(tab);
    tab=NULL;
}

void exo2b() {
    int n;
    FILE *f = fopen("data/donnees.txt", "r");
    fscanf(f, "%d", &n);
    int *tab = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        fscanf(f, "%d", tab+i);
    }
    printf("Le tableau cree a partir du fichier : \n");
    printTab(tab, n);
    printf("\n");
    triInser(tab, n);
    printf("Le tableau trie : \n");
    printTab(tab, n);
    free(tab);
    tab=NULL;
}

void exo3() {
    FILE *f = fopen("../data/resultInser.txt", "w");
    int n=0;
    double t;
    int *tab;
    int i;
    for (i=0; i<40; i++) {
        tab = randomTab(n=n+1000); //Obligé de mettre une petite valeur car c'est trop long
        clock_t start = clock();
        triInser(tab, n);
        clock_t end = clock();
        t = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(f, "%d %f\n", n, t);
        free(tab);
        tab=NULL;
    }
    fclose(f);
    printf("Tris realises avec succes, resultats dans data/resultInser.txt");
}

int main(void) {
    srand(time(NULL));
    //exo1a();
    //exo1b();
    //exo2a();
    //exo2b();
    exo3();
}