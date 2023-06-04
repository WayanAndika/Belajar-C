#include <stdio.h>
#include <string.h>

struct product
{
    char name[50];
    int price;
};

int binarySearch(struct product *p, int n, char *searchKey)
{
    int mid, low, high;
    low = 0;
    high = n - 1;
    // printf("ini dari func: %ss", searchKey);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (strcmp(searchKey, p[mid].name) == 0)
            return mid;
        if (strcmp(searchKey, p[mid].name) < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    struct product p[5] = {
        {"Mouse", 20000},
        {"Keyboard", 50000},
        {"Monitor", 100000},
        {"Speaker", 80000},
        {"Headset", 70000}};
    int n = sizeof(p) / sizeof(p[0]);

    char searchKey[50] = "Monitor";
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
    return 0;
}
