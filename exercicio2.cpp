#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double arredondar(double valor, int casas = 0) {
    int f = 1;

    for (int i = 0; i < casas; i++)
        f *= 10;

    return ((double)(int)(valor * f + 0.5)) / f;
}

int main(int argc, char *argv[]) {

    printf("%f\n", arredondar(69696.6564, 3));

    printf("%f\n", arredondar(69696.6564));

    getchar();
    return 0;
}