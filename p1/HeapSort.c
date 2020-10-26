/* ========================================================================= *
 * HeapSort
 * Implementation of the HeapSort algorithm.
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

/**
 * \fn max_heapify(int *array, int i, int length)
 * \brief Permet de réparer le noeud d'un arbe dont le père est l'élément à la case i du tableau
 * 
 * \param array un pointeur vers un tableau d'entier qui est l'arbre à réparer
 * \param i un entier étant l'indice du noeud à réparer
 * \param length un entier étant la longueur maximal du tableau
 * 
 * \pre array init && i>=0 && length>1
 * \post Le noeud à la position i a été réparé
 */
static void max_heapify(int *array, int i, int length){
    int left = i*2+1;
    int right = i*2+2;
    int largest;
    if(left<=length && array[left]>array[i])
        largest = left;
    else
        largest = i;
    if(right<=length && array[right]>array[largest])
        largest = right;
    if(largest!=i){
        swap(array, i, largest);
        max_heapify(array, largest, length);
    }
}
/**
 * \fn build_max_heap(int *array, int length)
 * \brief Transforme le tableau array en arbre si c'est pas déjà le cas
 * 
 * \param array un pointeur vers le tableau d'entier qui doit être transformé en arbre
 * \param length un entier étant la longueur maximal du tableau
 * 
 * \pre array init && length>1
 * \post Le tableau a été transformé en arbre
 */
static void build_max_heap(int *array, int length){
    int i = length;
    int fin = 1;
    while(fin){
        max_heapify(array, i, length);
        if(i==0)
            fin=0;
        i/=2;
    }
}


void sort(int *array, size_t length){
    if(!array||length<2)
        return;


    build_max_heap(array, length-1);
    while(length>=1){
        swap(array, length-1, 0);
        length--;
        max_heapify(array, 0, length-1);
    }
}