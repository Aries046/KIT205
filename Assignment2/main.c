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
    while (1) {
        int m;
        printf("\t\tAdmin Operations Interface\n");
        printf("\tHello, welcome! How can I help you?\n");
        printf("\t<1> View scenic spot introduction\n");
        printf("\t<2> Modify scenic spot information\n");
        printf("\t<3> Add scenic spot information\n");
        printf("\t<4> Delete scenic spot information\n");
        printf("\t<5> Add scenic spot path\n");
        printf("\t<6> Delete scenic spot path\n");
        printf("\t<7> Shortest path to a scenic spot\n");
        printf("\t<8> Shortest path between two scenic spots\n");
        printf("\t<9> Change login password\n");
        printf("\t<10> Exit admin system\n");
        scanf("%d", &m);
        switch (m) {
            // Placeholder for menu options
            default: printf("Invalid input, please enter a number between 1 and 10!\n"); break;
        }
    }
}

void menu2() {
    while (1) {
        int a;
        printf("\t\tTourist Operations Interface\n");
        printf("\tHello, welcome! How can I help you?\n");
        printf("\t<1> View scenic spot introduction\n");
        printf("\t<2> Shortest path to a scenic spot\n");
        printf("\t<3> Shortest path between two scenic spots\n");
        printf("\t<4> Exit system\n");
        scanf("%d", &a);
        switch (a) {
            // Placeholder for menu options
            default: printf("Invalid input\n"); break;
        }
    }
}
void introduce() {
    createspot();
    if (map.v == 0) {
        printf("There are currently no scenic spots on this map!\n");
        return;
    }
    Listspot();
    printf("\nPlease enter the code of the scenic spot you want to view: \n");
    int n;
    while (1) {
        scanf("%d", &n);
        if (n < 1 || n > map.v) {
            printf("Invalid input, please re-enter! \n");
        } else {
            break;
        }
    }
    printf("%s: %s\n", map.pk[n - 1].name, map.pk[n - 1].features);
    printf("\nTo query again, press 1, to exit the query, press any other key\n");
    char flag;
    scanf(" %c", &flag);
    if (flag == '1') {
        introduce();
    }
}



void menu2() {
    // Placeholder for tourist menu
}
