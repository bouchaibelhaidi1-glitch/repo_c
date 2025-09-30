#include <stdio.h>
#include <stdlib.h>




void tri_selection(int table[],int taille){
    int i,j,temp,min;
    for (i=0 ; i<taille-1 ; i++)

    {
        min=i;
        for (j=i+1 ; j<taille ;j++)
        {
          if (table[j] < table[min])
          {

            min=j;
          }
        }
        if (min !=i)
        {

           temp = table[i]  ;
           table[i] = table[min];
           table[min] = temp;

        }
    }

}


int main()
{


    int i,table[5] ;

    for (i=0 ;i<5 ;i++)
    {

        printf("table[%d] : ",i);
        scanf("%d",&table[i]);
    }

    printf("===================AVANT LE TRI==================\n");
       for (i=0 ;i<5 ;i++)
    {

        printf("%d\n", table[i]);

    }

     tri_selection(table,5);



    printf("===================APRES LE TRI==================\n");
    for (i=0 ;i<5 ;i++)
    {

        printf("%d\n", table[i]);

    }

    return 0;
}
