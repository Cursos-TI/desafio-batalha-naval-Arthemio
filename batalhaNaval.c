#include <stdio.h>

int main() {
    // Criando o tabuleiro 10x10 e preenchendo tudo com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio 1 - horizontal com tamanho 3
    int linha1 = 2;
    int coluna1 = 4;

    // Colocando o navio horizontal no tabuleiro (valor 3)
    tabuleiro[linha1][coluna1] = 3;
    tabuleiro[linha1][coluna1 + 1] = 3;
    tabuleiro[linha1][coluna1 + 2] = 3;

    // Navio 2 - vertical com tamanho 3
    int linha2 = 5;
    int coluna2 = 1;

    // Colocando o navio vertical no tabuleiro (valor 3)
    tabuleiro[linha2][coluna2] = 3;
    tabuleiro[linha2 + 1][coluna2] = 3;
    tabuleiro[linha2 + 2][coluna2] = 3;

    // Mostrando o tabuleiro na tela
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

