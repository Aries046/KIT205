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
void addspot() {
    createspot();
    if (map.v >= MAX_PEAKS) {
        printf("The maximum number of scenic spots has been reached, unable to add more!\n");
        return;
    }
    char newName[200];
    char newFeatures[1000];
    printf("Please enter the name of the new scenic spot:\n");
    scanf("%s", newName);
    getchar();
    printf("Please enter the description for the scenic spot \"%s\" (up to 200 characters):\n", newName);
    scanf("%s", newFeatures);
    getchar();
    int m = 0;
    Listspot();
    printf("Please enter the number of adjacent scenic spots:\n");
    scanf("%d", &m);
    while (m < 0 || m > map.v) {
        printf("Invalid input, please re-enter!\n");
        scanf("%d", &m);
    }
    for (int i = 0; i < m; i++) {
        int a, d;
        printf("Please enter the code of the %d adjacent scenic spot:\n", i + 1);
        scanf("%d", &a);
        while (a < 1 || a > map.v) {
            printf("Invalid input, please re-enter! Range is 1 to %d.\n", map.v);
            scanf("%d", &a);
        }
        printf("Please enter the distance between \"%s\" and \"%s\":\n", newName, map.pk[a - 1].name);
        scanf("%d", &d);
        while (d <= 0 || d >= BIG) {
            printf("Invalid distance, please re-enter!\n");
            scanf("%d", &d);
        }
        Edge *newEdge = (Edge *)malloc(sizeof(Edge));
        newEdge->dest = a - 1;
        newEdge->weight = d;
        newEdge->next = map.pk[map.v].adjList;
        map.pk[map.v].adjList = newEdge;

        Edge *reverseEdge = (Edge *)malloc(sizeof(Edge));
        reverseEdge->dest = map.v;
        reverseEdge->weight = d;
        reverseEdge->next = map.pk[a - 1].adjList;
        map.pk[a - 1].adjList = reverseEdge;
    }
    strcpy(map.pk[map.v].name, newName);
    strcpy(map.pk[map.v].features, newFeatures);
    map.v++;
    map.e += m;
    printf("Scenic spot added successfully!\n");
}

void changes() {
    createspot();
    Listspot();
    int name;
    char outputname[200], inputfeatures[200];
    printf("Please enter the code of the scenic spot you want to modify (enter 0 to return to the main menu):\n");
    scanf("%d", &name);
    if (name == 0) return;
    while (name < 1 || name > map.v) {
        printf("Invalid scenic spot code, please re-enter:\n");
        scanf("%d", &name);
    }
    printf("The current name of this scenic spot is:\n%s\n", map.pk[name - 1].name);
    printf("Please enter the new name:\n");
    scanf("%s", outputname);
    strcpy(map.pk[name - 1].name, outputname);
    printf("Name updated successfully\n");
    printf("The current information of this scenic spot is:\n%s\n", map.pk[name - 1].features);
    printf("Please enter the new description of the scenic spot:\n");
    scanf("%s", inputfeatures);
    strcpy(map.pk[name - 1].features, inputfeatures);
    printf("Scenic spot description updated successfully. Enter 1 to continue modifying, or enter 2 to return to the main menu\n");
    int p;
    scanf("%d", &p);
    if (p == 2) return;
    if (p == 1) changes();
}

void deletespot() {
    createspot();
    if (map.v < 1) {
        printf("There are no scenic spots on the map, unable to delete!\n");
        return;
    }
    Listspot();
    printf("Please enter the code of the scenic spot you want to delete (must be a number):\n");
    int a;
    scanf("%d", &a);
    while (a < 1 || a > map.v) {
        printf("Invalid input, please re-enter! Range is 1 to %d.\n", map.v);
        scanf("%d", &a);
    }
    printf("You are about to delete the scenic spot: \"%s\"\nPress 1 to confirm deletion, press any other key to cancel\n", map.pk[a - 1].name);
    int flag;
    scanf("%d", &flag);
    if (flag == 1) {
        Edge *curr = map.pk[a - 1].adjList;
        while (curr != NULL) {
            Edge *temp = curr;
            curr = curr->next;
            free(temp);
        }
        for (int i = a - 1; i < map.v - 1; i++) {
            map.pk[i] = map.pk[i + 1];
        }
        for (int i = 0; i < map.v; i++) {
            Edge *prev = NULL;
            Edge *curr = map.pk[i].adjList;
            while (curr != NULL) {
                if (curr->dest == a - 1) {
                    if (prev == NULL) {
                        map.pk[i].adjList = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        map.v--;
        map.e -= 1; // Adjust the edge count appropriately
        printf("Scenic spot deleted successfully!\n");
    }
}
void addpath() {
    createspot();
    Listspot();
    if (map.v <= 0 || map.v == 1) {
        printf("Due to no scenic spots or too few scenic spots, roads cannot be added to this map!\n");
        return;
    }
    printf("Please enter the codes of the two scenic spots you want to connect (enter numbers between 1 and %d):\n", map.v);
    int a, b;
    scanf("%d %d", &a, &b);
    while (a < 1 || a > map.v || b < 1 || b > map.v) {
        if (a == b)
            printf("The codes of the scenic spots you entered are the same, please re-enter!\n");
        else
            printf("Invalid input, please enter numbers between 1 and %d separated by a space, and re-enter!\n", map.v);
        scanf("%d %d", &a, &b);
    }
    int d;
    printf("Please enter the length of the road between \"%s\" and \"%s\":\n", map.pk[a - 1].name, map.pk[b - 1].name);
    scanf("%d", &d);
    while (d < 0 || d >= BIG) {
        printf("Invalid length, please re-enter!\n");
        scanf("%d", &d);
    }
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->dest = b - 1;
    newEdge->weight = d;
    newEdge->next = map.pk[a - 1].adjList;
    map.pk[a - 1].adjList = newEdge;

    Edge *reverseEdge = (Edge *)malloc(sizeof(Edge));
    reverseEdge->dest = a - 1;
    reverseEdge->weight = d;
    reverseEdge->next = map.pk[b - 1].adjList;
    map.pk[b - 1].adjList = reverseEdge;

    map.e++;
    printf("Congratulations, the road has been successfully added!\n");
}

void deletepath() {
    createspot();
    Listspot();
    if (map.v <= 0) {
        printf("There are no scenic spots on the map, unable to delete roads!\n");
        return;
    }
    if (map.e <= 0) {
        printf("There are no roads on the map, unable to delete!\n");
        return;
    }
    printf("Please enter the codes of the two scenic spots corresponding to the road you want to delete, separated by a space:\n");
    int a, b;
    scanf("%d %d", &a, &b);
    while (a < 1 || a > map.v || b < 1 || b > map.v || a == b) {
        if (a == b)
            printf("The codes of the scenic spots you entered are the same, please re-enter!\n");
        else
            printf("Invalid input, please re-enter! Range is 1 to %d.\n", map.v);
        scanf("%d %d", &a, &b);
    }
    Edge *prev = NULL;
    Edge *curr = map.pk[a - 1].adjList;
    while (curr != NULL && curr->dest != b - 1) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("There is no road between \"%s\" and \"%s\", unable to delete!\n", map.pk[a - 1].name, map.pk[b - 1].name);
    } else {
        if (prev == NULL) {
            map.pk[a - 1].adjList = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);

        prev = NULL;
        curr = map.pk[b - 1].adjList;
        while (curr != NULL && curr->dest != a - 1) {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) {
            map.pk[b - 1].adjList = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);

        map.e--;
        printf("Road deleted successfully!\n");
    }
}

