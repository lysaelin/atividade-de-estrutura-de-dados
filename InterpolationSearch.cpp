#include <stdio.h>


int buscaInterpolacao(int arr[], int n, int x) {
    int baixo = 0, alto = n - 1;

    while (baixo <= alto && x >= arr[baixo] && x <= arr[alto]) {
        if (baixo == alto) {
            if (arr[baixo] == x) return baixo;
            return -1;
        }
        int pos = baixo + ((double)(alto - baixo) / (arr[alto] - arr[baixo]) * (x - arr[baixo]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            baixo = pos + 1;
        else
            alto = pos - 1;
    }
    return -1; 
}

int buscaBinaria(int arr[], int baixo, int alto, int x) {
    if (alto >= baixo) {
        int meio = baixo + (alto - baixo) / 2;

        if (arr[meio] == x)
            return meio;

        if (arr[meio] > x)
            return buscaBinaria(arr, baixo, meio - 1, x);

        return buscaBinaria(arr, meio + 1, alto, x);
    }

    return -1; 
}

void testarBuscas(int arr[], int n, int x) {
    printf("Buscando valor %d...\n", x);

    int resultadoInterpolacao = buscaInterpolacao(arr, n, x);
    if (resultadoInterpolacao != -1)
        printf("Busca por Interpolação encontrou o valor no índice %d\n", resultadoInterpolacao);
    else
        printf("Busca por Interpolação não encontrou o valor\n");
 
    int resultadoBinaria = buscaBinaria(arr, 0, n - 1, x);
    if (resultadoBinaria != -1)
        printf("Busca Binária encontrou o valor no índice %d\n", resultadoBinaria);
    else
        printf("Busca Binária não encontrou o valor\n");

    printf("\n");
}

int main() {
   
    int arr_uniforme[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n_uniforme = sizeof(arr_uniforme) / sizeof(arr_uniforme[0]);

    int arr_nao_uniforme[] = {10, 22, 35, 47, 53, 68, 72, 81, 93, 101};
    int n_nao_uniforme = sizeof(arr_nao_uniforme) / sizeof(arr_nao_uniforme[0]);
  
    printf("Testando com lista de intervalos uniformes:\n");
    testarBuscas(arr_uniforme, n_uniforme, 70);
    testarBuscas(arr_uniforme, n_uniforme, 25);

    printf("Testando com lista de intervalos não uniformes:\n");
    testarBuscas(arr_nao_uniforme, n_nao_uniforme, 68);
    testarBuscas(arr_nao_uniforme, n_nao_uniforme, 50);

    return 0;
}

