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
   char phone[11];
   int ID ;

};

void create_validate_contact(struct Contact carnet[], int count);

int search_contact_nom(struct Contact carnet[] ,char contact_for_search [] , int count);
int search_contact_ID(struct Contact carnet[] ,int search_ID, int count);




int main()

{
            //==========variables declaration===========//

             struct Contact carnet[100];
             int option, i,j,count=0,result;
             char contact_for_search[30];
             int search_ID,choice ;


    do {

          //==========================MENU=============================//
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
          case 1 : system("cls");

                 create_validate_contact(carnet,count);
                 printf("le contact a ete ajouter avec succes\n");

                 count++;
                 system("PAUSE");
                 break;
          case 2 : system("cls");

                 if(count==0){
                   printf("\nAucun Contact Existe Dans Le Carnet\n");
                   break;

                 }
                 printf("==============================MODIFICATION==============================\n");

                 printf("entrer le nom :\n");
                 fgets(contact_for_search,sizeof(contact_for_search), stdin);
                 contact_for_search[strcspn(contact_for_search, "\n")] = '\0';

                 result = search_contact_nom(carnet ,contact_for_search , count);
                 if (result>=0){


                        printf("=======================================Contacts============================================================\n");
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                           Mail                           +\n");
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");

                        printf("+ %d  |        %s        |    %s               |                             %s                           +\n",carnet[result].ID,carnet[result].nom,carnet[result].phone,carnet[result].mail);

                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n\n");


                 create_validate_contact(carnet,result);
                 printf("le contact a ete modifier avec succes \n");

                 }else
                 {
                    printf("le contact avec le nom %s pas trouve\n",contact_for_search);

                 }

                system("PAUSE");
                break;

         case 3 : system("cls");

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


                        printf("=======================================Contacts============================================================\n");
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                           Mail                           +\n");
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");

                        printf("+ %d  |        %s        |    %s               |                             %s                           +\n",carnet[result].ID,carnet[result].nom,carnet[result].phone,carnet[result].mail);

                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");

                        printf("voulez vous vraiment supprimer ce contact\n");

                        printf("1 - confimer la suppression .\n");
                        printf("2 - annuler la suppression.\n");
                        printf("choisir votre option :\n");
                        scanf(" %d", &choice);
                        getchar();
                        if (choice==1){

                             for(i=result ; i<count ;i++ ) {


                             strcpy(carnet[i].nom,carnet[i+1].nom);
                             strcpy(carnet[i].phone,carnet[i+1].phone);
                             strcpy(carnet[i].mail,carnet[i+1].mail);
                             carnet[i].ID = carnet[i+1].ID;


                        }
                        count--;
                        printf("le contact a ete supprimer avec succes\n");

                        }

                        }else if (result == -1){

                        printf("le contact avec le nom %s n'est pas trouve\n",contact_for_search);

                        }
                        if (choice==2)
                        {

                            printf("la suppression est annuler\n");
                            break;
                        }
                         system("PAUSE");

                         break;

                case 4 : system("cls");
                         if(count==0){
                         printf("\nAucun Contact Existe Dans Le Carnet\n");
                         break;

                        }
                        printf("=======================================Contacts============================================================\n");
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                           Mail                           +\n");
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");
                        for (i=0 ;i<count ; i++)
                        {
                        printf("+ %d  |        %s        |    %s               |                             %s                           +\n",carnet[i].ID,carnet[i].nom,carnet[i].phone,carnet[i].mail);

                        }
                        printf("+-----+------------------+---------------------+----------------------------------------------------------+\n");

                        system("PAUSE");
                        break;
                case  5 :system("cls");
                        result=-3;
                        choice = 0;
                        if(count==0)
                        {
                         printf("\nAucun Contact Existe Dans Le Carnet\n");
                         break;

                        }
                        printf("========Entrer La Methode De Recherche========\n");
                        printf("1 - rechercher par nom .\n");
                        printf("2 - rechercher par ID .\n");
                        printf("choisir votre option :\n");
                        scanf(" %d", &choice);
                        getchar();

                        if (choice==1){

                        printf("Entrez le nom que tu cherche\n");
                        fgets(contact_for_search,sizeof(contact_for_search), stdin);
                        contact_for_search[strcspn(contact_for_search, "\n")] = '\0';

                        result = search_contact_nom(carnet,contact_for_search,count);

                        if (result>=0){

                        printf("=======================================Contacts============================================\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                  Mail                    +\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+ %d  |       %s         |        %s           |                 %s                       +\n",carnet[result].ID,carnet[result].nom,carnet[result].phone,carnet[result].mail);
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");


                        }else if (result==-1)
                        {

                        printf("le contact avec le nom %s n'est pas trouve\n",contact_for_search);

                        }

                        }
                        result =-3;
                        if(choice==2)
                        {

                        printf("entrer le ID :\n");
                        scanf(" %d",&search_ID);
                        getchar();
                        result = search_contact_ID(carnet ,search_ID,count);

                        if (result>=0){
                        printf("=======================================Contacts============================================\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+  ID |       Nom        |        Phone        |                  Mail                    +\n");
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");
                        printf("+ %d  |       %s         |        %s           |                 %s                       +\n",carnet[result].ID,carnet[result].nom,carnet[result].phone,carnet[result].mail);
                        printf("+-----+------------------+---------------------+------------------------------------------+\n");


                        printf("le contact a ete supprime avec succes\n");

                       }else if (result=-1)
                       {

                        printf("le contact avec ID %d n'est pas trouve\n",search_ID);

                       }

                       }
                       system("PAUSE");
                       break;
            case 6 :  system("cls");

                      printf("exiting........Goodby!\n");
                      system("PAUSE");
                      break;

            default :
                     printf("invalid option \n");


                   }


                  }while(option !=6);








    return 0;
}




void create_validate_contact(struct Contact carnet[], int count){

   //==========================================create and validate the name===============================================

   int i,j;
   int valid=0,allvalide = 1;

   while(!valid)
    {
    int space_count=0;

    printf("entrer le nom %d:",count+1);

    if (fgets(carnet[count].nom,sizeof(carnet[count].nom), stdin)==NULL)
    {
        printf("Erreur : Entree non valide \n");
        continue;
    }


    carnet[count].nom[strcspn(carnet[count].nom, "\n")] = '\0';

    int lenght = strlen(carnet[count].nom);

     //check lenght .the lenght of the name should be at least 2 character
    if (lenght < 2 || lenght > 30)
    {

       printf("Erreur : Veuillez entrer au moins 2 caracteres.\n") ;
       continue;
    }

    //check for spaces no space are allowed in the beginning or the end
    if (isspace(carnet[count].nom[0]) || isspace(carnet[count].nom[lenght-1]))
        {

         printf("Erreur : Le nom ne doit pas commencer ni se terminer par un espace.\n");
         continue;

        }

    // the name should only contain caractere or spaces


    for (i=0 ; i<lenght ; i++)
    {
        if (!(isalpha(carnet[count].nom[i]) || isspace(carnet[count].nom[i])))
        {

         printf("Erreur : Le nom ne doit contenir que des lettres.\n");
         allvalide = 0;
         break;

        }
    }

    if (!allvalide)continue;

    //count the spaces only 2 spaces are allowed
    for (i=1 ; i<lenght-1 ; i++)
    {
        if (isspace(carnet[count].nom[i]))
        {
         space_count++;
        }
    }
    if(space_count>2){

        printf(" Erreur : Trop d espaces. Seulement 2 sont autorises.\n");
        continue;
    }

    valid = 1;    // passed all checks valid name

   }


   //=========================================create and validate the email===================================================

   valid =0;
   while(!valid)
    {
     char gmail[]="@gmail.com";
     printf("entrer l'adresse mail %d:\n",count+1);

     if (fgets(carnet[count].mail,sizeof(carnet[count].mail), stdin)==NULL)
      {
        printf("Erreur : Entree non valide \n");
        continue;
      }

      carnet[count].mail[strcspn(carnet[count].mail, "\n")] = '\0';
      int lenght1 = strlen(carnet[count].mail);

      //check for spaces no space are allowed in the gmail
      int is_space = 0;
      for (i=0 ; i<lenght1 ; i++)
       {
        if (isspace(carnet[count].mail[i]))
        {
         is_space = 1;
         printf("Erreur : Le nom ne doit pas contenir des espaces\n");
         break;

        }
       }
       if (is_space)continue;

       //check if the gmail end with the domain (@gmail.com)
       int found =1;
       int k=lenght1-1;
       int lenght2 = strlen(gmail);
       for (i=lenght2-1 ;i>=0 ; i--)
        {

              if(gmail[i]!=carnet[count].mail[k])
              {
                 found=0;
                 printf("Erreur : mail invalide (ne se termine pas par @gmail.com).\n");
                 break;
              }
              k--;
        }
       if(!found)continue;

       //check for the lenght of the gmail

       if (lenght1 < 15)
       {

          printf("Erreur : Adresse e-mail invalide. L adresse doit contenir au moins 15 caracteˋres\n");
          continue;
       }

       int lenght3 = lenght1 - lenght2;    //lenght3 is the username lenght

       //check the username should not start nor end with a dot

       if(carnet[count].mail[0]=='.' || carnet[count].mail[lenght3-1]=='.'){

        printf("Erreur : Le nom d utilisateur ne doit pas commencer ni se terminer par un point.\n");
        continue;
       }

       //check for caractere.the gmail should only contain alphanumeric and dots

       allvalide=1;
       int has_dots = 0;
       for(i=0;i<lenght3 ;i++)
       {
          if(carnet[count].mail[i] =='.')
          {
           has_dots++;
          }
          if (!(isalnum(carnet[count].mail[i])  || carnet[count].mail[i] =='.'))
          {
          allvalide=0;
          }
       }
       if (!allvalide)continue;

       //check only 2 dots are allowed

       if(has_dots>2)
       {
         printf("Erreur : Nom d utilisateur invalide. Seuls 2 points ('.') sont autorises \n");
       }
       //check for consecutive dots (..) not allowed
       int dot_check = 0;
       for(i=0 ;i<lenght3 ;i++)
        {
         if(carnet[count].mail[i]=='.' && carnet[count].mail[i+1]=='.')
         {
             printf("Erreur : Nom d utilisateur invalide. Les points consecutifs (..) ne sont pas autorises.\n");
             dot_check = 1;
             break;
         }
       }
       if (dot_check)continue;

       valid = 1;  // passed all checks valid gmail
       }

       //======================================create and validate the number===================================================

       valid =0;
       while(!valid)
       {
        char buffer[20];

        printf("entrer le numero de telephone %d:\n",count+1);

        if (fgets(buffer,sizeof(buffer), stdin)==NULL)
        {
              printf("Erreur : Entree non valide \n");
              continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        int lenght4 = strlen(buffer);

        if (lenght4 != 10)
         {
             printf("Erreur : Le numéro de téléphone doit contenir 10 chiffres.\n");
             continue;
         }

        int alldigit = 1;
        for (i=0 ; i<lenght4 ; i++)
        {
            if (!isdigit(buffer[i]))
            {
              printf("Erreur : Le numéro de téléphone ne doit contenir que des chiffres.");
              alldigit = 0;
              break;
            }
        }
        if (!alldigit) continue;

        if (!(buffer[0] == '0' && (buffer[1] == '6' || buffer[1] == '7')) )
        {
          printf("Erreur : Le numéro de téléphone doit commencer par 06 ou 07.\n");
          continue;

        }

        strcpy(carnet[count].phone,buffer);

        int duplicate = 0;

        for (i=0 ; i<count ;i++)
        {
          if (strcmp(carnet[i].phone,carnet[count].phone)==0)
          {
             printf("Erreur : Ce numéro de téléphone existe déjà. Veuillez entrer un numéro de téléphone valide.n");
             duplicate = 1;
             break;
          }
        }
        if (duplicate)continue;


       valid=1; // passed all checks valid phone
       }




       carnet[count].ID = count+1;    // auto generative ID

}


int search_contact_ID(struct Contact carnet[] ,int search_ID, int count){


  int i;
  for (i=0 ; i<count ; i++)
  {

  if (carnet[i].ID==search_ID){
  return i;
  break;
  }

  }

return -1;

}

int search_contact_nom(struct Contact carnet[] ,char contact_for_search [] , int count){


 int i;

 for (i=0 ; i<count ; i++){

 if (strcmpi(carnet[i].nom,contact_for_search)==0){
 return i;
 break;
 }

 }
return -1;


}
