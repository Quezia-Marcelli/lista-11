#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linha = 5;
int coluna = 5;

void gerarNum(int *arr, int inicio, int fim, int quantidade) {
    int range = fim - inicio + 1;
    int usados[range];

    for (int i = 0; i < range; i++) 
        usados[i] = 0;

    int count = 0;

    while (count < quantidade) {
        int num = inicio + rand() % range;
        if (!usados[num - inicio]) {
            usados[num - inicio] = 1;
            arr[count++] = num;
        }
    }
}

void cartela(FILE *arquivo) {
    int bingo[linha][coluna];

    // Gerar números para cada coluna:
    gerarNum(&bingo[0][0], 1, 15, linha);      // Coluna B
    gerarNum(&bingo[0][1], 16, 30, linha);     // Coluna I

    int numerosN[linha - 1];
    gerarNum(numerosN, 31, 45, linha - 1);     // Coluna N (4 números, pois tem o FREE)

    gerarNum(&bingo[0][3], 46, 60, linha);     // Coluna G
    gerarNum(&bingo[0][4], 61, 75, linha);     // Coluna O

    // Preencher a coluna N com os números e o "FREE" no meio
    int idxN = 0;
    for (int i = 0; i < linha; i++) {
        if (i == 2)
            bingo[i][2] = 0;  // Usando 0 para representar FREE
        else
            bingo[i][2] = numerosN[idxN++];
    }

    // Escrever cartela no arquivo CSV
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (j > 0) fprintf(arquivo, ",");
            if (j == 2 && i == 2)
                fprintf(arquivo, "FREE");
            else
                fprintf(arquivo, "%d", bingo[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    // Linha em branco para separar cartelas
    fprintf(arquivo, "\n");
}

int main() {
    srand(time(NULL));

    FILE *arquivo = fopen("cartelas.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int qtd_cartelas;
    printf("Digite a quantidade de cartelas: ");
    scanf("%d", &qtd_cartelas);

    fprintf(arquivo, "B,I,N,G,O\n");

    for (int i = 0; i < qtd_cartelas; i++) {
        cartela(arquivo);
    }

    fclose(arquivo);
    printf("Cartelas geradas em 'cartelas.csv'.\n");

    system("pause");
    return 0;
}