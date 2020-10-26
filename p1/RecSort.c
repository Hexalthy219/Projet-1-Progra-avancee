/* ========================================================================= *
 * RecSort
 * Implementation of the RecSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <limits.h>
#include "Sort.h"

static void swap(int *array, int a, int b){
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

static int place(int *array, int p, int r){
    int m = 0;
    for(int i=p; i<r; i++){
        if(array[i]<array[r])
            m++;
    }
    int l=m+p;
    swap(array, r, l);

    return l;
}

static void merge(int *array, int borne_inf, int pivot, int borne_sup){
    int tailleL = pivot-borne_inf+1, tailleR = borne_sup-pivot+1;
    int i, j = 0, k = borne_inf;
    int R[tailleR], L[tailleL];

    for(i = 0; i<tailleL-1; i++)
        L[i] = array[i+borne_inf];
    L[tailleL-1] = INT_MAX;

    for (i = 0; i<tailleR-1; i++)
        R[i] = array[pivot+1+i];
    R[tailleR-1] = INT_MAX;

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