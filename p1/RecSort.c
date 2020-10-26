/* ========================================================================= *
 * RecSort
 * Implementation of the RecSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <limits.h>
#include "Sort.h"

/**
 * \fn swap(int *array, int a, int b)
 * \brief permute les éléments de array se trouvant aux indices a et b
 * 
 * \param array un pointeur vers un tableau d'entier dans lequel faire les permutations
 * \param a un entier étant le premier indice des éléments à permuter
 * \param b un entier étant le deuxième indice des éléments à permuter
 * 
 * \pre array[a] = array[a]_init && array[b] = array[b]_init
 * \post array[a] = array[b]_init && array[b] = array[a]_init
 */
static void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
 * \fn place(int *array, int p, int r)
 * \brief permute la dernière case de l'intervale [p,r] à sa position correcte si 
 * le sous tableau [p...r] était trié et retourne cette valeur
 * 
 * \param array un pointeur vers un tableau d'entier dans lequel faire les permutations
 * \param p un entier étant la borne_inf de l'intervalle sur lequel chercher la place du pivot
 * \param r un entier étant la borne_sup de l'intervalle sur lequel chercher la place du pivot * 
 * 
 * \pre /
 * \post array[r] se trouve à sa position exact dans l'intervalle [p,r]
 */
static int place(int *array, int p, int r){
    int m = 0;
    //calcul la position relative au sous tableau allant de p à r pour le pivot r dans cet intervalle
    for(int i = p; i<r; i++){
        if(array[i]<array[r])
            m++;
    }
    //l est l'indice réel dans le tableau array
    int l = m+p;
    swap(array, r, l);

    return l;
}

/**
 * \fn merge(int *array, int borne_inf, int pivot, int borne_sup)
 * \brief permute la dernière case de l'intervale [p,r] à sa position correcte si 
 * le sous tableau [p...r] était trié et retourne cette valeur
 * 
 * \param array un pointeur vers un tableau d'entier dans lequel faire les permutations
 * \param borne_inf un entier étant la borne inférieur de l'intervalle sur lequel appliquer le merge
 * \param borne_inf un entier étant la borne inférieur de l'intervalle sur lequel appliquer le merge
 * \param pivot un entier étant le pivot délimitant les 2 sous tableaux de l'intervalle [borne_inf, borne_sup]
 * 
 * \pre /
 * \post array[r] se trouve à sa position exact dans l'intervalle [p,r]
 */
static void merge(int *array, int borne_inf, int pivot, int borne_sup){
    int tailleL = pivot-borne_inf+1, tailleR = borne_sup-pivot+1;
    int i, j = 0, k = borne_inf;
    int R[tailleR], L[tailleL];

    //initialisation du tableau intermédaire de gauche
    for(i = 0; i<tailleL-1; i++)
        L[i] = array[i+borne_inf];
    L[tailleL-1] = INT_MAX;

    //initialisation du tableau intermédiaire de droite
    for (i = 0; i<tailleR-1; i++)
        R[i] = array[pivot+1+i];
    R[tailleR-1] = INT_MAX;

    //fusion des 2 sous tableaux trié dans array
    i=0;
    while (k<=borne_sup){
        if(R[i]<L[j]){
            array[k]=R[i];
            i++;
        }
        else{
            array[k]=L[j];
            j++;
        }

        k++;
        if(k==pivot)
            k++;
    }
}

/**
 * \fn recsort(int *array, int p, int r)
 * \brief applique la technique du recsort, donc place le pivot à la bonne place
 * puis apllique le recsort récusivement sur les tableaux à gauche et à droite du pivot
 * puis fusionne les deux tableaux par la technique du mergesort
 * 
 * \param array un pointeur vers un tableau d'entier dans lequel faire les permutations
 * \param borne_inf un entier étant la borne inférieur de l'intervalle sur lequel appliquer le merge
 * \param borne_inf un entier étant la borne inférieur de l'intervalle sur lequel appliquer le merge
 * \param pivot un entier étant le pivot délimitant les 2 sous tableaux de l'intervalle [borne_inf, borne_sup]
 * 
 * \pre /
 * \post array[r] se trouve à sa position exact dans l'intervalle [p,r]
 */
static void recsort(int *array, int p, int r){
    if(p<r){
        int q = place(array, p, r);
        recsort(array, p, q-1);
        recsort(array, q+1, r);
        if(((q-p)>0)&&((r-q)>0))
            merge(array, p, q, r);
    }
}

void sort(int *array, size_t length){
    if(!array||length<2)
        return;

    recsort(array, 0, length-1);
}