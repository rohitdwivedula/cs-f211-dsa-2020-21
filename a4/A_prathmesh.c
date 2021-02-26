#include <stdio.h>
#include <stdlib.h>

/**
 * We first make a directed graph where an edge from a to b means b > a in the alien alphabets 
 * We perform DFS on each vertex and count the no of nodes we can reach
 * If we can reach all the nodes from a vertex then there exist a solution
 * We are asked to print any order so we just perform BFS on the vertex we found in the first step
 * * */

int adj[26][26];
int reg[26];
int count = 0;

/* IMPLEMENTING STACK */
int stack[1000];
int top = -1;
void push(int i) {
    stack[++top] = i;
}

int pop() {
    return stack[top--];
}
void clear() {
    top = -1;
}
int size() {
    return top + 1;
}
/* IMPLEMENTING STACK */

int dfs(int start) {
    clear();
    int visited[26] = {0};
    visited[start] = 1;
    int nodes_count = 1;
    push(start);
    while (size() != 0) {
        int current = pop();
        for (int i=0; i<26; i++) {
            if (adj[current][i] && !visited[i]) {
                push(i);
                visited[i] = 1;
                nodes_count++;
            } 
        }
    }
    return nodes_count;
}

/* IMPLEMENTING QUEUE */
int queue[1000];
int insert_pointer = -1, remove_pointer = -1;
void qpush(int i) {
    queue[++insert_pointer] = i;
}
int qpop() {
    return queue[++remove_pointer];
}

int qsize() {
    return insert_pointer - remove_pointer;
}
/* IMPLEMENTING QUEUE */

void bfs(int start) {
    int visited[26] = {0};
    visited[start] = 1;
    qpush(start);
    printf("%c", (char)(start + 65));
    while (qsize() > 0) {
        int current = qpop();
        for (int i=0; i<26; i++) {
            if (adj[current][i] && !visited[i]) {
                qpush(i);
                visited[i] = 1;
                printf("%c", (char)(65 + i));
            }
        }
    }
} 

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        char c1, c2;
        scanf(" %c", &c1);
        scanf(" %c", &c2);
        int first = (int)c1 - 65;
        int second = (int)c2 - 65;
        if (reg[first] == 0) {
            reg[first] = 1;
            count++;
        }
        if (reg[second] == 0) {
            reg[second] = 1;
            count++;
        }
        adj[first][second] = 1;
    }
    int vertex = -1;
    for (int i=0; i<26; i++) {
        if (reg[i] == 1) {
            int ans = dfs(i);
            if (ans == count) {
                vertex = i;
                continue;
            }
        }
    }
    if (vertex != -1) {
        bfs(vertex);
    } else {
        printf("ALIENS BE CRAZY");
    }
}