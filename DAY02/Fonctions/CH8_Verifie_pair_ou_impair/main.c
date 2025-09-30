#include <stdio.h>
#include <stdlib.h>



int estPair(int n) {
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}

int main() {
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);

    if (estPair(n))
        printf("%d est pair.\n", n);
    else
        printf("%d est impair.\n", n);

    return 0;
}
