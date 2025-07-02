#include <stdio.h>

#define TAM 10
#define AGUA 0
#define NAVIO 3

int main() {
    // Criando o tabuleiro e preenchendo com 0 (água)
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // === NAVIO 1: Horizontal ===
    int l1 = 1, c1 = 2; // linha 1, coluna 2
    if (c1 + 2 < TAM &&
        tabuleiro[l1][c1] == AGUA &&
        tabuleiro[l1][c1+1] == AGUA &&
        tabuleiro[l1][c1+2] == AGUA) {
        
        tabuleiro[l1][c1] = NAVIO;
        tabuleiro[l1][c1+1] = NAVIO;
        tabuleiro[l1][c1+2] = NAVIO;
    }

    // === NAVIO 2: Vertical ===
    int l2 = 4, c2 = 6;
    if (l2 + 2 < TAM &&
        tabuleiro[l2][c2] == AGUA &&
        tabuleiro[l2+1][c2] == AGUA &&
        tabuleiro[l2+2][c2] == AGUA) {

        tabuleiro[l2][c2] = NAVIO;
        tabuleiro[l2+1][c2] = NAVIO;
        tabuleiro[l2+2][c2] = NAVIO;
    }

    // === NAVIO 3: Diagonal ↘ ===
    int l3 = 6, c3 = 0;
    if (l3 + 2 < TAM && c3 + 2 < TAM &&
        tabuleiro[l3][c3] == AGUA &&
        tabuleiro[l3+1][c3+1] == AGUA &&
        tabuleiro[l3+2][c3+2] == AGUA) {

        tabuleiro[l3][c3] = NAVIO;
        tabuleiro[l3+1][c3+1] = NAVIO;
        tabuleiro[l3+2][c3+2] = NAVIO;
    }

    // === NAVIO 4: Diagonal ↙ ===
    int l4 = 2, c4 = 8;
    if (l4 + 2 < TAM && c4 - 2 >= 0 &&
        tabuleiro[l4][c4] == AGUA &&
        tabuleiro[l4+1][c4-1] == AGUA &&
        tabuleiro[l4+2][c4-2] == AGUA) {

        tabuleiro[l4][c4] = NAVIO;
        tabuleiro[l4+1][c4-1] = NAVIO;
        tabuleiro[l4+2][c4-2] = NAVIO;
    }

    // === Mostrando o tabuleiro ===
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


