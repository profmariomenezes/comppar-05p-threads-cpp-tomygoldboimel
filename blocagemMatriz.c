#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100
#define N 100
#define X 100
#define BLOCK_SIZE 32

void blocagemMatriz(int A[M][N], int B[N][X], int C[M][X]) {
    int i, j, k, l, m, n;
    for (l = 0; l < M; l += BLOCK_SIZE) {
        for (m = 0; m < X; m += BLOCK_SIZE) {
            for (n = 0; n < N; n += BLOCK_SIZE) {
                for (i = l; i < l + BLOCK_SIZE && i < M; i++) {
                    for (j = m; j < m + BLOCK_SIZE && j < X; j++) {
                        for (k = n; k < n + BLOCK_SIZE && k < N; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

void preenchimentoMatriz(int matrix[][N], int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

int main() {
    int A[M][N], B[N][X], C[M][X] = {0};
    srand(time(NULL));

    preenchimentoMatriz(A, M, N);
    preenchimentoMatriz(B, N, X);


    clock_t inicio = clock();
    blocagemMatriz(A, B, C);
    clock_t fim = clock();
    double tempoTotal = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo Levado(Blocagem): %f segundos", tempoTotal);

    return 0;
}
