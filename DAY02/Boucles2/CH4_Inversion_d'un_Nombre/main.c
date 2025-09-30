#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, inverse = 0, digit;

    printf("Entrez un entier : ");
    scanf("%d", &n);

    while (n != 0) {
        digit = n % 10;
        inverse = inverse * 10 + digit;
        n = n / 10;
    }

    printf("L'entier inverse est : %d\n", inverse);

    return 0;
}

