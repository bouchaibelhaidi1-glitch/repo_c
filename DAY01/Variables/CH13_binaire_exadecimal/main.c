#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char num[100];
    char *endptr1;
    char *endptr2;
    long int num_bin;
    long int num_hexa;

    printf("enter number to convert :");
    scanf("%s", num);

    num_bin  = strtol(num, &endptr1, 2);
    num_hexa = strtol(num, &endptr2, 16);

    if (*endptr1 == '\0' && *endptr2 == '\0') {
        printf("le nombre %s en binaire est :%ld\n", num, num_bin);
        printf("le nombre %s en hexadecimal est :%ld", num, num_hexa);
    } else {
        printf("invalid number");
    }

    return 0;
}
