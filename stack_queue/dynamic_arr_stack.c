#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *arr;
    int top;
    int capacity;
} Stack;
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}
void push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack penuh. Tidak bisa menambahkan %d.\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("Menambahkan %d ke dalam stack.\n", data);
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack kosong.\n");
        return -1;
    }
    int data = stack->arr[stack->top--];
    printf("Menghapus %d dari stack.\n", data);
    return data;
}
void displayStack(int *arr, int top)
{
    if (top == -1)
    {
        printf("Stack kosong.\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int nilai, menu, kapasitas;
    int capacity = 3;
    Stack *stack = createStack(capacity);
    while (1)
    {
        printf("Menu\n");
        printf("1.Tambah.\n");
        printf("2.Hapus.\n");
        printf("0.Keluar.\n");
        printf("Masukan pilihan: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            printf("Terima Kasih telah menggunakan program ini.");
            exit(0);
            break;
        case 1:
            printf("Masukan Nilai: ");
            scanf("%d", &nilai);
            push(stack, nilai);
            displayStack(stack->arr, stack->top);
            break;
        case 2:
            pop(stack);
            displayStack(stack->arr, stack->top);
            break;
        default:
            printf("Yang Anda Masukan Tidak Ada!");
            break;
        }
    }
    return 0;
}
