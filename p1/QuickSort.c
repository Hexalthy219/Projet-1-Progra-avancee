/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include "Sort.h"

static void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

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

static void quicksort(int *array, int p, int r){
    int position_pivot;
    if(p<r){
        position_pivot = partition(array, p, r);
        quicksort(array, p, position_pivot-1);
        quicksort(array, position_pivot+1, r);
    }
}

static void affichage(int *array, int length){
    for(int i=0; i<length; i++)
        printf("%d\t", array[i]);
    printf("\n\n");
}

void sort(int *array, size_t length){
    if(!array)
        return;

    quicksort(array, 0, length-1);

}