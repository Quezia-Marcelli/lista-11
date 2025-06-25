#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *menu = fopen("menu.txt", "r");
    if (menu == NULL) {
        printf("Erro ao abrir menu.txt\n");
        return 1;
    }

    int totalItens;
    fscanf(menu, "%d", &totalItens);

    char nomesProdutos[totalItens][50];
    float precosProdutos[totalItens];
    int qtdVendida[totalItens];

    for (int i = 0; i < totalItens; i++) {
        fscanf(menu, "%s %f", nomesProdutos[i], &precosProdutos[i]);
        qtdVendida[i] = 0;
    }

    fclose(menu);

    printf("\n===== MENU =====\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%d - %s (R$ %.2f)\n", i + 1, nomesProdutos[i], precosProdutos[i]);
    }
    printf("================\n");

    int opcaoItem, quantidade;
    do {
        printf("Digite o numero do item (0 para finalizar): ");
        scanf("%d", &opcaoItem);

        if (opcaoItem > 0 && opcaoItem <= totalItens) {
            printf("Quantidade de %s: ", nomesProdutos[opcaoItem - 1]);
            scanf("%d", &quantidade);
            qtdVendida[opcaoItem - 1] += quantidade;
        } else if (opcaoItem != 0) {
            printf("Item invalido.\n");
        }
    } while (opcaoItem != 0);

    FILE *boleto = fopen("boleto.txt", "w");
    if (boleto == NULL) {
        printf("Erro ao criar boleto.txt\n");
        return 1;
    }

    float valorTotal = 0;
    fprintf(boleto, "======= BOLETO =======\n");
    for (int i = 0; i < totalItens; i++) {
        if (qtdVendida[i] > 0) {
            float subtotal = qtdVendida[i] * precosProdutos[i];
            fprintf(boleto, "%s x%d - R$ %.2f\n", nomesProdutos[i], qtdVendida[i], subtotal);
            valorTotal += subtotal;
        }
    }
    fprintf(boleto, "-----------------------\n");
    fprintf(boleto, "TOTAL: R$ %.2f\n", valorTotal);
    fprintf(boleto, "=======================\n");

    fclose(boleto);

    printf("\nBoleto gerado em 'boleto.txt'.\n");

    system("pause");
    return 0;
}