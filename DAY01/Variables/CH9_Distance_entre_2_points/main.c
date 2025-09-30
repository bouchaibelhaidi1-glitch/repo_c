#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{


    float  x1,x2,y1,y2,z1,z2;
    float result;

    printf("enter distance x1:");
    scanf("%f",&x1);
    printf("enter distance x2:");
    scanf("%f",&x2);
    printf("enter distance y1:");
    scanf("%f",&y1);
    printf("enter distance y2:");
    scanf("%f",&y2);
    printf("enter distance z1:");
    scanf("%f",&z1);
    printf("enter distance z2:");
    scanf("%f",&z2);

    result = sqrt(pow((x2-x1),2) + pow((y2-y1), 2) + pow((z2-z1), 2));

    printf("the Distance is :%f",result);



    return 0;
}
