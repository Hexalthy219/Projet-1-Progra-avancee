#include <stdio.h>

static void affichage(int *array, size_t length)
{
    for (size_t i = 0; i < length; i++)
        printf("%d\t", array[i]);
    printf("\n\n");
}

int main(){
    double moyenne=0;
    double tmp;
    int i=1;
    do{
        scanf("%lf", &tmp);
        printf("\n");
        moyenne+=tmp;
        i++;
    }while(i<=10);
    moyenne/=10;
    printf("moyenne : %lf\n", moyenne);



    return 0;
}