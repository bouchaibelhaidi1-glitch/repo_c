#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base , exposant, result=1 ;
    printf("enter number ");
    scanf("%d", &base);
    printf("enter number ");
    scanf("%d", &exposant);

    if (exposant==0){

     result =1;

    }

    for (int i=0 ; i<exposant; i++){

        result = result * base;



    }
    printf("le calcule de puissance de nombre %d est :%d",base,result);
    return 0;
}
