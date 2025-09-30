#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, temp;

    printf("Entrez le nombre d'elements du tableau : ");
    scanf("%d", &n);

    int tab[n];

    for (i = 0; i < n; i++) {
        printf("tab[%d]: ", i + 1);
        scanf("%d", &tab[i]);
    }


    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (tab[i] > tab[j]) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    printf("Tableau trie en ordre croissant : ");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }

    return 0;
}
