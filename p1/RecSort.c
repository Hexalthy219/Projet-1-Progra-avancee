/* ========================================================================= *
 * RecSort
 * Implementation of the RecSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include "Sort.h"

static void affichage(int *array, size_t length)
{
    for (size_t i = 0; i < length; i++)
        printf("%d\t", array[i]);
    printf("\n\n");
}

static void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

static size_t place(int *array, size_t p, size_t r){
    size_t m = 0;
    for(size_t i=p; i<r; i++){
        if(array[i]<array[r])
            m++;
    }
    size_t l=m+p;
    swap(array, r, l);

    return l;
}

static void merge(int *array, size_t p, size_t q, size_t r){
    int L[q-p+1], R[r-q+1];

    for(size_t i = 0; i<q-p; i++)
        L[i] = array[p+i];

    for (size_t i = 0; i<r-q; i++)
        R[i] = array[q+i+1];
    
    R[q-p] = INT_MAX; L[r-q] = INT_MAX;

    for(size_t i = 0, j = 0, k = p; (k<r); k++){
        if(k==q)
            k++;
        if(L[i]<=R[j]){
            array[k]=L[i];
            i++;
        }
        else{
            array[k]=R[j];
            j++;
        }
    }
}

static void recsort(int *array, size_t p, size_t r){
    if(p<r){
        size_t q = place(array, p, r);
        recsort(array, p, q-1);
        recsort(array, q+1, r);
        merge(array, p, q, r);
    }
}

void sort(int *array, size_t length){
    affichage(array, length);
    recsort(array, 0, length-1);
    affichage(array, length);
}