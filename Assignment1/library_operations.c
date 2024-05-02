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
    new_book->left = new_book->right = NULL;

    Book **ptr = &(lib->books);
    while (*ptr) {
        Book *current = *ptr;
        if (book_id < current->book_id)
            ptr = &current->left;
        else
            ptr = &current->right;
    }
    *ptr = new_book;
}

void add_borrower(Library *lib, int borrower_id, const char *name) {
    Borrower *new_borrower = (Borrower *)malloc(sizeof(Borrower));
    new_borrower->borrower_id = borrower_id;
    strcpy(new_borrower->name, name);
    new_borrower->next = lib->borrowers;
    lib->borrowers = new_borrower;
}

Book* find_book(Book *root, int book_id) {
    while (root) {
        if (book_id < root->book_id)
            root = root->left;
        else if (book_id > root->book_id)
            root = root->right;
        else
            return root;
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

void print_books(Book *root) {
    if (root != NULL) {
        print_books(root->left);
        printf("ID: %d, Title: %s, Author: %s\n", root->book_id, root->title, root->author);
        print_books(root->right);
    }
}

void print_library(Library *lib) {
    printf("Books:\n");
    print_books(lib->books);

    printf("Borrowers:\n");
    Borrower *current_borrower = lib->borrowers;
    while (current_borrower) {
        printf("ID: %d, Name: %s\n", current_borrower->borrower_id, current_borrower->name);
        current_borrower = current_borrower->next;
    }
}
