#include "library_operations.h"

void init_library(Library *lib) {
    lib->books = NULL;
    lib->borrowers = NULL;
}

void add_book(Library *lib, int book_id, const char *title, const char *author) {
    Book *new_book = (Book *)malloc(sizeof(Book));
    new_book->book_id = book_id;
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->next = lib->books;
    lib->books = new_book;
}

void add_borrower(Library *lib, int borrower_id, const char *name) {
    Borrower *new_borrower = (Borrower *)malloc(sizeof(Borrower));
    new_borrower->borrower_id = borrower_id;
    strcpy(new_borrower->name, name);
    new_borrower->next = lib->borrowers;
    lib->borrowers = new_borrower;
}
