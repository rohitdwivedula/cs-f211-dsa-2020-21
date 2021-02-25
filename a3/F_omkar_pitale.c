#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int *queue;
    int front;
    int rear;
    int size;
}Queue;

typedef struct Node{
    int vertex;
    struct Node *next;
}Node;

typedef struct Graph{
    int V, E;
    Node **adjList;
    int *isVisited;
}Graph;

Queue *createQueue(int size){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->queue = (int *)malloc(sizeof(int) * size);
    Q->size = size;
    Q->front = 0;
    Q->rear = 0;
    return Q;
}   

int isQueueEmpty(Queue *Q){
    return (Q->front == Q->rear)? 1: 0;
}

void enqueue(Queue *Q, int data){
    if(Q->rear == Q->size){
        return;
    }
    else{
        Q->queue[Q->rear] = data;
        Q->rear++;
    }
}

int dequeue(Queue *Q){
    if(Q->front == Q->rear){
        return -1;
    }
    else{
        int data = Q->queue[Q->front];
        Q->front++;
        if(Q->front == Q->rear){
            Q->front = 0;
            Q->rear = 0;
        }
        return data;
    }
}

Node *createNode(int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int V, int E){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->adjList = (Node **)malloc(sizeof(Node *) * V);
    G->isVisited = (int *)calloc(V, sizeof(int));
    G->V = V;
    G->E = E;

    for(int i = 0; i < V; ++i){
        G->adjList[i] = NULL;
    }
    return G;
}

void addEdge(Graph *G, int u, int v){
    Node *newNode = createNode(v);
    newNode->next = G->adjList[u];
    G->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = G->adjList[v];
    G->adjList[v] = newNode;
}

int visitedNodesCount(Graph *G){
    int visited = 0;
    for(int i = 0; i < G->V; ++i){
        visited += G->isVisited[i];
    }
    return visited;
}

int BFS(Graph *G, int source){
    Queue *Q = createQueue(G->V);
    G->isVisited[source] = 1;
    enqueue(Q, source);

    while(!isQueueEmpty(Q)){
        int v = dequeue(Q);

        for(Node *T = G->adjList[v]; T != NULL; T = T->next){
            if(G->isVisited[T->vertex] == 0){
                G->isVisited[T->vertex] = 1;
                if(visitedNodesCount(G) >= 0.8 * G->V)
                    return 0;
                enqueue(Q, T->vertex);
            }
        }
    }
    return 1;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    Graph *G = createGraph(N, M);
    for(int i = 0; i < M; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(G, u, v);
    }

    int minVaccines = 0;
    for(int i = 0; i < N; ++i){
        if(G->isVisited[i] == 0){
            if(BFS(G, i))
                minVaccines++;
        }
    }

    printf("%d", minVaccines);
}