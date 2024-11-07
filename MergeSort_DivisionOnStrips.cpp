#include <stdio.h>
#include <stdlib.h>

void exibir_arrayfaixas(int arr[], int tamanho, int faixa){
    int faixa_exib = (faixa+1) * 10;
    printf("Faixa %d ate a %d graus: ", faixa_exib - 9, faixa_exib - 1);
    for (int i = 0; i < tamanho; i++) {
        printf("%d C ", arr[i]);
    }
    printf("\n");
}

void divisao_faixas(int arr[], int tamanho_arr){
    int faixa = arr[0] / 10;
    int i = 0;
    while (i < tamanho_arr) {
        int faixa_arr[tamanho_arr];
        int tamanho_nova_arr = 0;
        while (i < tamanho_arr && arr[i] / 10 == faixa) {
            faixa_arr[tamanho_nova_arr] = arr[i];
            tamanho_nova_arr++;
            i++;
        }
        exibir_arrayfaixas(faixa_arr, tamanho_nova_arr, faixa);
        faixa++;
    }
}

void merge(int arr[], int inicio, int meio, int tamanho)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = tamanho - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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
}

void mergeSort(int arr[], int inicio, int tamanho_arr)
{
    if (inicio < tamanho_arr) {
        int meio = inicio + (tamanho_arr - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, tamanho_arr);

        merge(arr, inicio, meio, tamanho_arr);
    }
}

void exibir_array(int arr[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7,30,23,24,51,12,32,24 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array dada e: \n");
    exibir_array(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Temperaturas agrupadas por intervalos de 10 graus: \n");
    divisao_faixas(arr, arr_size);

    return 0;
}
