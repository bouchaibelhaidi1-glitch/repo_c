#include <stdio.h>
#include <stdlib.h>


long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
     int n;
    printf("Entrez le terme n de Fibonacci : ");
    scanf("%d", &n);

    printf("Le %d  terme de Fibonacci est : %lld\n", n, fibonacci(n));
    return 0;
}
