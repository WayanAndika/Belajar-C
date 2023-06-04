#include <stdio.h>
#include <string.h>

struct product
{
    int id;
    char name[40];
    int price;
};
int sequentialSearch(struct product *p, int n, char *searchKey)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(searchKey, p[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    struct product p[7] =
        {
            {11112, "Dining chairs", 100},
            {11113, "Sofas", 150},
            {12321, "Bookselves", 90},
            {14589, "Cabinet", 115},
            {14777, "Drawer", 100},
            {11973, "Wardobe closet", 210},
            {13876, "Bean bag", 55},

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
        int result = sequentialSearch(p, n, searchKey);
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
