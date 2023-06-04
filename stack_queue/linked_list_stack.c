#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d ke stack.\n", data);
}

int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack kosong.\n");
        return -1;
    }
    int data = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped %d dari stack.\n", data);
    return data;
}
void displayStack(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack Kosong.\n");
    }
    else
    {
        Node *current = stack->top;
        printf("Stack: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
int main()
{
    int menu, nilai;
    Stack *stack = createStack();
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
            displayStack(stack);
            break;
        case 2:
            pop(stack);
            displayStack(stack);
            break;
        default:
            printf("Yang Anda Masukan Tidak Ada!");
            break;
        }
    }
    return 0;
}
