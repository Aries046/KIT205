#include <stdio.h>
#include "list.h"

int main() {
    List my_list = new_list();

    int input;

    // Reads integers from user input until the input is 0.
    while (1) {
        printf("Enter an integer (0 to exit): ");
        scanf("%d", &input);

        if (input == 0)
            break;

        insert_at_front(&my_list, input);
    }

    destroy_list(&my_list);

    return 0;
}