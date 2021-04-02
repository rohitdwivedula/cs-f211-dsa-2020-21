#include <stdio.h>
#include <stdlib.h>
#define N 1000

int heap[N];
int size = 0;

void swap(int* a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void minHeapify(int heap[], int i) {
	int parent = (i-1)/2;

	if(i >= 0 && heap[parent] > heap[i]) {
		swap(&heap[parent],&heap[i]);
		minHeapify(heap, parent);
	}
}

void insertNode(int x) {
	heap[size] = x;
	size++;
	minHeapify(heap, size-1);
}

struct Node {
	int vertex;
	struct Node * next;
};

struct Graph {
	int numVertices;
	struct Node** adjList;
};

typedef struct Node Node;
typedef struct Graph Graph;

Node* createNode(int v) {
	Node* node = (Node*) malloc(sizeof(Node));
	node -> vertex = v;
	node -> next = NULL;

	return node;
}

Graph* createGraph(int numVertices) {
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph -> numVertices = numVertices;
	graph -> adjList = malloc(numVertices * sizeof(Node));

	for(int i = 1; i <= numVertices; i++) {
		graph -> adjList[i] = NULL;
	}

	return graph;
}

void addEdge(Graph* graph, int u, int v) {

	Node* node = createNode(v);
	node -> next = graph -> adjList[u];
	graph -> adjList[u] = node;

	node = createNode(u);
	node -> next = graph -> adjList[v];
	graph -> adjList[v] = node;
}

void BFS(Graph* graph, int start) {
	int visited[N] = {0};
	
	insertNode(start);
	visited[start] = 1;

	while(size) {
		int v = heap[0];
		printf("%d ",v);
		swap(&heap[0],&heap[size-1]);
		size--;

		for(Node* u = graph -> adjList[v]; u != NULL; u = u -> next){
			if(! visited[u -> vertex]) {
				visited[u -> vertex] = 1;
				insertNode(u -> vertex);
			}
		}
	} 

}
int main() {
	int n, m;
	scanf("%d %d",&n,&m);

	Graph* graph = createGraph(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d",&u,&v);
		addEdge(graph, u, v);
	}

	BFS(graph, 1);

	return 0;
}
