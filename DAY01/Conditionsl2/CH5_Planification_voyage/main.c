#include <stdio.h>
#include <stdlib.h>

int main()
{
       int budget , destination , num_persone;

    printf("entre votre budget :");
    scanf("%d",&budget);
    printf("entre combien de personne :");
    scanf("%d",&num_persone);

    if (budget >= 1000) {
        printf("Type de voyage : Haut de gamme\n");
      }
    else if (budget >= 500 && budget < 1000) {
        printf("Type de voyage : Moyen\n");
      }
    else {
        printf("Type de voyage : Economique\n");
      }

    if (budget >= 1000 && num_persone > 2) {
        printf("Destination recommandée : Plage\n");
      }
    else if (budget >= 500 && num_persone <= 2) {
        printf("Destination recommandée : Montagne\n");
      }
    else {
        printf("Destination recommandée : Ville\n");
     }

    return 0;
}
