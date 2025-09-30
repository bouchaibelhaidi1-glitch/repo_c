#include <stdio.h>
#include <stdlib.h>




struct air{

   float longeur;
   float largeur;

};

float air_rectangle(float longeur , float largeur) {



     return longeur * largeur;
}


int main()
{
    struct air rectangle;


    printf("entrer la longeur de rectangle :\n");
    scanf("%f", &rectangle.longeur);

    printf("entrer la largeur de rectangle :\n");
    scanf("%f", &rectangle.largeur);


    printf("l'air de rectangle est :%.2f",air_rectangle(rectangle.longeur ,rectangle.largeur));




    return 0;
}
