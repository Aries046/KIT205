#include <stdio.h>
#include "library_operations.h"

void display_menu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Find Book\n");
    printf("3. Print Library\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Library lib;
    init_library(&lib);

    int choice;
    int book_id;
    char title[100];
    char author[100];
    Book *book;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter book ID, title, and author: ");
            scanf("%d%99s%99s", &book_id, title, author);
            add_book(&lib, book_id, title, author);
            break;
        case 2:
            printf("Enter book ID to find: ");
            scanf("%d", &book_id);
            book = find_book(&lib, book_id);
            if (book) {
                printf("Book found: %d, %s, %s\n", book->book_id, book->title, book->author);
            } else {
                printf("Book not found.\n");
            }
            break;
        case 3:
            print_library(&lib);
            break;
        case 4:
            return 0;  // Exit program
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

