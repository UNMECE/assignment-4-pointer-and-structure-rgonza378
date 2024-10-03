#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;

    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].category = (char *)malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = (char *)malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += item_list[i].price;
    }
    return total / size;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
        printf("###############\n");
    }
}

int main(int argc, char *argv[]) {
    int size = 5;
    Item *item_list = (Item *)malloc(size * sizeof(Item));

    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 6.80, "12345", "snacks", "chips", 2);
    add_item(item_list, 4.50, "67890", "bakery", "bread", 3);
    add_item(item_list, 7.75, "54321", "beverages", "orange juice", 4);

    print_items(item_list, size);

    printf("Average price of items = %f\n", average_price(item_list, size));

    if (argc == 2) {
        char *search_sku = argv[1];
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(item_list[i].sku, search_sku) == 0) {
                printf("Item found:\n");
                printf("item name = %s\n", item_list[i].name);
                printf("item sku = %s\n", item_list[i].sku);
                printf("item category = %s\n", item_list[i].category);
                printf("item price = %f\n", item_list[i].price);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Item not found.\n");
        }
    }

    free_items(item_list, size);
    
    return 0;
}
