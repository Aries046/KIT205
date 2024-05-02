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
Book* find_book(Library *lib, int book_id) {
    Book *current = lib->books;
    while (current) {
        if (current->book_id == book_id) return current;
        current = current->next;
    }
    return NULL;
}

Borrower* find_borrower(Library *lib, int borrower_id) {
    Borrower *current = lib->borrowers;
    while (current) {
        if (current->borrower_id == borrower_id) return current;
        current = current->next;
    }
    return NULL;
}

void print_library(Library *lib) {
    Book *current_book = lib->books;
    printf("Books:\n");
    while (current_book) {
        printf("ID: %d, Title: %s, Author: %s\n", current_book->book_id, current_book->title, current_book->author);
        current_book = current_book->next;
    }
    Borrower *current_borrower = lib->borrowers;
    printf("Borrowers:\n");
    while (current_borrower) {
        printf("ID: %d, Name: %s\n", current_borrower->borrower_id, current_borrower->name);
        current_borrower = current_borrower->next;
    }
}
