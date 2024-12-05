#include <stdio.h>

void trocar(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void exibirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, indice_minimo;

    
    for (i = 0; i < n-1; i++) {
        
        indice_minimo = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[indice_minimo])
                indice_minimo = j;

        
        trocar(&arr[indice_minimo], &arr[i]);

        
        printf("Passo %d: ", i+1);
        exibirArray(arr, n);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original:\n");
    exibirArray(arr, n);

    selectionSort(arr, n);

    printf("\nArray ordenado:\n");
    exibirArray(arr, n);
    return 0;
}

