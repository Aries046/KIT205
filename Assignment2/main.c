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

void menu1();
void menu2();
void introduce();
void changes();
void addspot();
void deletespot();
void addpath();
void deletepath();
void Dijkstra();
void Floyed();
void changecode();
void Listspot();
void createspot();
void Exit();
void addEdge(int src, int dest, int weight);

char PASSCODE[20] = "bao";
int main() {
    int n;
    printf("\n\n\n");
    printf("\t\t\t\tWelcome to the University of Tasmania! This is UTASGuide. All scenic spot information is fictional\n");
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
            case 1: introduce(); break;
            case 2: changes(); break;
            case 3: addspot(); break;
            case 4: deletespot(); break;
            case 5: addpath(); break;
            case 6: deletepath(); break;
            case 7: Dijkstra(); break;
            case 8: Floyed(); break;
            case 9: changecode(); break;
            case 10: Exit(); break;
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
            case 1: introduce(); break;
            case 2: Dijkstra(); break;
            case 3: Floyed(); break;
            case 4: exit(0); break;
            default: printf("Invalid input\n"); break;
        }
    }
}


void introduce() {

}


void changes() {

}

void addspot() {

}

void deletespot() {

}

void addpath() {

}

void deletepath() {

}

void Exit() {
    printf("\n[Note]:\nAfter exiting the system, all previous operations will be reset to the initial default values.\n");
    printf("To confirm exit, press 1. Press any other key to cancel the exit operation.\n");
    int judge;
    scanf("%d", &judge);
    if (judge == 1) {
        exit(0);
    }
}

void Dijkstra() {
    
}

void Floyed() {
    
}

void changecode() {
    char newcode[20];
    printf("Please enter the new password you want to set: \n");
    scanf("%s", newcode);
    strcpy(PASSCODE, newcode);
    printf("Password changed successfully! Please remember your new password!\n");
    printf("*Note* The new password will revert to the initial default password the next time you enter the program.");
}

void Listspot() {
    if (map.v == 0) {
        printf("There are currently no scenic spots on the map!\n\n");
        return;
    }
    printf("The University of Tasmania has the following scenic spots (Note: all data is fictional.):\n\n");
    for (int i = 0; i < map.v; i++) {
        printf("\t<%d>%s\n", i + 1, map.pk[i].name);
    }
}

void createspot() {

    FILE *file = fopen(TESTFILE, "r");

    fclose(file);
}

void addEdge(int src, int dest, int weight) {
}

