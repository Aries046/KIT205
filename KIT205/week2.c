#include <stdio.h>
#include "list.h"

void option_insert(List* my_list);
void option_delete(List* my_list);
void option_print(List* my_list);

int main() {
    List my_list = new_list();

    int quit = 0;

    // Start the loop until you quit
    while (!quit) {
        int option; 

        // menu
        printf("Menu:\n");
        printf("0. Quit\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("Enter option: ");

        scanf("%d", &option);

        switch (option) {
        case 0:
            quit = 1;
            break;
        case 1:
            option_insert(&my_list);
            break;
        case 2:
            option_delete(&my_list);
            break;
        case 3:
            option_print(&my_list);
            break;
        default:
            printf("Invalid option\n");
        }
    }

    /*
    // Reads integers from user input until the input is 0.
    while (1) {
        printf("Enter an integer (0 to exit): ");
        scanf("%d", &input);

        if (input == 0)
            break;

        insert_at_front(&my_list, input);
    }
    */

    destroy_list(&my_list);

    return 0;
}


void option_insert(List* my_list) {
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    insert_at_front(my_list, data);
}

void option_delete(List* my_list) {
    int data;
    printf("Enter data to delete: ");
    scanf("%d", &data);
    delete_list(my_list, data);
}

void option_print(List* my_list) {
    printf("List contents: ");
    print_list(my_list);
}
