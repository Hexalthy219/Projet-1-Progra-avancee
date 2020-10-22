/* ========================================================================= *
 * PlaceSort
 * Implementation of the PlaceSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"

static void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void sort(int *array, size_t length){
    size_t i=0, m, x=0;
    while(i<length){
        x++;
        m=0;
        for(size_t j=0; j<length; j++){
            if(array[i]>array[j])
                m++;
        }

        if (m!=i){
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