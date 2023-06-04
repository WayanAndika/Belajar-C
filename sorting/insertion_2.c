#include <stdio.h>
#include <malloc.h>

int *ins_sort(int *arr, int start, int end)
{
    start++;
    for (int i = start; i < end; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= start - 1 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return arr;
}

int main(void)
{
    int *arr;
    arr = (int *)malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i += 1)
    {
        arr[i] = 500 + rand() % 1000;
    }
    arr = ins_sort(arr, 0, 100);
    for (int i = 0; 1 < 100; i += 1)
    {
        printf("%d", arr[i]);
    }
    free(arr);
    return 0;
}