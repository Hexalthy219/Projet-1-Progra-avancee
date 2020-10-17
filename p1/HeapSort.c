/* ========================================================================= *
 * HeapSort
 * Implementation of the HeapSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include "Sort.h"

static void affichage(int *array, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\t", array[i]);
    printf("\n\n");
}

static void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

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
    affichage(array, length);
    int i = length;

    build_max_heap(array, length-1);
    affichage(array, length);
    while(length>=1){
        swap(array, length-1, 0);
        length--;
        max_heapify(array, 0, length-1);
    }
    affichage(array, i);
}