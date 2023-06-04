#include <stdio.h>
#include <string.h>

struct product {
    char name[50];
    int price;
};

int sequentialSearch(struct product *p, int n, char *searchKey) {
    int i;
    for(i = 0; i < n; i++) {
        if(strcmp(searchKey, p[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct product p[5] = {
        {"Mouse", 20000},
        {"Keyboard", 50000},
        {"Monitor", 100000},
        {"Speaker", 80000},
        {"Headset", 70000}
    };
    int n = sizeof(p) / sizeof(p[0]);
    
    char searchKey[50] = "Monitor";
    int result = sequentialSearch(p, n, searchKey);
    if(result == -1) {
        printf("Data not found.\n");
    } else {
        printf("Data found at index %d.\n", result);
        printf("Product name: %s, Price: %d\n", p[result].name, p[result].price);
    }
    return 0;
}
