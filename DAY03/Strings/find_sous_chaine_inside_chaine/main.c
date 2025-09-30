#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char chaine[100];
    char sous_chaine[20];
    int i,j,k=1;


    printf("entre la chaine de caractere :\n");
    fgets(chaine, sizeof(chaine), stdin);

    printf("entre la sous_chaine de caractere :\n");
    fgets(sous_chaine, sizeof(sous_chaine), stdin);

    sous_chaine[strcspn(sous_chaine, "\n") ] = '\0';

    int len1 = strlen(chaine);
    int len2 = strlen(sous_chaine);

    strlwr(chaine);
    strlwr(sous_chaine);



    if (len2 >len1){

        printf("invalid la sous chaine est grand de la chaine");
    }
    int found =0;
    for (i=0 ; i<=len1-len2 ; i++){
        if(chaine[i]== sous_chaine[0]){
                found =1;

           for (j=i+1 ; j<len2 ; j++){

            if (chaine[j] != sous_chaine[k]){

            found = 0;

            }
             k++;

           }
           if(found){
            break;
           }
           }
        }
        printf("%d",found);







    if (found)

    printf("la sous_chaine de caractere est trouve ");

    else

    printf("sous_chaine de caractere n'a pas trouve");
















    return 0;
}

