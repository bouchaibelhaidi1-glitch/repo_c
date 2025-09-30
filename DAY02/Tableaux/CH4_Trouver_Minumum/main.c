#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, max;

    printf("Entrez le nombre d'elements du tableau : ");
    scanf("%d", &n);

    int tab[n];

    for (i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    max = tab[0];

    for (i = 1; i < n; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    printf("Le plus grand element du tableau est : %d\n", max);

    return 0;
}
