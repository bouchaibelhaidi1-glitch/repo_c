#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define RED "\e[1;31m"
#define OLA "\e[1;32m"
#define GRN "\e[0;32m"
#define YEL "\e[1;33m"
#define YELLow "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[1;35m"
#define ROSE "\e[0;35m"
#define CYN "\e[1;36m"
#define AZZ "\e[1;36m"
#define WHT "\e[0;36m"
#define reset "\e[0m"

struct Contact {

   char nom[100];
   char mail[100];
   int phone;
   int ID ;

};

void create_contact(struct Contact carnet[], int count);

int search_contact_nom(struct Contact carnet[] ,char contact_for_search [] , int count);
int search_contact_ID(struct Contact carnet[] ,int search_ID, int count);
int modifier_contact(struct Contact carnet[] , int count);



int main()

{
    struct Contact carnet[100];
    int option, i,j,count=0,result;
    char contact_for_search[30];
    int search_ID,choice ;


    do {


          printf("\n\n=========carnet de contact===========\n\n");
          printf("1. Ajouter un Contact \n");
          printf("2. Modifier un Contact \n");
          printf("3. Supprimer un Contact \n");
          printf("4. Afficher Tous les Contacts\n");
          printf("5. Rechercher un Contact\n");
          printf("6. Exit\n");
          printf("entrer votre option :");
          scanf("%d",&option);
          getchar();


          switch(option)
              {
          case 1 :


                 create_contact(carnet, count);
                 printf("le contact a ete ajouter avec succes\n");
                 count++;

                 break;
          case 2 :

                 if(count==0){
                   printf("\nAucun Contact Existe Dans Le Carnet\n");
                   break;

                 }
                 printf("========entrer la methode de recherche pour la modification========\n");
                 printf("1 - rechercher par nom .\n");
                 printf("2 - rechercher par ID .\n");
                 printf("choisir votre option :\n");
                 scanf("%d", &choice);
                 getchar();

                 switch(choice)
                               {

                           case 1 :

                               printf("entrer le nom :\n");
                               fgets(contact_for_search,sizeof(contact_for_search), stdin);
                               contact_for_search[strcspn(contact_for_search, "\n")] = '\0';

                               result = search_contact_nom(carnet ,contact_for_search , count);





                               if (result>=0){


                                   printf("=====modification======\n");


                                   printf("%d - entrer le nouveau nom :\n",result+1);
                                   fgets(carnet[result].nom,sizeof(carnet[result].nom), stdin);
                                   carnet[result].nom[strcspn(carnet[result].nom, "\n")] = '\0';

                                   printf("%d - entrer le nouveau adresse mail %:\n",result+1);
                                   fgets(carnet[result].mail,sizeof(carnet[result].mail), stdin);
                                   carnet[result].mail[strcspn(carnet[result].mail, "\n")] = '\0';


                                    printf("%d - entrer le nouveau numero de telephone :\n",result+1);
                                    scanf("%d", &carnet[result].phone);
                                    getchar();
                                    printf("le contact a ete modifier avec succes \n");


                                }else {

                                printf("le contact avec le nom %s pas trouve\n",contact_for_search);


                                }


                               break;

                            case 2 :
                               printf("entrer le ID :\n");
                               scanf("%d",&search_ID);
                               getchar();

                               result = search_contact_ID(carnet ,search_ID,count);

                               if (result>=0){


                                   printf("=====modification======\n");


                                   printf("%d - entrer le nouveau nom :\n",result+1);
                                   fgets(carnet[result].nom,sizeof(carnet[result].nom), stdin);
                                   carnet[result].nom[strcspn(carnet[result].nom, "\n")] = '\0';

                                   printf("%d - entrer le nouveau adresse mail %:\n",result+1);
                                   fgets(carnet[result].mail,sizeof(carnet[result].mail), stdin);
                                   carnet[result].mail[strcspn(carnet[result].mail, "\n")] = '\0';


                                    printf("%d - entrer le nouveau numero de telephone :\n",result+1);
                                    scanf("%d", &carnet[result].phone);
                                    getchar();

                                    printf("le contact a ete modifier avec succes \n");


                                }else {

                                printf("le contact avec ID %d pas trouve\n",search_ID);


                                }
                                break;
                            default :
                                 printf("invalid option \n");


                               }

                           break;

                case 3 :
                  choice =0;

                  if(count==0){
                   printf("\nAucun Contact Existe Dans Le Carnet\n");
                   break;

                   }
                   result =-2;
                   printf("Entrez le nom du contact que vous souhaitez supprimer:\n");
                   fgets(contact_for_search,sizeof(contact_for_search), stdin);
                   contact_for_search[strcspn(contact_for_search, "\n")] = '\0';

                   result = search_contact_nom(carnet,contact_for_search,count);

                   if (result>=0){

                        printf("====contact trouve======\n");

                        printf("%d -Nom : %s\n",result+1,carnet[result].nom);
                        printf("%d -phone : %d\n",result+1,carnet[result].phone);
                        printf("%d -mail : %s\n",result+1,carnet[result].mail);
                        printf("%d -ID   : %d\n",result+1,carnet[result].ID);

                        printf("voulez vous vraiment supprimer ce contact\n");

                        printf("1 - confimer la suppression .\n");
                        printf("2 - annuler la suppression.\n");
                        printf("choisir votre option :\n");
                        scanf(" %d", &choice);
                        getchar();
                        if (choice==1){

                             for(i=result ; i<count ;i++ ) {


                             strcpy(carnet[i].nom,carnet[i+1].nom);
                             carnet[i].phone = carnet[i+1].phone;
                             strcpy(carnet[i].mail,carnet[i+1].mail);
                             carnet[i].ID = carnet[i+1].ID;


                        }
                        count--;
                        printf("le contact a ete supprimer avec succes\n");

                        }

                        }else if (result == -1){

                        printf("le contact avec le nom %s pas trouve\n",contact_for_search);

                        }
                        if (choice==2){


                            break;
                        }

                break;

                case 4 :
                         if(count==0){
                         printf("\nAucun Contact Existe Dans Le Carnet\n");
                         break;

                        }
                        printf("=======================================Contacts============================================\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                  Mail                    +\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        for (i=0 ;i<count ; i++)
                        {
                        printf("+ %d  |       %s         |        %d           |                 %s                       +\n",carnet[i].ID,carnet[i].nom,carnet[i].phone,carnet[i].mail);

                        }
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");


                     break;
                case  5 :
                    result=-3;
                    choice = 0;
                    if(count==0){
                         printf("\nAucun Contact Existe Dans Le Carnet\n");
                         break;

                        }



                   printf("========entrer la methode de recherche========\n");
                   printf("1 - rechercher par nom .\n");
                   printf("2 - rechercher par ID .\n");
                   printf("choisir votre option :\n");
                   scanf("%d", &choice);
                   getchar();

                   if (choice==1){

                   printf("Entrez le nom que tu cherche\n");
                   fgets(contact_for_search,sizeof(contact_for_search), stdin);
                   contact_for_search[strcspn(contact_for_search, "\n")] = '\0';

                    result = search_contact_nom(carnet,contact_for_search,count);

                    if (result>=0){

                        printf("=============Contact trouve===============");

                        printf("=======================================Contacts============================================\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                  Mail                    +\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+ %d  |       %s         |        %d           |                 %s                       +\n",carnet[result].ID,carnet[result].nom,carnet[result].phone,carnet[result].mail);
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");


                    }else if (result==-1){


                     printf("le contact avec le nom %s pas trouve\n",contact_for_search);


                    }

                   }
                   result =-3;
                   if(choice==2){

                     printf("entrer le ID :\n");
                     scanf("%d",&search_ID);
                     getchar();
                     result = search_contact_ID(carnet ,search_ID,count);

                    if (result>=0){

                        printf("=============Contact trouve===============");

                        printf("=======================================Contacts============================================\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                  Mail                    +\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+ %d  |       %s         |        %d           |                 %s                       +\n",carnet[result].ID,carnet[result].nom,carnet[result].phone,carnet[result].mail);
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");


                        printf("le contact a ete supprime avec succes\n");

                    }else if (result=-1){


                        printf("le contact avec ID %d pas trouve\n",search_ID);

                    }

                   }

                   break;
            case 6 :

               printf("exiting........Goodby!");
               break;

            default :
                printf("invalid option \n");


                   }






    }while(option !=6);








    return 0;
}




void create_contact(struct Contact carnet[], int count){




   printf("entrer le nom %d:\n",count+1);
   fgets(carnet[count].nom,sizeof(carnet[count].nom), stdin);
   carnet[count].nom[strcspn(carnet[count].nom, "\n")] = '\0';

   printf("entrer l'adresse mail %d:\n",count+1);
   fgets(carnet[count].mail,sizeof(carnet[count].mail), stdin);
   carnet[count].mail[strcspn(carnet[count].mail, "\n")] = '\0';


   printf("entrer le numero de telephone %d:\n",count+1);
   scanf("%d", &carnet[count].phone);
   getchar();

   carnet[count].ID = count+1;


}


int search_contact_ID(struct Contact carnet[] ,int search_ID, int count){



                      int i,found=0;;
                      int accountindex;

                       for (i=0 ; i<count ; i++){

                         if (carnet[i].ID==search_ID){
                         accountindex = i;
                         found = 1;
                         break;
                       }

                       }
                      if(found){

                        return accountindex ;
                        }else {

                         return -1;

                       }






}

int search_contact_nom(struct Contact carnet[] ,char contact_for_search [] , int count){



                      int i,found=0;;
                      int accountindex;


                       for (i=0 ; i<count ; i++){

                         if (strcmpi(carnet[i].nom,contact_for_search)==0){
                         accountindex = i;
                         found = 1;
                         break;
                        }

                        }
                       if(found){

                       return accountindex;
                        }else {

                         return -1 ;

                        }



}





































