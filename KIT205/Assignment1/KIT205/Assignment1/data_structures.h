#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    int book_id;
    char title[256];
    char author[100];
    struct book *next;
} Book;

typedef struct borrower {
    int borrower_id;
    char name[100];
    struct borrower *next;
} Borrower;

typedef struct library {
    Book *books;
    Borrower *borrowers;
} Library;

#endif
