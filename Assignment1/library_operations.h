#ifndef LIBRARY_OPERATIONS_H
#define LIBRARY_OPERATIONS_H

#include "data_structures.h"

void init_library(Library *lib);
void add_book(Library *lib, int book_id, const char *title, const char *author);
void add_borrower(Library *lib, int borrower_id, const char *name);
Book* find_book(Library *lib, int book_id);
Borrower* find_borrower(Library *lib, int borrower_id);
void print_library(Library *lib);

#endif
