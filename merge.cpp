#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mesclarStrings(const char *arr[], int esquerdo, int meio, int direito) {
    int n1 = meio - esquerdo + 1;
    int n2 = direito - meio;

    
    const char **L = (const char **)malloc(n1 * sizeof(const char *));
    const char **R = (const char **)malloc(n2 * sizeof(const char *));

   
    for (int i = 0; i < n1; i++)
        L[i] = arr[esquerdo + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[meio + 1 + i];

    int i = 0, j = 0, k = esquerdo;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void ordenarStrings(const char *arr[], int esquerdo, int direito) {
    if (esquerdo < direito) {
        int meio = esquerdo + (direito - esquerdo) / 2;

        ordenarStrings(arr, esquerdo, meio);
        ordenarStrings(arr, meio + 1, direito);

        mesclarStrings(arr, esquerdo, meio, direito);
    }
}

void imprimirArrayDeStrings(const char *arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

int main() {
 
    const char *arr[] = {"laranja", "morango", "abacaxi", "manga", "uva"};
    int tamanhoArr = sizeof(arr) / sizeof(arr[0]);

    printf("Array original de frutas: \n");
    imprimirArrayDeStrings(arr, tamanhoArr);

    ordenarStrings(arr, 0, tamanhoArr - 1);

    printf("\nArray de frutas ordenado: \n");
    imprimirArrayDeStrings(arr, tamanhoArr);
    return 0;
}

