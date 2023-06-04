#include <stdio.h>

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
void printArr(int arr[], int arr_size)
{
    printf("[");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d", arr[i]);
        if (i != arr_size - 1)
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
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Array sebelum pengurutan: \n");
    printArr(arr, arr_size);
    shellSort(arr, arr_size);
    printf("Array setelah pengurutan: \n");
    printArr(arr, arr_size);

    return 0;
}
