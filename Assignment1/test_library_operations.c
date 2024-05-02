#include <assert.h>
#include "library_operations.h"

void test_add_and_find_book() {
    Library lib;
    init_library(&lib);
    
    add_book(&lib, 1, "2000", "hh bb");
    Book *book = find_book(&lib, 1);
    assert(book != NULL && "Book should be found");
    assert(book->book_id == 1 && "Book ID should match");
    assert(strcmp(book->title, "1984") == 0 && "Book title should match");
    assert(strcmp(book->author, "George Orwell") == 0 && "Book author should match");

    printf("test_add_and_find_book passed.\n");
}

void test_add_and_find_borrower() {
    Library lib;
    init_library(&lib);
    
    add_borrower(&lib, 1, "John Doe");
    Borrower *borrower = find_borrower(&lib, 1);
    assert(borrower != NULL && "Borrower should be found");
    assert(borrower->borrower_id == 1 && "Borrower ID should match");
    assert(strcmp(borrower->name, "John Doe") == 0 && "Borrower name should match");

    printf("test_add_and_find_borrower passed.\n");
}

int main() {
    test_add_and_find_book();
    test_add_and_find_borrower();
    return 0;
}

