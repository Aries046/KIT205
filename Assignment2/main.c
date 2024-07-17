#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions
#define BIG 100000
#define MAX_PEAKS 50
#define TESTFILE "spots.txt"

typedef struct Edge {
    int dest;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    int num;
    char name[100];
    char features[500];
    Edge *adjList;
} Peak;

typedef struct {
    Peak pk[MAX_PEAKS];
    int v; // Number of vertices
    int e; // Number of edges
} Graph;

static Graph map;
char PASSCODE[20] = "bao";
int main() {
    int n;
    printf("\n\n\n");
    printf("\t\t\t\tWelcome to the Tasmania Tourism Guide! All scenic spot information is fictional\n");
    printf("\t\t\t\tDear kind and beautiful gentlemen and ladies, please select your identity\n");
    printf("\t\t\t\t<1> To enter the admin interface, please enter the number 1\n");
    printf("\t\t\t\t<2> To enter the tourist interface, please enter the number 2\n");
    start:
    scanf("%d", &n);
    if (n == 1) {
        char pc[20];
        printf("\t\t\t\tPlease enter the admin password: ");
        scanf("%s", pc);
        getchar();
        while (strcmp(pc, PASSCODE) != 0) {
            printf("Incorrect password, please re-enter the password:\n");
            scanf("%s", pc);
        }
        if (strcmp(pc, PASSCODE) == 0) {
            printf("Identity verified, entering the system...");
            menu1();
        }
    } else if (n == 2) {
        menu2();
    } else {
        printf("Input error, please re-enter 1 or 2\n");
        goto start;
    }
    return 0;
}

void menu1() {
    // Placeholder for admin menu
}

void menu2() {
    // Placeholder for tourist menu
}
