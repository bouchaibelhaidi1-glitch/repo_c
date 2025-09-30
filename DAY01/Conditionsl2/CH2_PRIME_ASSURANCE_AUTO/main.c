#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age, type_voiture, accidents;
    float prime_base, prime;

    printf("Entrez la prime de base  : ");
    scanf("%f", &prime_base);

    printf("Entrez l'âge du conducteur : ");
    scanf("%d", &age);

    printf("Type de voiture (1=Sportive, 2=Utilitaire, 3=Familiale) : ");
    scanf("%d", &type_voiture);

    printf("Nombre d'accidents au cours des 5 dernières années : ");
    scanf("%d", &accidents);

        prime = prime_base;

    if (age < 25) {
        prime *= 1.5;
    }
    else if (age > 65) {
        prime *= 1.2;
    }

    if (type_voiture == 1) {
        prime *= 2;
     }
    else if (type_voiture == 2) {
        prime *= 1.2;
     }
    else if (type_voiture == 3) {
        prime *= 1.1;
     }

    if (accidents > 1) {
        prime *= 1.3;
     }

    printf("La prime d'assurance calculée est : %.2f \n", prime);

    return 0;
}
