#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char  str1[100];
    int i,j,len;

    printf("entrer une chaine de caractere :");
    fgets(str1 , sizeof(str1), stdin);

    len = strlen(str1);
    for (i=0 ;i<len ;i++){

        if(str1[i]==' '){

        for(j=i ; j<len-1 ; j++){

           str1[j] = str1[j+1];
            }

    }
    }

    printf("la chaine de caractere son espace est :%s",str1);










    return 0;
}
