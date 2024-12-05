#include <stdio.h>
#include <stdlib.h>

int obterMaximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void contagemSort(int arr[], int n, int exp) {
    int saida[n]; 
    int contagem[10] = {0}; 
    int i;

    
    for (i = 0; i < n; i++)
        contagem[(arr[i] / exp) % 10]++;

    
    for (i = 1; i < 10; i++)
        contagem[i] += contagem[i - 1];

 
    for (i = n - 1; i >= 0; i--) {
        saida[contagem[(arr[i] / exp) % 10] - 1] = arr[i];
        contagem[(arr[i] / exp) % 10]--;
    }

    
    for (i = 0; i < n; i++)
        arr[i] = saida[i];
}


void radixSort(int arr[], int n) {
   
    int max = obterMaximo(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        contagemSort(arr, n, exp);
}

void exibirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    exibirArray(arr, n);

    radixSort(arr, n);

    printf("Array ordenado:\n");
    exibirArray(arr, n);

    return 0;
}

