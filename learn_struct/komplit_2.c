#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    int count;
};

// Fungsi untuk menambah node baru di awal linked list
void addNodeAtBeginning(struct LinkedList *list, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

// Fungsi untuk menambah node baru di akhir linked list
void addNodeAtEnd(struct LinkedList *list, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        struct Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

// Fungsi untuk menampilkan isi linked list
void displayList(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong\n");
    }
    else
    {
        struct Node *current = list->head;
        printf("Isi linked list adalah: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Fungsi untuk mencari node dengan nilai tertentu
struct Node *searchNode(struct LinkedList *list, int key)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(struct LinkedList *list, int key)
{
    struct Node *current = list->head, *previous = NULL;
    while (current != NULL && current->data != key)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Node dengan nilai {%d} tidak ditemukan\n", key);
    }
    else
    {
        if (previous == NULL)
        {
            list->head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
        list->count--;
        printf("Node dengan nilai %d berhasil dihapus\n", key);
    }
}

// Fungsi untuk menghapus seluruh isi linked list
void deleteList(struct LinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->count = 0;
}

int main()
{
    struct LinkedList list;
    list.head = NULL;
    list.count = 0;

    int choice, value;
    while (1)
    {
        printf("Menu:\n");
        printf("1. Tambah node di awal linked list\n");
        printf("2. Tambah node di akhir linked list\n");
        printf("3. Tampilkan isi linked list\n");
        printf("4. Cari node dengan nilai tertentu\n");
        printf("5. Hapus isi linked list dengan node tertentu\n");
        printf("6. Hapus seluruh isi linked list\n");
        printf("0. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Terima kasih telah menggunakan program ini!\n");
            exit(0);
        case 1:
            printf("Masukkan nilai: ");
            scanf("%d", &value);
            addNodeAtBeginning(&list, value);
            printf("Node dengan nilai %d berhasil ditambahkan di awal linked list\n", value);
            break;
        case 2:
            printf("Masukkan nilai: ");
            scanf("%d", &value);
            addNodeAtEnd(&list, value);
            printf("Node dengan nilai %d berhasil ditambahkan di akhir linked list\n", value);
            break;
        case 3:
            displayList(&list);
            break;
        case 4:
            printf("Masukkan nilai yang ingin dicari: ");
            scanf("%d", &value);
            struct Node *foundNode = searchNode(&list, value);
            if (foundNode == NULL)
            {
                printf("Node dengan nilai %d tidak ditemukan\n", value);
            }
            else
            {
                printf("Node dengan nilai %d ditemukan pada alamat %p\n", value, foundNode);
            }
            break;
        case 5:
            printf("Masukkan nilai yang ingin dihapus: ");
            scanf("%d", &value);
            deleteNode(&list, value);
            break;
        case 6:
            deleteList(&list);
            printf("Seluruh isi linked list berhasil dihapus\n");
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }
        printf("\n");
    }
    return 0;
}

// Penjelasan tiap-tiap fungsi dan metode dalam implementasi linked list di atas adalah sebagai berikut:
//
// 1. `struct Node`: merupakan struktur untuk merepresentasikan node dalam linked list. Setiap node memiliki dua atribut, yaitu `data` untuk menyimpan data yang ada di dalam node dan `next` untuk menunjuk ke node berikutnya di linked list.
//
// 2. `struct LinkedList`: merupakan struktur untuk merepresentasikan linked list secara keseluruhan. Atribut `head` menyimpan alamat node pertama dalam linked list dan `count` menyimpan jumlah node dalam linked list.
//
// 3. `addNodeAtBeginning()`: merupakan fungsi untuk menambah node baru di awal linked list. Fungsi ini menerima dua parameter, yaitu alamat linked list dan nilai yang akan dimasukkan ke dalam node baru. Fungsi ini mengalokasikan memori untuk node baru, mengatur nilai atribut `data` dan `next` dari node baru, dan mengatur alamat node baru sebagai node pertama dalam linked list.
//
// 4. `addNodeAtEnd()`: merupakan fungsi untuk menambah node baru di akhir linked list. Fungsi ini menerima dua parameter, yaitu alamat linked list dan nilai yang akan dimasukkan ke dalam node baru. Fungsi ini mengalokasikan memori untuk node baru, mengatur nilai atribut `data` dan `next` dari node baru, dan menemukan node terakhir dalam linked list untuk menetapkan alamat node baru sebagai node berikutnya.
//
// 5. `displayList()`: merupakan fungsi untuk menampilkan isi linked list. Fungsi ini menerima satu parameter, yaitu alamat linked list. Jika linked list kosong, fungsi ini menc
