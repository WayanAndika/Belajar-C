#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}
int isFull(Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}
void enqueue(Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue penuh. Tidak bisa menambahkan %d.\n", data);
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = data;
    printf("Menambahkan %d ke dalam queue.\n", data);
}

int serve(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue kosong.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    printf("hapus %d dari queue.\n", data);
    return data;
}
void displayQueue(int *arr, int front, int rear, int capacity)
{
    if (front == -1)
    {
        printf("Queue kosong.\n");
    }
    else
    {
        printf("Queue: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", arr[i]);
            i = (i + 1) % capacity;
        }
        printf("%d\n", arr[rear]);
    }
}

int main()
{
    int kapasitas, nilai, menu;
    int capacity = 3;
    Queue *queue = createQueue(capacity);

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
            displayQueue(queue->arr, queue->front, queue->rear, queue->capacity);
            break;
        case 2:
            serve(queue);
            displayQueue(queue->arr, queue->front, queue->rear, queue->capacity);
            break;
        default:
            printf("Yang Anda Masukan Tidak Ada!");
            break;
        }
    }
    return 0;
}
