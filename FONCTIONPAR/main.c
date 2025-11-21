#include <math.h>

#include "structure.h"
int VMAX=-1;
int somme(int a, int b) {
    return a+b;
}

int produit(int a, int b) {
    return a*b;
}

int division(int a, int b) {
    return a/b;
}

void printTab(int *tab, int n) {
    printf("{ ");
    for (int i=0; i<n; i++) {
        printf("%d ", *(tab+i));
    }
    printf("}\n");
}

void printTabComplexe(Complexe *tab, int n) {
    printf("{ ");
    for (int i=0; i<n; i++) {
        printf("{%d, %d}", (*(tab+i)).pr, (*(tab+i)).pi);
    }
    printf("}\n");
}

int recherche(int n, int *tab, int elt, Fcomp comp) {
    int i;
    tab[n]=elt;
    i=0;
    while (!(*comp)(elt,tab[i])) {
        i++;
    }
    return i<n;
}

int estInferieur(int i, int j) {
    return i<j;
}
int estSuperieur(int i, int j) {
    return i>j;
}

int indiceMilieu(int n) {
    return n/2;
}

int estInferieurComp(Complexe i, Complexe j) {
    double z1 = sqrt(i.pr*i.pr+i.pi*i.pi);
    double z2 = sqrt(j.pr*j.pr+j.pi*j.pi);
    return z1<z2;
}
int estSuperieurComp(Complexe i, Complexe j) {
    double z1 = sqrt(i.pr*i.pr+i.pi*i.pi);
    double z2 = sqrt(j.pr*j.pr+j.pi*j.pi);
    return z1>z2;
}

void copie(int *tab, int indInf, int indSup, int *tmp) {
    int j=0;
    for (int i=indInf; i<indSup+1; i++) {
        *(tmp+j) = *(tab+i);
        j++;
    }
}

void fusion(int *tab, int indInf, int indMil, int indSup, int *tmp1, int *tmp2, Fcomp fcomp) {
    copie(tab, indInf, indMil, tmp1);
    copie(tab, indMil+1, indSup, tmp2);
    tmp1[indMil-indInf+1] = VMAX;
    tmp2[indSup-indMil] = VMAX;
    int i=0;
    int j=0;
    for (int k=indInf; k<=indSup; k++) {
        if ((*fcomp)(*(tmp1+i), *(tmp2+j))) {
            *(tab+k) = *(tmp1+i);
            i++;
        }
        else {
            *(tab+k) = *(tmp2+j);
            j++;
        }
    }
}

void triFusion(int *tab, int indMin, int indSup, int *tmp1, int *tmp2, Fcomp fcomp) {
    if (indMin<indSup) {
        int indMil = indiceMilieu(indMin+indSup);
        triFusion(tab, indMin, indMil, tmp1, tmp2, fcomp);
        triFusion(tab, indMil+1, indSup, tmp1, tmp2, fcomp);
        fusion(tab, indMin, indMil, indSup, tmp1, tmp2, fcomp);
    }
}

int main(void) {
    //Fcomp tabFonc[3] = {somme, produit, division};
    int tab[10] = {8,4,6,9,7,2,8,4,1,2};
    int n=10;
    printTab(tab, 10);
    int *tmp1=malloc(n*sizeof(int));
    int *tmp2=malloc(n*sizeof(int));
    triFusion(tab, 0, n-1,tmp1, tmp2, estSuperieur);
    printTab(tab, n);
    VMAX=100;
    triFusion(tab, 0, n-1,tmp1, tmp2, estInferieur);
    printTab(tab, n);
    Complexe tabC[5]= {{10,5}, {5,6},{8,9},{2,3},{4,3}};
    printTabComplexe()

}