/* ========================================================================= *
 * PlaceSort
 * Implementation of the PlaceSort algorithm.
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
 */
static void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void sort(int *array, size_t length){
    if(!array||length<2)
        return;

    size_t i = 0, m;
    while(i<length){
        m = 0;
        //Calcul la position de array[i] en le comparant à tous les 
        //éléments de array
        for(size_t j = 0; j<length; j++){
            if(array[i]>array[j])
                m++;
        }

        /*si nécessaire permute l'élément de la case i avec l'élément se trouvant
        à la position m, étant la position où est censé se trouver l'élément 
        i si array était trié*/
        if (m!=i){
            //gere le cas particulier où il y a plusieurs fois
            //la même valeur dans array
            if (array[i]==array[m]){
                while (array[i]==array[m])
                    m++;
                swap(array, i, m);
                i++;
            }
            else
                swap(array, i, m);
        }
        else
            i++;
    }
}