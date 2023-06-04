#include <stdio.h>

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
    printf("]");
    printf("\n");
}

int main()
{
    int arr[] = {20, 95, 85, 70, 30, 10, 5, 2, 90, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array sebelum pengurutan: \n");
    printArr(arr, n);
    selectionSort(arr, n);
    printf("Array setelah pengurutan: \n");
    printArr(arr, n);
    return 0;
}
