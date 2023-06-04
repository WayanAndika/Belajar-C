#include <stdio.h>
#include <string.h>
// pembuatan struct
struct product
{
    int id;
    char name[40];
    int price;
};
// pembuatan function binary search
int binarySearch(struct product *p, int n, char *searchKey)
{
    int mid, low, high;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(searchKey, p[mid].name) == 0)
        {
            return mid;
        }
        else if (strcmp(searchKey, p[mid].name) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    struct product p[7] =
        {
            {13876, "Bean bag", 55},
            {12321, "Bookselves", 90},
            {14589, "Cabinet", 115},
            {11112, "Dining chairs", 100},
            {14777, "Drawer", 100},
            {11113, "Sofas", 150},
            {11973, "Wardobe closet", 210},

        };
    int n = sizeof(p) / sizeof(p[0]);
    // tampilan awal
    printf("==================================\n");
    printf("|----------Data Product----------|\n");
    printf("==================================\n");
    for (int i = 0; i < 7; i++)
    {
        printf("| %d| %d| %s| %d|\n", i, p[i].id, p[i].name, p[i].price);
        printf("==================================\n");
    }
    while (1)
    {
        printf("Masukan Keyword Name: ");
        char searchKey[50];
        fgets(searchKey, 50, stdin);
        searchKey[strcspn(searchKey, "\n")] = '\0';
        int result = binarySearch(p, n, searchKey);
        if (result == -1)
        {
            printf("Data not found.\n");
        }
        else
        {
            printf("Data found at index %d.\n", result);
            printf("Product name: %s, Price: %d\n", p[result].name, p[result].price);
        }
    }
    return 0;
}
