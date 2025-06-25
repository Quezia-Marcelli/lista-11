#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int ini, fim, primo = 1;

    if(argc != 3) 
        return 1;

    ini = atoi(argv[1]);
    fim = atoi(argv[2]);

    for(int i = ini; i < fim; i++){
        primo = 1;
        if(i <= 1)
            primo = 0;
        else
        {
            for(int j = 2; j < i && primo == 1; j++){
                if(i % j == 0)
                    primo = 0;
            }
        }

        if(primo == 1)
            printf("%d ",i);
    }

    printf("\n");

    system("pause");
    return 0;
}