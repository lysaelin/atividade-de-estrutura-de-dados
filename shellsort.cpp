#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ordenacaoShell(int arr[], int n, int seq[], int seq_tamanho) {
    for (int s = 0; s < seq_tamanho; s++) {
        int gap = seq[s];

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void sequenciaShell(int n, int seq[], int *tamanho) {
    int h = n / 2;
    int i = 0;
    while (h > 0) {
        seq[i++] = h;
        h /= 2;
    }
    *tamanho = i;
}

void sequenciaKnuth(int n, int seq[], int *tamanho) {
    int h = 1;
    int i = 0;
    while (h < n) {
        seq[i++] = h;
        h = 3 * h + 1;
    }
    *tamanho = i;
}

void sequenciaHibbard(int n, int seq[], int *tamanho) {
    int k = 1;
    int i = 0;
    int h = 1;
    while (h < n) {
        seq[i++] = h;
        k++;
        h = pow(2, k) - 1;
    }
    *tamanho = i;
}

double medirTempo(void (*funcOrdenacao)(int[], int, int[], int), int arr[], int n, int seq[], int seq_tamanho) {
    clock_t inicio, fim;
    double tempo_cpu_usado;

    inicio = clock();
    funcOrdenacao(arr, n, seq, seq_tamanho);
    fim = clock();

    tempo_cpu_usado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_cpu_usado;
}

void copiarArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {

    int tamanhos[] = {1000, 5000, 10000, 50000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int arr[n], arr_copia[n];

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        int seq_shell[50], tamanho_shell;
        int seq_knuth[50], tamanho_knuth;
        int seq_hibbard[50], tamanho_hibbard;

        sequenciaShell(n, seq_shell, &tamanho_shell);
        sequenciaKnuth(n, seq_knuth, &tamanho_knuth);
        sequenciaHibbard(n, seq_hibbard, &tamanho_hibbard);

        copiarArray(arr, arr_copia, n);
        double tempoShell = medirTempo(ordenacaoShell, arr_copia, n, seq_shell, tamanho_shell);
        printf("Shell Sort (sequência original) - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoShell);

        copiarArray(arr, arr_copia, n);
        double tempoKnuth = medirTempo(ordenacaoShell, arr_copia, n, seq_knuth, tamanho_knuth);
        printf("Shell Sort (sequência de Knuth) - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoKnuth);

        copiarArray(arr, arr_copia, n);
        double tempoHibbard = medirTempo(ordenacaoShell, arr_copia, n, seq_hibbard, tamanho_hibbard);
        printf("Shell Sort (sequência de Hibbard) - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoHibbard);

        printf("\n");
    }

    return 0;
}

