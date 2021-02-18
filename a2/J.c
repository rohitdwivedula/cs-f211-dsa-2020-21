#include <stdio.h>
#include <stdlib.h>
#define N 2000

typedef struct Nodetype
{
    int data;
    struct Nodetype* next;
} Node;

Node* adj_list[N];
int dist[N];

void add(int idx, int pos)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node -> next = NULL;
    node -> data = idx;
    if(adj_list[pos])
        node -> next = adj_list[pos];
    adj_list[pos] = node;
}

void BFS(int src, int n)
{
    int queue[N], vis[n+1];
    int front = 0, back = 0;

    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }

    dist[0] = 0;
    queue[back++] = src;
    while(front != back)
    {
        int curr = queue[front++];
        vis[curr] = 1;
        Node* head = adj_list[curr];
        while(head)
        {
            int it = head -> data;
            if(!vis[it])
            {
                if(dist[it] > dist[curr] + 1)
                    dist[it] = dist[curr] + 1;
                queue[back++] = it;
            }
            head = head -> next;
        }
    }
    return;
}


int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    BFS(s, n);
    printf("%d", dist[t]*100);
    return 0;
}