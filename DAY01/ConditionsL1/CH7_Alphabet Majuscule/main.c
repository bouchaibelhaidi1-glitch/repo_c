#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c ;

    printf("enter le caractere :");
    scanf("%c", &c);

    if (c>=65 && c<=90){


        printf("le caractere  %c est majuscule",c);
    }else{


    printf("le caractere  %c c'est pas majuscule",c);
    }



    return 0;
}
