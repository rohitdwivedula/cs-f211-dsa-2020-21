#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int visited[1000] = {0};

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjList;
};


typedef struct Node Node;
typedef struct Graph Graph;

Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;

    return node;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->numVertices = vertices;
    graph->adjList = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int s, int d) {
    Node* node = createNode(d);
    node->next = graph->adjList[s];
    graph->adjList[s] = node;
}

int DFS(Graph* graph, int start, int visited[1000], int *count) {
    visited[start] = 1;
    (*count)++;

    for (Node* u = graph->adjList[start]; u != NULL; u = u->next) {
        if (!visited[u->vertex]) {
            DFS(graph, u->vertex, visited, count);
        }
    }
}

int main() {
    uint32_t n, m, u, v, maxVisited = 0;
    scanf("%d%*c%d", &n, &m);

    Graph* grandLine = createGraph(n);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        addEdge(grandLine, u - 1, v - 1);
    }

    for (uint32_t i = 0; i < n; i++) 
    {
        uint32_t visited[1000] = {0}, count = 0;
        DFS(grandLine, i, visited, &count);

        if (count > maxVisited) {
            maxVisited = count;
        }
    }

    printf("%d", maxVisited);
    

    return 0;
}
