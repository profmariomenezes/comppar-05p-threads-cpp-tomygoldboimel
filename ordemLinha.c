#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100
#define N 100
#define X 100

void ordemLinha(int A[M][N], int B[N][X], int C[M][X]) {
    int i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < X; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void preenchimentoMatriz(int matriz[][N], int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

int main() {
    int A[M][N], B[N][X], C[M][X];
    srand(time(NULL));

    preenchimentoMatriz(A, M, N);
    preenchimentoMatriz(B, N, X);

    clock_t inicio = clock();
    ordemLinha(A, B, C);
    clock_t fim = clock();

    double tempoTotal = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo levado (Ordem Linha): %f segundos", tempoTotal);

    return 0;
}
