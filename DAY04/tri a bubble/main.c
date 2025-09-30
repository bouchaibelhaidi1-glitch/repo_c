#include <stdio.h>
#include <stdlib.h>

#define taille 5

int main()
{
    int i,j , table[taille];

    //remplir le tableau

    for (i=0 ; i<taille ; i++)
    {

        printf("table[%d] : ",i);
        scanf("%d", &table[i]);

    }

    //afficher le tableau avant le tri

    printf("le tableau avant le tri :\n");

    for (i=0 ; i<taille ; i++)
    {

        printf("table[%d] : %d\n",i,table[i]);


    }
    //le tri
    for (i=0 ; i<taille-1 ; i++)
    {

      for (j=i+1 ; j<taille ; j++)
      {

          int temp;
          if(table[i]>table[j])
          {

           temp=  table[i] ;
           table[i] = table[j];
           table[j]=temp;
          }

      }
    }

    //afficher le tableau apres le tri
    printf("le tableau apres le tri :\n");

    for (i=0 ; i<taille ; i++)
    {

        printf("table[%d] : %d\n",i,table[i]);


    }


    return 0;
}
