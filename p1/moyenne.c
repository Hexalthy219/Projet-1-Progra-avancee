#include <stdio.h>


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