#include <stdio.h>\
#include <malloc.h>

void createArray(int *arr, int a)
{
    int i;
    for (i = 0; i < a; i++)
    {
        arr[i] = 0;
    }
}
void inputArray(int *arr, int a)
{
    int i;
    for (i = 0; i < a; i++)
    {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

//*mencari array
int findIndex(int *arr, int a, int nilai)
{
    int i;
    for (i = 0; i < a; i++)
    {
        if (arr[i] == nilai)
        {
            return i;
        }
    }
    return -1;
}

//*mengubah nilai array
void updateValue(int *arr, int index, int nilai)
{
    arr[index] = nilai;
    printf("Nilai pada indeks %d berhasil diubah menjadi %d\n", index, nilai);
}

void printArray(int *arr, int a)
{
    int i;
    printf("[");
    for (i = 0; i < a - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[a - 1]);
}

int main()
{
    int pilihan, arr, nilai, index, choice;
    printf("Masukan Nilai yang Diinginkan: ");
    scanf("%d", &arr);
    int *array = (int *)malloc(arr * sizeof(int));
    createArray(array, arr);
    printf("]\n");
    switch (1)
    {
        printf("-----Menu Pilihan------\n");
        printf("1. Input Nilai.\n");
        printf("2. Cari Nilai.\n");
        printf("3. Edit Nilai.\n");
        printf("0. Exit.\n");
        printf("-----------------------\n");
        printf("Masukan Pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 0:
            printf("Terima kasih telah menggunakan program ini\n");
            exit(0);
            break;
        case 1:
            inputArray(array, arr);
            break;
        case 2:
            printf("Masukkan nilai yang ingin dicari: ");
            scanf("%d", &nilai);
            index = findIndex(arr, index, nilai);
            if (index == -1)
            {
                printf("Nilai %d tidak ditemukan dalam Array\n", nilai);
            }
            else
            {
                printf("Nilai %d ditemukan pada indeks %d\n", nilai, index);
            }
            break;
        case 3:
            printf("Masukkan indeks yang ingin diubah: ");
            scanf("%d", &index);
            if (index < 0 || index >= arr)
            {
                printf("Indeks tidak valid\n");
            }
            else
            {
                printf("Masukkan nilai baru: ");
                scanf("%d", &nilai);
                updateValue(array, arr, nilai);
            }
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }
    }
    free(array);
    return 0;
}