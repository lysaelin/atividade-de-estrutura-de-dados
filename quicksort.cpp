#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}


int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Parti��o usando o elemento do meio como piv�
int partitionMiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(&arr[mid], &arr[high]);  // Troca o meio com o �ltimo
    return partitionLast(arr, low, high);
}

// Fun��o para realizar o Quick Sort com base no piv� escolhido
void quickSort(int arr[], int low, int high, int pivotType) {
    if (low < high) {
        int pi;

        // Escolher a fun��o de parti��o com base no piv�
        if (pivotType == 1)
            pi = partitionFirst(arr, low, high);     // Piv�: primeiro elemento
        else if (pivotType == 2)
            pi = partitionLast(arr, low, high);      // Piv�: �ltimo elemento
        else
            pi = partitionMiddle(arr, low, high);    // Piv�: elemento do meio

        // Recurs�o para as duas metades
        quickSort(arr, low, pi - 1, pivotType);
        quickSort(arr, pi + 1, high, pivotType);
    }
}

// Fun��o para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Testando Quick Sort com o piv� sendo o primeiro elemento
    printf("Quick Sort (Piv�: Primeiro Elemento):\n");
    quickSort(arr, 0, n - 1, 1);
    printArray(arr, n);

    // Revertendo o array para testar as outras op��es
    int arr2[] = {10, 7, 8, 9, 1, 5};
    printf("\nQuick Sort (Piv�: �ltimo Elemento):\n");
    quickSort(arr2, 0, n - 1, 2);
    printArray(arr2, n);

    // Revertendo o array para testar as outras op��es
    int arr3[] = {10, 7, 8, 9, 1, 5};
    printf("\nQuick Sort (Piv�: Elemento do Meio):\n");
    quickSort(arr3, 0, n - 1, 3);
    printArray(arr3, n);

    return 0;
}
