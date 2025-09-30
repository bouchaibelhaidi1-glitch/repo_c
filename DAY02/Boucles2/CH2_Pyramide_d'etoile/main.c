#include <stdio.h>
#include <stdlib.h>

int main()
{
    int L,i,j;


    printf("Entrer le nombres des lignes :");
    scanf("%d",&L);

    for(i=1 ;i<L ;i++)
    {
        for(j=0 ; j<L-i ; j++)
        {
            printf(" ");
        }

        for (j=0 ; j<2*i-1 ;j++)

        {
            printf("*");
        }


      printf("\n");
    }






    return 0;
}
