#include "library_operations.h"
#include <time.h>

void performance_test(Library *lib, int num_books) {
    srand(time(NULL));
    for (int i = 0; i < num_books; i++) {
        int id = rand() % num_books;
        char title[30], author[30];
        sprintf(title, "Book%d", id);
        sprintf(author, "Author%d", id);
        add_book(lib, id, title, author);
    }

    clock_t start = clock();
    for (int i = 0; i < num_books; i++) {
        find_book(lib->books, rand() % num_books);
    }
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent for %d operations: %f seconds\n", num_books, time_spent);
}

int main() {
    Library lib;
    init_library(&lib);
    performance_test(&lib, 10000);
    return 0;
}

