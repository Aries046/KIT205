#include <stdio.h>
#include "list.h" 

int main() {
    List my_list = new_list();

    insert_at_front(&my_list, 10);
    insert_at_front(&my_list, 20);
    insert_at_front(&my_list, 30);

    printf("List contents: ");
    print_list(&my_list);

    return 0;
}