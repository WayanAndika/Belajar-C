#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void printArr(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i != size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int pilihan;
    int arr[] = {20, 95, 85, 70, 30, 10, 5, 2, 90, 40};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Array sebelum pengurutan: \n");
    printArr(arr, arr_size);
    while (1)
    {
        printf("Pilihan Sort : \n");
        printf("1. Selection Sort.\n");
        printf("2. Shell Sort.\n");
        printf("0. Exit\n");
        printf("Masukan Pilihan Anda: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 0:
            printf("Terima kasih telah menggunakan program ini!\n");
            exit(0);
        case 1:
            selectionSort(arr, arr_size);
            printf("Array setelah pengurutan menggunkaan Selection Sort: \n");
            printArr(arr, arr_size);
            break;
        case 2:
            shellSort(arr, arr_size);
            printf("Array setelah pengurutan menggunkaan Shell Sort: \n");
            printArr(arr, arr_size);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }
    }
    return 0;
}