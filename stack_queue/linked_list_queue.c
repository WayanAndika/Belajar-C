#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef struct
{
    Node *front;
    Node *rear;
} Queue;
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
void enqueue(Queue *queue, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Menambahkan %d ke dalam queue.\n", data);
}

int serve(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue kosong.\n");
        return -1;
    }

    int data = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    printf("Hapus %d dari queue.\n", data);
    return data;
}
void displayQueue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue kosong.\n");
    }
    else
    {
        Node *current = queue->front;
        printf("Queue: ");
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
    Queue *queue = createQueue();
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
            enqueue(queue, nilai);
            displayQueue(queue);
            break;
        case 2:
            serve(queue);
            displayQueue(queue);
            break;
        default:
            printf("Yang Anda Masukan Tidak Ada!");
            break;
        }
    }
    return 0;
}
