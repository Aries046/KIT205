#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(Graph *G, int V) {
    G->V = V;
    G->edges = (EdgeList *)malloc(V * sizeof(EdgeList));
    for (int i = 0; i < V; i++) {
        G->edges[i].head = NULL;
    }
}

void add_edge(Graph *G, int from, int to, int w) {
    EdgeNodePtr newNode = (EdgeNodePtr)malloc(sizeof(struct edgeNode));
    newNode->edge.to_vertex = to;
    newNode->edge.weight = w;
    newNode->next = G->edges[from].head;
    G->edges[from].head = newNode;
}

void calculate_in_degrees(const Graph *G, int *in_degrees) {
    for (int i = 0; i < G->V; i++) {
        for (EdgeNodePtr p = G->edges[i].head; p != NULL; p = p->next) {
            in_degrees[p->edge.to_vertex]++;
        }
    }
}

void free_graph(Graph *G) {
    for (int i = 0; i < G->V; i++) {
        EdgeNodePtr current = G->edges[i].head;
        while (current != NULL) {
            EdgeNodePtr to_free = current;
            current = current->next;
            free(to_free);
        }
    }
    free(G->edges);
}

int main() {
    Graph G;
    FILE* file = fopen("real_world_graph.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int V;
    fscanf(file, "%d", &V);
    init_graph(&G, V);

    int from, to;
    while (fscanf(file, "%d,%d", &from, &to) == 2) {
        add_edge(&G, from - 1, to - 1, 0); // Assuming no weights and 1-based index
    }
    fclose(file);

    int *in_degrees = (int *)calloc(G.V, sizeof(int));
    calculate_in_degrees(&G, in_degrees);
    for (int i = 0; i < G.V; i++) {
        printf("Vertex %d has in-degree %d\n", i, in_degrees[i]);
    }
    free(in_degrees);

    free_graph(&G);

    return 0;
}
