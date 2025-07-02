#include <stdio.h>

#define TAM 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HAB 5

// Função para exibir o tabuleiro com símbolos diferentes
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ "); // água
            else if (tabuleiro[i][j] == NAVIO)
                printf("N "); // navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* "); // área de habilidade
            else
                printf("? "); // qualquer outro valor inesperado
        }
        printf("\n");
    }
}

// Cria matriz de habilidade Cone (↘ em forma de pirâmide)
void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade Cruz (+)
void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade Octaedro (losango)
void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica matriz de habilidade no tabuleiro, centralizada no ponto (linha, coluna)
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int linha, int coluna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int li = linha + i - offset;
            int co = coluna + j - offset;

            // Valida se está dentro dos limites do tabuleiro
            if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[li][co] == AGUA) {
                    tabuleiro[li][co] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona 2 navios como exemplo
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    tabuleiro[1][4] = NAVIO;

    tabuleiro[4][6] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;

    // Posiciona 2 navios diagonais
    tabuleiro[6][0] = NAVIO;
    tabuleiro[7][1] = NAVIO;
    tabuleiro[8][2] = NAVIO;

    tabuleiro[2][8] = NAVIO;
    tabuleiro[3][7] = NAVIO;
    tabuleiro[4][6] = NAVIO; // já existe, mas ok para exemplo

    // Criação das 3 habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicação das habilidades em diferentes pontos
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 8);  // octaedro no canto inferior direito

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}



