/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
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
 * 
 */
static void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
 * \fn partition(int *array, int p, int r)
 * \brief place tous les éléments inférieurs à p à sa gauche et tous les autres, donc 
 * supérieurs, à sa droite
 * 
 * \param array un pointeur vers un tableau d'entier dans lequel faire les permutations
 * \param p un entier définissant la borne_inf de l'intervale sur lequel 
 * partitionner le tableau
 * \param r un entier définissant la borne_sup de l'intervale sur lequel 
 * partitionner le tableau
 * 
 * \pre /
 * \post soit R le nouvel emplacement du pivot, 
 * array[p...R-1]<=array[R]&&array[R+1...r]>array[r]
 */
static int partition(int *array, int p, int r){
    int i = p-1;
    for(int j = p; j<r; j++){
        if(array[j]<=array[r]){
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i+1, r);

    return i+1;
}

/**
 * \fn quicksort(int *array, int p, int r)
 * \brief applique la technique du quicksort, donc crée un pivot et place 
 * les valeurs à gauche et à droite du pivot avant de refaire appel à cette fonction sur 
 * les tableaux se trouvant de part et d'autre du pivot
 * 
 * \param array un pointeur vers un tableau d'entier dans lequel faire les permutations
 * \param p un entier définissant la borne_inf de l'intervale sur lequel appliquer le quicksort 
 * sur la tableau array
 * \param r un entier définissant la borne_sup de l'intervale sur lequel appliquer le quicksort 
 * sur la tableau array
 * 
 * \pre array[a] = array[a]_init && array[b] = array[b]_init
 * \post array[a] = array[b]_init && array[b] = array[a]_init
 * 
 */
static void quicksort(int *array, int p, int r){
    int position_pivot;
    if(p<r){
        position_pivot = partition(array, p, r);
        quicksort(array, p, position_pivot-1);
        quicksort(array, position_pivot+1, r);
    }
}

void sort(int *array, size_t length){
    if(!array)
        return;

    quicksort(array, 0, length-1);

}