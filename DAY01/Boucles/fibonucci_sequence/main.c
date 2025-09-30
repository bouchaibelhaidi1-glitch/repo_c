#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,count=0;


    printf("enter le nombre de sequence:");
    scanf("%d",&n);
    int result[n];
    do {

      if (count == 0){

        result[0] = 0;
      }
      if (count == 1){

        result[1] = 1;
      }
      if (count > 1){

        result[count]=result[count-1]+result[count-2];


      }


      count++;

    }while(count < n);



    if (n == 1){

        printf("%d",result[0]);
    }
     if (n == 2){

        printf("%d,%d",result[0],result[1]);
    }else {
     for (int i=0 ;i<count ; i++){

        printf("%d,",result[i]);

    }

    }




    return 0;
}
