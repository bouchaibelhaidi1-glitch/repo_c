#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct livre {

    char titre[100];
    char auteur[100];
    float price;
    int qauntite;



};


void validate_livre(struct livre library[], int count);

int search_livre(struct livre library[], int count);




int main()
{

    struct livre library[100];
    int i,option,count =0,accountindex ;
    char search_livre[100] ;
    char decision;



    do {

         printf("\n=======Gestion de Librairie=========\n\n");
         printf("1 - Ajouter un livre au stock. \n");
         printf("2 - Afficher tous les livres disponibles. \n");
         printf("3 - Rechercher un livre par son titre. \n");
         printf("4 - Mettre à jour la quantité d'un livre. \n");
         printf("5 - Supprimer un livre du stock. \n");
         printf("6 - Afficher le nombre total de livres en stock. \n");
         printf("7 -Exit \n");
         printf("choisir votre option :");
         scanf("%d",&option);
         getchar();

         switch(option){

             case 1 :
                validate_livre(library,count);
                printf("le livre a ete ajoute avec succes\n");
                count++;
                break;

             case 2 :


                    if (count==0){

                        printf("pas de livre au stock");
                        break;

                      }
                     printf("\n======livres on stock=======\n");
                      for (i=0 ;i<count ; i++){


                        printf("%d - Nom De Livre :%s\n",i+1,library[i].titre);
                        printf("%d - Nom de l auteur :%s\n",i+1,library[i].auteur);
                        printf("%d - le prix de livre :%.2f\n",i+1,library[i].price);
                        printf("%d - la quantite en stock :%d\n\n",i+1,library[i].qauntite);
                      }


                      break;

             case 3 :

                    if (count==0){

                        printf("pas de livre au stock");
                        break;

                      }
                    printf("entre le nom de livre pour la recherche :");
                    fgets(search_livre,sizeof(search_livre), stdin);
                    search_livre[strcspn(search_livre , "\n")] = '\0';

                    int found=0;
                    for (i=0 ;i<count ;i++){

                        if (strcmpi(library[i].titre, search_livre)==0){


                            printf("\n livre trouve:\n");
                            printf("%d - Nom De Livre :%s\n",i+1,library[i].titre);
                            printf("%d - Nom de l auteur :%s\n",i+1,library[i].auteur);
                            printf("%d - le prix de livre :%.2f\n",i+1,library[i].price);
                            printf("%d - la quantite en stock :%d\n\n",i+1,library[i].qauntite);

                            found =1;
                            break;

                        }
                    }




                   if (!found){

                    printf("\npas de livre trouve avec ce nom!\n");
                   }

                   break;


             case 4 :
                    if (count==0)
                    {

                    printf("pas de livre au stock");
                    break;

                    }
                    printf("entre le nom de livre pour mise a jour de stock :");
                    fgets(search_livre,sizeof(search_livre), stdin);
                    search_livre[strcspn(search_livre , "\n")] = '\0';

                    found=0;
                    for (i=0 ;i<count ;i++){

                        if (strcmpi(library[i].titre, search_livre)==0){


                            printf("entre la nouvelle quantite de stock :");
                            scanf("%d", &library[i].qauntite);
                            found =1;
                            break;

                        }
                    }

                   if (!found)
                    {

                    printf("pas de livre trouve entre a valid nom !");
                    }

                    break;

             case 5 :

                        if (count==0)
                        {
                        printf("pas de livre au stock");
                        break;
                        }

                        printf("entre le nom de livre pour supprimer :");
                        fgets(search_livre,sizeof(search_livre), stdin);
                        search_livre[strcspn(search_livre , "\n")] = '\0';

                        printf("voulez vous vraiment suppreme (o/n) :\n");
                        scanf("%c",&decision);
                        getchar();

                        if (decision == 'n')break;
                        else if (decision == 'o')
                        {
                         int found=0;
                         for (i=0 ;i<count ;i++){

                         if (strcmpi(library[i].titre, search_livre)==0)
                         {

                           for (int j=i ; j<count ; j++){


                            strcpy(library[j].titre , library[j+1].titre);
                            strcpy(library[j].auteur , library[j+1].auteur);
                            library[j].price = library[j+1].price;
                            library[j].qauntite , library[j+1].qauntite;

                            printf("le livre a ete supprime aved succes \n");
                            found = 1;
                           }

                           count--;
                           }
                           }

                           if (!found)
                           {

                            printf("pas de livre trouve entre a valid nom !");

                           }

                           }


                       break;

             case 6 :

                        if (count==0)
                        {

                        printf("pas de livre au stock");
                        break;

                        }
                        printf("le nombre total de livre dans la librarie est :%d",count);

                        break;



           default :
                  printf("Invalid option ");

             }

    }while(option != 7);


   return 0;
}




void validate_livre(struct livre library[], int count){

            char buffer[50];


            //validation de titre

             int valid=0;
             while(!valid){


              printf("entre le titre de livre :");

              if (fgets(library[count].titre,sizeof(library[count].titre), stdin)== NULL){

                printf("Input error Try again.\n");
                continue;
              }


              library[count].titre[strcspn(library[count].titre , "\n")] = '\0';
              int lenght = strlen(library[count].titre);



              if (isspace(library[count].titre[0]) || isspace(library[count].titre[lenght-1])){

                printf("entre a valide (pas d'espace au deput de titre ou a la fin).\n");
                continue;


              }

              valid = 1;


              }

              //validate auteur


             valid=0;
             while(!valid){

              int lenght = strlen(library[count].auteur);
              printf("entre le nom d'auteur :");

              if (fgets(library[count].auteur,sizeof(library[count].auteur), stdin)== NULL){

                printf("Input error Try again.\n");
                continue;
              }

              library[count].auteur[strcspn(library[count].auteur , "\n")] = '\0';


              if (isspace(library[count].auteur[0]) || isspace(library[count].auteur[lenght-1])){

                printf("entre a valide (pas d'espace au deput d'auteur ou a la fin).\n");
                continue;


              }

              valid = 1;


              }

              printf("entre le prix de livre :");
              scanf("%f", &library[count].price);
              getchar();
              printf("entre la qauntite de stock :");
              scanf("%d", &library[count].qauntite);
              getchar();

}


