#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main()
{
        srand(time(NULL));
        int randomNumber = (rand() % 7) + 1;
        switch(randomNumber){
    case 1 :
        printf("lundi");
        break;
    case 2 :
        printf("Mardi");
        break;
    case 3 :
        printf("Mercredi");
        break;
    case 4 :
        printf("jeudi");
        break;
    case 5 :
        printf("vendredi");
        break;
    case 6 :
        printf("samedi");
        break;
    case 7 :
       printf("dimanche");
       break;




        }

    return 0;
}
