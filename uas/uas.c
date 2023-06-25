#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct
{
    char namaCustomer[MAX_NAME_LENGTH];
    char alamat[MAX_NAME_LENGTH];
    char namaItem[MAX_NAME_LENGTH];
    int jumlah;
    double totalHarga;
} Order;

typedef struct
{
    Order *orders;
    int front;
    int rear;
    int size;
} OrderQueue;

void initializeQueue(OrderQueue *queue, int size)
{
    queue->orders = (Order *)malloc(size * sizeof(Order));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int isQueueEmpty(OrderQueue *queue)
{
    return queue->front == -1;
}

int isQueueFull(OrderQueue *queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(OrderQueue *queue, Order order)
{
    if (isQueueFull(queue))
    {
        printf("Cart Penuh. Tidak bisa tambah Pesanan.\n");
        return;
    }
    if (isQueueEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->orders[queue->rear] = order;
}

Order dequeue(OrderQueue *queue)
{
    Order order = queue->orders[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->size;
    return order;
}

void printOrders(OrderQueue *queue)
{
    int current = queue->front;
    if (current == -1)
    {
        printf("\033[31m"); // warna merah
        printf("\033[1m");  // Teks tebal
        printf("|%-4s  %-10s  %-4s |\n", " ", "TIDAK ADA PESANAN DALAM CART", " ");
        printf("-------------------------------------------\n");
        return;
    }
    printf("\033[35m"); // warna magenta
    printf("\033[1m");  // Teks tebal
    printf("|%-9s  %-10s  %-10s|\n", " ", "PESANAN DALAM CART", " ");
    while (current != queue->rear)
    {
        printf("-------------------------------------------\n");
        printf("| %-15s | %-21s |\n", "Nama Customer", queue->orders[current].namaCustomer);
        printf("| %-15s | %-21s |\n", "Alamat", queue->orders[current].alamat);
        printf("| %-15s | %-21s |\n", "Nama Item", queue->orders[current].namaItem);
        printf("| %-15s | %-21d |\n", "Jumlah", queue->orders[current].jumlah);
        printf("| %-15s | %-21.2f |\n", "Total Harga", queue->orders[current].totalHarga);
        printf("-------------------------------------------\n");
        current = (current + 1) % queue->size;
    }
    printf("-------------------------------------------\n");
    printf("| %-15s | %-21s |\n", "Nama Customer", queue->orders[current].namaCustomer);
    printf("| %-15s | %-21s |\n", "Alamat", queue->orders[current].alamat);
    printf("| %-15s | %-21s |\n", "Nama Item", queue->orders[current].namaItem);
    printf("| %-15s | %-21d |\n", "Jumlah", queue->orders[current].jumlah);
    printf("| %-15s | %-21.2f |\n", "Total Harga", queue->orders[current].totalHarga);
    printf("-------------------------------------------\n");
}

void sortOrders(OrderQueue *queue)
{
    int i, j;
    int n = (queue->rear - queue->front + queue->size + 1) % queue->size;
    Order temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (queue->orders[(queue->front + j) % queue->size].totalHarga <
                queue->orders[(queue->front + j + 1) % queue->size].totalHarga)
            {
                temp = queue->orders[(queue->front + j) % queue->size];
                queue->orders[(queue->front + j) % queue->size] = queue->orders[(queue->front + j + 1) % queue->size];
                queue->orders[(queue->front + j + 1) % queue->size] = temp;
            }
        }
    }
}

int searchOrder(OrderQueue *queue, const char *namaItem)
{
    int current = queue->front;
    int count = 0;
    if (current == -1)
    {
        printf("No orders in the queue.\n");
        return 0;
    }
    while (current != queue->rear)
    {
        if (strcmp(queue->orders[current].namaItem, namaItem) == 0)
        {
            count++;
        }
        current = (current + 1) % queue->size;
    }
    if (strcmp(queue->orders[current].namaItem, namaItem) == 0)
    {
        count++;
    }
    return count;
}

int main()
{
    int queueSize = 10;
    OrderQueue orderQueue;
    initializeQueue(&orderQueue, queueSize);

    int pilihan;
    do
    {
        // Warna teks
        printf("\033[1;32m"); // Warna hijau terang untuk teks
        printf("===========================================\n");

        // Tampilan tabel dengan garis horizontal
        printf("\033[1m"); // Teks tebal
        printf("| %-4s  %-10s  %-4s |\n", " ", "SELAMAT DATANG DI TOKO JAYA", " ");
        printf("===========================================\n");

        // Tampilan tabel dengan garis horizontal
        printf("\033[33m"); // warna kuning
        printf("\033[1m");  // Teks tebal

        printf("| %-15s  %-10s  %-10s |\n", " ", "MENU", " ");

        printf("-------------------------------------------\n");
        printf("\033[0m");  // Reset teks
        printf("\033[33m"); // Reset warna

        printf("| %s | %-34s |\n", "1.", "Tambah Pesanan.");
        printf("| %s | %-34s |\n", "2.", "Kirim Pesanan.");
        printf("| %s | %-34s |\n", "3.", "Tampilkan Semua Pesanan.");
        printf("| %s | %-34s |\n", "4.", "Sorting Pesanan berdasarkan total.");
        printf("| %s | %-34s |\n", "5.", "Cari Pesanan berdasarkan nama.");
        printf("| %s | %-34s |\n", "6.", "Keluar.");

        printf("-------------------------------------------\n");
        printf("|%s ", " Masukan Pilihan: ");
        scanf("%d", &pilihan);
        printf("-------------------------------------------\n");
        switch (pilihan)
        {
        case 1:
        {
            Order newOrder;
            getchar();
            printf("| Masukan Nama Customer: ");
            fgets(newOrder.namaCustomer, 50, stdin);
            newOrder.namaCustomer[strcspn(newOrder.namaCustomer, "\n")] = '\0';
            printf("| Masukan Alamat: ");
            fgets(newOrder.alamat, 50, stdin);
            newOrder.alamat[strcspn(newOrder.alamat, "\n")] = '\0';
            printf("| Masukan Nama Item: ");
            fgets(newOrder.namaItem, 50, stdin);
            newOrder.namaItem[strcspn(newOrder.namaItem, "\n")] = '\0';
            printf("| Masukan Jumlah: ");
            scanf("%d%*c", &newOrder.jumlah);

            printf("| Masukan Total Harga: ");
            scanf("%lf%*c", &newOrder.totalHarga);

            enqueue(&orderQueue, newOrder);

            printf("\033[1;32m");
            printf("-------------------------------------------\n");
            printf("|%-40s|\n", " Order Ditambahkan ke cart.");
            printf("-------------------------------------------\n");
            break;
        }
        case 2:
        {
            if (isQueueEmpty(&orderQueue))
            {
                printf("\033[31m"); // warna merah
                printf("\033[1m");  // Teks tebal
                printf("|%-4s  %-10s  %-4s |\n", " ", "TIDAK ADA PESANAN DALAM CART", " ");
                printf("-------------------------------------------\n");
                break;
            }
            Order processedOrder = dequeue(&orderQueue);
            if (strcmp(processedOrder.namaCustomer, "") != 0)
            {
                printf("\033[34m"); // warna biru
                printf("\033[1m");  // Teks tebal
                printf("|%-9s  %-10s  %-8s|\n", " ", "PESANAN YANG DIKIRIM", " ");
                printf("-------------------------------------------\n");
                printf("| %-15s | %-21s |\n", "Nama Customer", processedOrder.namaCustomer);
                printf("| %-15s | %-21s |\n", "Alamat", processedOrder.alamat);
                printf("| %-15s | %-21s |\n", "Nama Item", processedOrder.namaItem);
                printf("| %-15s | %-21d |\n", "Jumlah", processedOrder.jumlah);
                printf("| %-15s | %-21.2f |\n", "Total Harga", processedOrder.totalHarga);
                printf("-------------------------------------------\n");
            }
            break;
        }
        case 3:
        {
            printOrders(&orderQueue);
            break;
        }
        case 4:
        {
            if (isQueueEmpty(&orderQueue))
            {
                printf("\033[31m"); // warna merah
                printf("\033[1m");  // Teks tebal
                printf("|%-4s  %-10s  %-4s |\n", " ", "TIDAK ADA PESANAN DALAM CART", " ");
                printf("-------------------------------------------\n");
                break;
            }
            sortOrders(&orderQueue);
            printf("\033[34m"); // warna biru
            printf("\033[1m");  // Teks tebal
            printf("|%-4s  %-10s  %-4s |\n", " ", "PESANAN BERHASIL DIURUTKAN", " ");
            printf("-------------------------------------------\n");
            break;
        }
        case 5:
        {
            char searchnamaItem[MAX_NAME_LENGTH];
            if (isQueueEmpty(&orderQueue))
            {
                printf("\033[31m"); // warna merah
                printf("\033[1m");  // Teks tebal
                printf("|%-4s  %-10s  %-4s |\n", " ", "TIDAK ADA PESANAN DALAM CART", " ");
                printf("-------------------------------------------\n");
                break;
            }
            printf("-------------------------------------------\n");
            printf("|%s ", " Masukan Nama Item: ");
            scanf("%s", &searchnamaItem);
            printf("-------------------------------------------\n");
            int count = searchOrder(&orderQueue, searchnamaItem);
            printf("\033[1;32m"); // warna hijau
            printf("\033[1m");    // Teks tebal
            printf("| %d pesanan dengan Nama Item '%s'. |\n", count, searchnamaItem);
            printf("-------------------------------------------\n");
            break;
        }
        case 6:
            printf("\033[36m"); // warna cyan
            printf("\033[1m");  // Teks tebal
            printf("|%-9s  %-10s  %-9s |\n", " ", "KELUAR DARI SISTEM", " ");
            printf("-------------------------------------------\n");
            break;
        default:
            printf("\033[31m"); // warna merah
            printf("\033[1m");  // Teks tebal
            printf("|%-4s  %-10s  %-4s |\n", " ", "YANG ANDA MASUKAN TIDAK ADA", " ");
            printf("-------------------------------------------\n");
            break;
        }
        printf("\n");
    } while (pilihan != 6);

    free(orderQueue.orders);
    return 0;
}
